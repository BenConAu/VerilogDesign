module MemoryController(
  reset,
  mcRamOut,
  mcStatus,
  mcRamAddress,
  mcRamIn,
  mcReadReq,
  mcWriteReq,
  mcAddrVirtual,
  mcExecMode,
  phRamIn,
  phRamAddress,
  phRamOut,
  phReadReq,
  phWriteReq,
  kptAddress,
  uptAddress,
  debug
  );
  // State definitions
  `define __initial 0
  `define __Ready 1
  `define __PRamWait1 2
  `define __PRamWait2 3
  `define __VPTWait1 4
  `define __VPTWait2 5
  `define __VPTWait3 6
  `define __VPTWait4 7
  `define __Error 8
  // inputs / outputs
  input wire reset;
  output reg[31:0] mcRamOut;
  output reg[1:0] mcStatus;
  input wire[31:0] mcRamAddress;
  input wire[31:0] mcRamIn;
  input wire[0:0] mcReadReq;
  input wire[0:0] mcWriteReq;
  input wire[0:0] mcAddrVirtual;
  input wire[0:0] mcExecMode;
  input wire[31:0] phRamIn;
  output reg[31:0] phRamAddress;
  output reg[31:0] phRamOut;
  output reg[0:0] phReadReq;
  output reg[0:0] phWriteReq;
  input wire[31:0] kptAddress;
  input wire[31:0] uptAddress;
  output reg[31:0] debug;
  reg clk = 0; always #5 clk = !clk;
  reg[0:0] isRead;
  reg[0:0] savedReadReq;
  reg[0:0] savedWriteReq;
  reg[31:0] savedVirtAddr;
  reg[31:0] savedPTReadAddr;
  reg[31:0] savedFirstWord;
  reg[31:0] savedWriteData;
  reg[63:0] ktlb[15:0];
  reg[63:0] utlb[15:0];
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        mcStatus <= 1;
        isRead <= 0;
      end
      `__Ready: begin
        if (mcReadReq || mcWriteReq)
        begin
          if (mcAddrVirtual)
          begin
            phRamAddress <= mcRamAddress;
            phReadReq <= mcReadReq;
            phWriteReq <= mcWriteReq;
            phRamOut <= mcRamIn;
            isRead <= mcReadReq;
            mcStatus <= 1;
            fsmState <= `__PRamWait1;
          end
          else
          begin
            if (mcExecMode)
            begin
              if (mcExecMode)
              begin
                if (ktlb[mcRamAddress[13:10]][39:20] == mcRamAddress[31:12] && ktlb[mcRamAddress[13:10]][63:63])
                begin
