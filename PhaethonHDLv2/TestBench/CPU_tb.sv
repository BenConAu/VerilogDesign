module CPUTestBench(
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  wire[31:0] phRamAddress;
  wire[0:0] phWriteEnable;
  wire[31:0] phRamWrite;
  wire[31:0] phRamRead;
  PhysicalRAM ram(clk, phRamAddress, phWriteEnable, phRamWrite, phRamRead);
  wire[0:0] uartReadReq;
  wire[0:0] phReadReq;
  wire[0:0] phWriteReq;
  wire[31:0] debug;
  wire[31:0] debug2;
  wire[8:0] debug3;
  wire[0:0] uartReadAck;
  wire[7:0] uartReadData;
  wire[0:0] uartWriteReq;
  wire[7:0] uartWriteData;
  wire[0:0] uartWriteReady;
  CPU cpu1(clk, phRamRead, phRamAddress, phRamWrite, phReadReq, phWriteReq, uartReadReq, uartReadAck, uartReadData, uartWriteReq, uartWriteData, uartWriteReady, debug, debug2, debug3);
  initial
  begin
    # 3000 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
  end
endmodule
