module MemoryController(
  clk,              // Global clock
  reset,            // Reset
  mcRamOut,         // [Output] RAM at requested address
  mcStatus,         // [Output] Status of controller (0 means not ready, 1 means ready, 2 means error)
  mcRamAddress,     // [Input] RAM address requested
  mcRamIn,          // [Input] RAM to write
  mcReadReq,        // [Input] RAM read request
  mcWriteReq,       // [Input] RAM write request
  mcAddrVirtual,    // [Input] Virtual flag for RAM
  mcExecMode,       // [Input] Execution mode for RAM
  phRamIn,          // [Input]  RAM at requested address
  phRamAddress,     // [Output] RAM address requested
  phRamOut,         // [Output] RAM to write
  phReadReq,        // [Output] RAM read request
  phWriteReq,       // [Output] RAM write request
  kptAddress,       // [Input] Page table address
  uptAddress,       // [Input] Page table address
  debug             // [Output] Debug port
  );

  `include "Common.sv"

  `define Ready 0
  `define PRamWait1 1
  `define PRamWait2 2
  `define VPTWait1 3
  `define VPTWait2 4
  `define VPTWait3 5
  `define VPTWait4 6
  `define Error 7

  input wire clk;
  input wire reset;
  output reg [31:0] mcRamOut;
  output reg [0:1] mcStatus = 0;
  input wire [31:0] mcRamAddress;
  input wire [31:0] mcRamIn;
  input wire mcReadReq;
  input wire mcWriteReq;
  input wire mcAddrVirtual;
  input wire mcExecMode;
  input wire [31:0] phRamIn;
  output reg [31:0] phRamAddress;
  output reg [31:0] phRamOut;
  output reg phReadReq;
  output reg phWriteReq;
  input wire [31:0] kptAddress;
  input wire [31:0] uptAddress;
  output reg [31:0] debug;

  reg [7:0] state = `Ready;
  reg [0:0] isRead;

  // Stuff saved when TLB misses
  reg savedReadReq;
  reg savedWriteReq;
  reg [31:0] savedVirtAddr;
  reg [31:0] savedPTReadAddr;
  reg [31:0] savedFirstWord;
  reg [31:0] savedWriteData;

  function [19:0] GetPageNumber;
    input [31:0] rawAddress;

    begin
      // It is the upper 20 bits
      GetPageNumber = rawAddress[31:12];
    end
  endfunction

  function [31:0] CalcPTEntryAddress;
    input [31:0] rawAddress;

    begin
      if (mcExecMode == 0)
      begin
        CalcPTEntryAddress = kptAddress + rawAddress[17:12] * 8;
      end
      else
      begin
        CalcPTEntryAddress = uptAddress + rawAddress[17:12] * 8;
      end
    end
  endfunction

  // The TLB
  reg [63:0] ktlb[0:15];
  reg [63:0] utlb[0:15];

  function [63:0] GetTLBEntry;
    input [3:0] pageNumber;

    begin
      if (mcExecMode == 0)
      begin
        GetTLBEntry = ktlb[pageNumber];
      end
      else
      begin
        GetTLBEntry = utlb[pageNumber];
      end
    end
  endfunction
    
  task SetTLBEntry;
    input [3:0] pageNumber;
    input [63:0] newEntry;

    begin
      if (mcExecMode == 0)
      begin
        ktlb[pageNumber] <= newEntry;
      end
      else
      begin
        utlb[pageNumber] <= newEntry;
      end
    end
  endtask


  function [19:0] GetTLBVirtPage;
    input [63:0] tlbEntry;

    begin
      GetTLBVirtPage = tlbEntry[51:32];
    end
  endfunction

  function [19:0] GetTLBPhysPage;
    input [63:0] tlbEntry;

    begin
      GetTLBPhysPage = tlbEntry[19:0];
    end
  endfunction

  function GetTLBValid;
    input [63:0] tlbEntry;

    begin
      GetTLBValid = tlbEntry[63:63];
    end
  endfunction

  function GetTLBProtected;
    input [63:0] tlbEntry;

    begin
      GetTLBProtected = tlbEntry[62:62];
    end
  endfunction

  function [3:0] GetPageHash;
    input [31:0] virtAddr;

    begin
      GetPageHash = virtAddr[13:10];
    end
  endfunction

  task RequestPhysicalPage;
    input [63:0] reqTLBEntry;
    input [31:0] reqVirtAddress;
    input reqReadReq;
    input reqWriteReq;
    input [31:0] reqWriteData;

    begin
      if (!GetTLBValid(reqTLBEntry))
      begin
        //$display("Address maps to invalid TLB entry %h", reqTLBEntry);

        state <= `Error;
        mcStatus <= `MCError;
      end
      else if (GetTLBProtected(reqTLBEntry) == 1 && mcExecMode == 1)
      begin
        //$display("Attempting access to protected page from user mode, execMode = %h", mcExecMode);

        state <= `Error;
        mcStatus <= `MCError;
      end
      else
      begin
        //$display("Building request from physical page %h and in-page address %h", GetTLBPhysPage(reqTLBEntry), reqVirtAddress[11:0]);

        // Translate page using TLB for upper bits
        phRamAddress[31:12] <= GetTLBPhysPage(reqTLBEntry);

        // Use lower bits from virtual address in physical address
        phRamAddress[11:0] <= reqVirtAddress[11:0];

        // Otherwise same as physical lookup
        phReadReq <= reqReadReq;
        phWriteReq <= reqWriteReq;
        phRamOut <= reqWriteData;
        isRead <= (reqReadReq == 1);
        state <= `PRamWait1;
        mcStatus <= `MCWaiting;
      end
    end
  endtask

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      mcStatus <= `MCWaiting;
      state <= `Ready;
      isRead <= 0;
    end
    else
    begin
      case (state)
        `Ready: begin
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
              mcStatus <= `MCWaiting;
            end
            else
            begin
              // Need to translate - use the lower bits of the virtual page
              if (GetTLBVirtPage(GetTLBEntry(GetPageHash(mcRamAddress))) == GetPageNumber(mcRamAddress))
              begin
                //$display(
                  //"Page to translate %h found in TLB entry %h, index %h", 
                  //mcRamAddress, 
                  //GetTLBEntry(GetPageHash(mcRamAddress)), 
                  //GetPageHash(mcRamAddress));

                RequestPhysicalPage(
                  GetTLBEntry(GetPageHash(mcRamAddress)), 
                  mcRamAddress, 
                  mcReadReq, 
                  mcWriteReq, 
                  mcRamIn);
              end
              else
              begin
                //$display("Page for address %h not found in TLB, page = %h, pt + page = %h", mcRamAddress, mcRamAddress[17:10], CalcPTEntryAddress(mcRamAddress));

                // TLB miss - need to lookup in page table. The page table
                // currently is a single level, and only supports up to 256
                // pages to keep it easy (8 bit index).
                phRamAddress <= CalcPTEntryAddress(mcRamAddress);
                phReadReq <= 1;

                // Save the address we are looking up or storing at
                savedVirtAddr <= mcRamAddress;

                // Save the address of the first word of the PT entry
                savedPTReadAddr <= CalcPTEntryAddress(mcRamAddress);

                // Save our request parameters
                savedReadReq <= mcReadReq;
                savedWriteReq <= mcWriteReq;
                savedWriteData <= mcRamIn;

                // Wait for the first word to read out
                state <= `VPTWait1;
                mcStatus <= `MCWaiting;
              end

            end
          end
          else
          begin
            mcStatus <= `MCWaiting;
          end
        end

        `PRamWait1: begin
          // Need to wait for another clock for this to complete
          //$display("PR wait 1 for %h", phRamAddress);

          mcStatus <= `MCWaiting;
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

          mcStatus <= `MCReady;
          state <= `Ready;
        end

        `VPTWait1: begin
          //$display("Waiting for read of page table");

          // Wait for read to complete
          mcStatus <= `MCWaiting;
          state <= `VPTWait2;
        end

        `VPTWait2: begin
          //$display("Waited for read %h from %h of page table 1", phRamIn, savedPTReadAddr);
          
          // Store first half of entry
          savedFirstWord <= phRamIn;

          // Now get second half
          phRamAddress <= savedPTReadAddr + 4;
          mcStatus <= `MCWaiting;
          state <= `VPTWait3;
        end

        `VPTWait3: begin
          //$display("Waiting again for read of page table");

          // Wait for read to complete
          mcStatus <= `MCWaiting;
          state <= `VPTWait4;
        end

        `VPTWait4: begin
          //$display("Waited for read %h of page table 2, va Addr = %h", phRamIn, savedVirtAddr);
          //$display("Inserting TLB entry %h", {1'b1, savedFirstWord[30:0], phRamIn});

          // Now we have second half of entry, store it in the TLB
          SetTLBEntry(GetPageHash(savedVirtAddr), {1'b1, savedFirstWord[30:0], phRamIn});

          RequestPhysicalPage(
            {1'b1, savedFirstWord[30:0], phRamIn}, 
            mcRamAddress, 
            savedReadReq, 
            savedWriteReq, 
            savedWriteData);
        end

        `Error: begin
          // Wait a clock for the error to register
          mcStatus <= `MCWaiting;
          state <= `Ready;
        end

      endcase
    end
  end
endmodule
