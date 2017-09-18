module PhysicalRAM(
  clk,
  address,
  WriteEnable,
  WriteValue,
  ReadValue
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[31:0] address;
  input wire[0:0] WriteEnable;
  input wire[31:0] WriteValue;
  output reg[31:0] ReadValue;
  reg[7:0] fileRam[65535:0];
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%d | RAM = %h:%h:%h:%h:%h:%h:%h:%h | WriteEnable = %h | RAM value read = %h", $time, fileRam[32'd0], fileRam[32'd1], fileRam[32'd2], fileRam[32'd3], fileRam[32'd4], fileRam[32'd5], fileRam[32'd6], fileRam[32'd7], WriteEnable, ReadValue);
        if (WriteEnable)
        begin
          fileRam[address] <= WriteValue[7:0];
          fileRam[address + 32'd1] <= WriteValue[15:8];
          fileRam[address + 32'd2] <= WriteValue[23:16];
          fileRam[address + 32'd3] <= WriteValue[31:24];
        end
        else
        begin
          ReadValue[7:0] <= fileRam[address];
          ReadValue[15:8] <= fileRam[address + 32'd1];
          ReadValue[23:16] <= fileRam[address + 32'd2];
          ReadValue[31:24] <= fileRam[address + 32'd3];
        end
      end
    endcase
  end
endmodule
module MMU_TestBench(
  );
  // State definitions
  `define __initial 0
  `define __WaitWrite1 1
  `define __WaitRead1 2
  `define __End 3
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  wire[31:0] RamOutput;
  wire[1:0] mcStatus;
  reg[31:0] mcRamAddress;
  reg[31:0] mcRamIn;
  reg[0:0] mcRequest;
  reg[0:0] mcWriteEnable;
  reg[0:0] mcAddrVirtual;
  reg[0:0] mcExecMode;
  wire[31:0] phRamRead;
  wire[31:0] phRamWrite;
  wire[31:0] phRamAddress;
  wire[0:0] phRequest;
  wire[0:0] phWriteEnable;
  wire[31:0] debug;
  wire[31:0] ptAddress;
  PhysicalRAM ram(clk, phRamAddress, phWriteEnable, phRamWrite, phRamRead);
  MemoryController MMU1(clk, RamOutput, mcStatus, mcRamAddress, mcRamIn, mcRequest, mcWriteEnable, mcAddrVirtual, mcExecMode, phRamRead, phRamAddress, phRamWrite, phRequest, phWriteEnable, ptAddress, debug);
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        mcExecMode <= 1'b0;
        mcAddrVirtual <= 1'b0;
        mcRamAddress <= 32'd0;
        mcRequest <= 1'b1;
        mcWriteEnable <= 1'b1;
        mcRamIn <= 32'd291;
        fsmState <= `__WaitWrite1;
      end
      `__WaitWrite1: begin
        if (mcStatus == 2)
        begin
          mcRequest <= 1'b1;
          mcWriteEnable <= 1'b0;
          fsmState <= `__WaitRead1;
        end
        else
        begin
          mcRequest <= 1'b0;
        end
      end
      `__WaitRead1: begin
        mcRequest <= 1'b0;
        if (mcStatus == 2)
        begin
          fsmState <= `__End;
        end
      end
      `__End: begin
      end
    endcase
  end
endmodule
