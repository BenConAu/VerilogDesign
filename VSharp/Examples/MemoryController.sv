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
  ptAddress,
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
  input wire[31:0] ptAddress;
  output reg[31:0] debug;
  reg clk = 0; always #5 clk = !clk;
  reg[0:0] isRead;
  reg[0:0] savedReadReq;
  reg[0:0] savedWriteReq;
  reg[31:0] savedVirtAddr;
  reg[31:0] savedPTReadAddr;
  reg[31:0] savedFirstWord;
  reg[31:0] savedWriteData;
  reg[63:0] tlbEntries[63:0];
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
            if (tlbEntries[{ 0, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][39:20] == mcRamAddress[31:12] && tlbEntries[{ 0, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][63:63])
            begin
              if (tlbEntries[{ 0, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][62:62] && mcExecMode)
              begin
                mcStatus <= 0;
                fsmState <= `__Error;
              end
              else
              begin
                phRamAddress <= { tlbEntries[{ 0, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][19:0], mcRamAddress[11:0] };
                phReadReq <= mcReadReq;
                phWriteReq <= mcWriteReq;
                phRamOut <= mcRamIn;
                isRead <= mcReadReq;
                mcStatus <= 1;
                fsmState <= `__PRamWait1;
              end
            end
            else
            begin
              phRamAddress <= ptAddress + mcRamAddress[31:12] * 8;
              phReadReq <= 1;
              savedVirtAddr <= mcRamAddress;
              savedPTReadAddr <= ptAddress + mcRamAddress[31:12] * 8;
              savedReadReq <= mcReadReq;
              savedWriteReq <= mcWriteReq;
              savedWriteData <= mcRamIn;
              mcStatus <= 1;
              fsmState <= `__VPTWait1;
            end
          end
        end
        else
        begin
          mcStatus <= 1;
        end
      end
      `__PRamWait1: begin
        mcStatus <= 1;
        fsmState <= `__PRamWait2;
      end
      `__PRamWait2: begin
        if (isRead)
        begin
          mcRamOut <= phRamIn;
        end
        else
        begin
        end
        mcStatus <= 2;
        fsmState <= `__Ready;
      end
      `__VPTWait1: begin
        mcStatus <= 1;
        fsmState <= `__VPTWait2;
      end
      `__VPTWait2: begin
        savedFirstWord <= phRamIn;
        phRamAddress <= savedPTReadAddr + 4;
        mcStatus <= 1;
        fsmState <= `__VPTWait3;
      end
      `__VPTWait3: begin
        mcStatus <= 1;
        fsmState <= `__VPTWait4;
      end
      `__VPTWait4: begin
        tlbEntries[{ 0, savedVirtAddr[31:30] } ^ savedVirtAddr[29:24] ^ savedVirtAddr[23:18] ^ savedVirtAddr[17:12] ^ savedVirtAddr[11:6] ^ savedVirtAddr[5:0]] <= { savedFirstWord[31:31], savedFirstWord[30:30], savedFirstWord[29:8], { savedFirstWord[7:0], phRamIn[31:20] }, phRamIn[19:0] };
        if (savedFirstWord[30:30] && mcExecMode)
        begin
          mcStatus <= 0;
          fsmState <= `__Error;
        end
        else
        begin
          phRamAddress <= { phRamIn[19:0], mcRamAddress[11:0] };
          phReadReq <= savedReadReq;
          phWriteReq <= savedWriteReq;
          phRamOut <= savedWriteData;
          isRead <= savedReadReq;
          mcStatus <= 1;
          fsmState <= `__PRamWait1;
        end
      end
      `__Error: begin
        mcStatus <= 1;
        fsmState <= `__Ready;
      end
    endcase
  end
endmodule
