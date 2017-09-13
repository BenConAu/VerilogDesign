module MMU_TestBench(
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  reg[7:0] fileRam[65535:0];
  wire[31:0] RamOutput;
  wire[1:0] mcStatus;
  reg[31:0] mcRamAddress;
  reg[31:0] mcRamIn;
  reg[0:0] mcReadReq;
  reg[0:0] mcWriteReq;
  reg[0:0] mcAddrVirtual;
  reg[0:0] mcExecMode;
  reg[31:0] phRamRead;
  wire[31:0] phRamWrite;
  wire[31:0] phRamAddress;
  wire[0:0] phReadReq;
  wire[0:0] phWriteReq;
  wire[31:0] debug;
  wire[31:0] ptAddress;
  MemoryController MMU1(clk, RamOutput, mcStatus, mcRamAddress, mcRamIn, mcReadReq, mcWriteReq, mcAddrVirtual, mcExecMode, phRamRead, phRamAddress, phRamWrite, phReadReq, phWriteReq, ptAddress, debug);
  initial
  begin
    # 0 mcRamAddress = 32'd0;
    # 0 mcWriteReq = 1'b1;
    # 0 mcReadReq = 1'b0;
    # 0 mcRamIn = 32'd291;
    # 100 mcWriteReq = 1'b0;
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("RAM = %h:%h:%h:%h:%h:%h:%h:%h | Status = %h | MMU value read = %h", fileRam[32'd0], fileRam[32'd1], fileRam[32'd2], fileRam[32'd3], fileRam[32'd4], fileRam[32'd5], fileRam[32'd6], fileRam[32'd7], mcStatus, RamOutput);
        mcExecMode <= 1'b0;
        mcAddrVirtual <= 1'b0;
        if (phReadReq == 32'd1)
        begin
          phRamRead[7:0] <= fileRam[phRamAddress];
          phRamRead[15:8] <= fileRam[phRamAddress + 32'd1];
          phRamRead[23:16] <= fileRam[phRamAddress + 32'd2];
          phRamRead[31:24] <= fileRam[phRamAddress + 32'd3];
        end
        if (phWriteReq == 32'd1)
        begin
          fileRam[phRamAddress] <= phRamWrite[7:0];
          fileRam[phRamAddress + 32'd1] <= phRamWrite[15:8];
          fileRam[phRamAddress + 32'd2] <= phRamWrite[23:16];
          fileRam[phRamAddress + 32'd3] <= phRamWrite[31:24];
        end
      end
    endcase
  end
endmodule
