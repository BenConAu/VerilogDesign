module MemoryController(
  clk,              // Global clock
  reset,            // Reset
  mcRamOut,         // [Output] RAM at requested address
  mcRamReady,       // [Output] RAM is ready to be picked up
  mcRamAddress,     // [Input] RAM address requested
  mcRamIn,          // [Input] RAM to write
  mcReadReq,        // [Input] RAM read request
  mcWriteReq,       // [Input] RAM write request
  mcAddrVirtual,    // [Input] Virtual flag for RAM
  phRamIn,          // [Input]  RAM at requested address
  phRamAddress,     // [Output] RAM address requested
  phRamOut,         // [Output] RAM to write
  phReadReq,        // [Output] RAM read request
  phWriteReq,       // [Output] RAM write request
  ptAddress,        // [Input] Page table address
  debug             // [Output] Debug port
  );

  `define Ready 0
  `define PRamWait1 1
  `define PRamWait2 2
  `define VPTWait1 3
  `define VPTWait2 4
  `define VPTWait3 5
  `define VPTWait4 6

  input wire clk;
  input wire reset;
  output reg [31:0] mcRamOut;
  output reg mcRamReady = 0;
  input wire [31:0] mcRamAddress;
  input wire [31:0] mcRamIn;
  input wire mcReadReq;
  input wire mcWriteReq;
  input wire mcAddrVirtual;
  input wire [31:0] phRamIn;
  output reg [31:0] phRamAddress;
  output reg [31:0] phRamOut;
  output reg phReadReq;
  output reg phWriteReq;
  input wire [31:0] ptAddress;
  output reg [31:0] debug;

  reg [7:0] state = `Ready;
  reg [0:0] isRead;

  // Stuff saved when TLB misses
  reg savedReadReq;
  reg savedWriteReq;
  reg [31:0] savedVirtAddr;
  reg [31:0] savedPTReadAddr;
  reg [31:0] savedFirstWord;

  // The TLB
  reg [63:0] tlb[0:15];

  function [21:0] GetTLBVirtPage;
    input [63:0] tlbEntry;

    begin
      GetTLBVirtPage = tlbEntry[53:32];
    end
  endfunction

  function [21:0] GetTLBPhysPage;
    input [63:0] tlbEntry;

    begin
      GetTLBPhysPage = tlbEntry[21:0];
    end
  endfunction

  function [3:0] GetPageHash;
    input [31:0] virtAddr;

    begin
      GetPageHash = virtAddr[13:10];
    end
  endfunction

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      mcRamReady <= 0;
      state <= `Ready;
      isRead <= 0;
    end
    else
    begin
      case (state)
        `Ready: begin
          mcRamReady <= 0;

          if (mcReadReq == 1 || mcWriteReq == 1)
          begin
            if (mcAddrVirtual == 0)
            begin
              //$display("Physical access, mcReadReq is %h, addr is %h, ramIn is %h", mcReadReq, mcRamAddress, mcRamIn);

              // Divert to the physical RAM
              phRamAddress <= mcRamAddress;
              phReadReq <= mcReadReq;
              phWriteReq <= mcWriteReq;
              phRamOut <= mcRamIn;
              isRead <= (mcReadReq == 1);
              state <= `PRamWait1;
            end
            else
            begin
              // Need to translate - use the lower bits of the virtual page
              if (GetTLBVirtPage(tlb[GetPageHash(mcRamAddress)]) == mcRamAddress[31:10])
              begin
                //$display("Page to translate %h found in TLB", mcRamAddress);

                // Translate page using TLB
                phRamAddress[31:10] <= GetTLBPhysPage(tlb[GetPageHash(mcRamAddress)]);

                // Use lower bits from virtual address in physical address
                phRamAddress[9:0] <= mcRamAddress[9:0];

                // Otherwise same as physical lookup
                phReadReq <= mcReadReq;
                phWriteReq <= mcWriteReq;
                phRamOut <= mcRamIn;
                isRead <= (mcReadReq == 1);
                state <= `PRamWait1;
              end
              else
              begin
                //$display("Page for address %h not found in TLB, page = %h, pt + page = %h", mcRamAddress, mcRamAddress[17:10], ptAddress + mcRamAddress[17:10] * 8);

                // TLB miss - need to lookup in page table. The page table
                // currently is a single level, and only supports up to 256
                // pages to keep it easy (8 bit index).
                phRamAddress <= ptAddress + mcRamAddress[17:10] * 8;
                phReadReq <= 1;

                // Save the address we are looking up or storing at
                savedVirtAddr <= mcRamAddress;

                // Save the address of the first word of the PT entry
                savedPTReadAddr <= ptAddress + mcRamAddress[17:10] * 8;

                // Save our request parameters
                savedReadReq <= mcReadReq;
                savedWriteReq <= mcWriteReq;

                // Wait for the first word to read out
                state <= `VPTWait1;
              end

              mcRamReady <= 0;
            end
          end
        end

        `PRamWait1: begin
          // Need to wait for another clock for this to complete
          //$display("PR wait 1 for %h", phRamAddress);

          mcRamReady <= 0;
          state <= `PRamWait2;
        end

        `PRamWait2: begin
          if (isRead == 1)
          begin
            //$display("Finish physical read value of %h in mc", phRamIn);

            // Deliver to the caller now
            mcRamOut <= phRamIn;
          end
          else
          begin
            //$display("Finish PRWait2 with isRead not set");
          end

          mcRamReady <= 1;
          state <= `Ready;
        end

        `VPTWait1: begin
          //$display("Waiting for read of page table");

          // Wait for read to complete
          mcRamReady <= 0;
          state <= `VPTWait2;
        end

        `VPTWait2: begin
          //$display("Waited for read %h from %h of page table 1", phRamIn, savedPTReadAddr);
          
          // Store first half of entry
          savedFirstWord <= phRamIn;

          // Now get second half
          phRamAddress <= savedPTReadAddr + 4;
          mcRamReady <= 0;
          state <= `VPTWait3;
        end

        `VPTWait3: begin
          //$display("Waiting again for read of page table");

          // Wait for read to complete
          mcRamReady <= 0;
          state <= `VPTWait4;
        end

        `VPTWait4: begin
          //$display("Waited for read %h of page table 2, va Addr = %h", phRamIn, savedVirtAddr);
          
          // Now we have second half of entry, store it in the TLB
          tlb[GetPageHash(savedVirtAddr)] <= {savedFirstWord, phRamIn};

          // Now we can do the actual request we came here for
          phRamAddress[31:10] <= GetTLBPhysPage({savedFirstWord, phRamIn});
          phRamAddress[9:0] <= savedVirtAddr[9:0];

          // Rehydrate the saved parameters
          phReadReq <= savedReadReq;
          phWriteReq <= savedWriteReq;
          phRamOut <= mcRamIn;
          isRead <= (savedReadReq == 1);

          // Wait for read to complete
          state <= `PRamWait1;
          mcRamReady <= 0;                    
        end
      endcase
    end
  end
endmodule
