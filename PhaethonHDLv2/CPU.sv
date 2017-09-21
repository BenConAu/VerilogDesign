module CPU(
  clk,
  reset,
  phRamRead,
  phRamAddress,
  phRamWrite,
  phReadReq,
  phWriteReq,
  uartReadReq,
  uartReadAck,
  uartReadData,
  uartWriteReq,
  uartWriteData,
  uartWriteReady,
  debug,
  debug2,
  debug3
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[0:0] reset;
  input wire[31:0] phRamRead;
  output reg[31:0] phRamAddress;
  output reg[31:0] phRamWrite;
  output reg[0:0] phReadReq;
  output reg[0:0] phWriteReq;
  output reg[0:0] uartReadReq;
  input wire[0:0] uartReadAck;
  input wire[7:0] uartReadData;
  output reg[0:0] uartWriteReq;
  output reg[7:0] uartWriteData;
  input wire[0:0] uartWriteReady;
  output reg[31:0] debug;
  output reg[31:0] debug2;
  output reg[8:0] debug3;
  wire[31:0] mcRamRead;
  wire[1:0] mcStatus;
  wire[0:0] mcCommand;
  wire[31:0] mcRamAddress;
  wire[31:0] mcRamWrite;
  wire[0:0] mcReadReq;
  wire[0:0] mcWriteReq;
  wire[0:0] mcAddrVirtual;
  wire[0:0] mcExecMode;
  wire[31:0] ptAddress;
  wire[31:0] iPointer;
  wire[5:0] opCode;
  wire[31:0] r0;
  wire[31:0] r1;
  wire[31:0] r2;
  wire[31:0] r3;
  wire[31:0] r4;
  wire[31:0] r5;
  wire[7:0] rPos;
  wire[31:0] mcDebug;
  ControlUnit control(clk, reset, mcRamRead, mcStatus, mcRamAddress, mcRamWrite, mcReadReq, mcWriteReq, mcAddrVirtual, mcExecMode, ptAddress, uartReadReq, uartReadAck, uartReadData, uartWriteReq, uartWriteData, uartWriteReady, iPointer, opCode, r0, r1, r2, r3, r4, r5, rPos, debug, debug2, debug3);
  MemoryController mc1(clk, mcRamRead, mcStatus, { mcRamAddress, mcRamWrite, mcWriteReq }, mcCommand, mcAddrVirtual, mcExecMode, phRamRead, phRamAddress, phRamWrite, phReadReq, phWriteReq, ptAddress, mcDebug);
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
    endcase
  end
endmodule
