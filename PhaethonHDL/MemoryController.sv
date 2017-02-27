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
  debug             // [Output] Debug port
  );

  `define Ready 0
  `define PRamWait1 1
  `define PRamWait2 2
  `define PRamWait3 3

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
  output reg [31:0] debug;

  reg [7:0] state = `Ready;
  reg [0:0] isRead;

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
          isRead <= (mcReadReq == 1);

          if (mcReadReq == 1 || mcWriteReq == 1)
          begin
            if (mcAddrVirtual == 0)
            begin
              //$display("mcReadReq is %h, addr is %h", mcReadReq, mcRamAddress);

              // Divert to the physical RAM
              phRamAddress <= mcRamAddress;
              phReadReq <= mcReadReq;
              phWriteReq <= mcWriteReq;
              phRamOut <= mcRamIn;
              state <= `PRamWait1;
            end
            else
            begin
              // Need to translate

              // TODO: Translation of address
            end
          end
        end

        `PRamWait1: begin
          // Need to wait for another clock for this to complete
          mcRamReady <= 0;
          state <= `PRamWait2;
        end

        `PRamWait2: begin
          if (isRead == 1)
          begin
            //$display("Setting ram out to %h in mc", phRamIn);

            // Deliver to the caller now
            mcRamOut <= phRamIn;
          end

          mcRamReady <= 1;
          state <= `Ready;
        end
      endcase
    end
  end
endmodule
