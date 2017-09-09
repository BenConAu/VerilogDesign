module MemoryController(
  reset,
  clk,
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
  input wire[0:0] clk;
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
  reg[64:0] savedRequest;
  reg[31:0] savedPTReadAddr;
  reg[31:0] savedFirstWord;
  reg[63:0] tlbEntries[63:0];
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        mcStatus <= 1;
      end
      `__Ready: begin
        if (mcReadReq || mcWriteReq)
        begin
          if (mcAddrVirtual)
          begin
            phRamAddress <= mcRamAddress;
            phReadReq <= mcReadReq;
            phWriteReq <= mcReadReq;
            phRamOut <= mcRamIn;
            savedRequest <= { mcReadReq, mcRamAddress, mcRamIn };
            mcStatus <= 1;
            fsmState <= `__PRamWait1;
          end
          else
          begin
            if (tlbEntries[{ 4'd10, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][39:20] == mcRamAddress[31:12] && tlbEntries[{ 4'd10, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][63:63])
            begin
              if (tlbEntries[{ 4'd10, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][62:62] && mcExecMode)
              begin
                mcStatus <= 0;
                fsmState <= `__Error;
              end
              else
              begin
                phRamAddress <= { tlbEntries[{ 4'd10, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][19:0], mcRamAddress[11:0] };
                phReadReq <= mcReadReq;
                phWriteReq <= mcReadReq;
                phRamOut <= mcRamIn;
                savedRequest <= { mcReadReq, { tlbEntries[{ 4'd10, mcRamAddress[31:30] } ^ mcRamAddress[29:24] ^ mcRamAddress[23:18] ^ mcRamAddress[17:12] ^ mcRamAddress[11:6] ^ mcRamAddress[5:0]][19:0], mcRamAddress[11:0] }, mcRamIn };
                mcStatus <= 1;
                fsmState <= `__PRamWait1;
              end
            end
            else
            begin
              phRamAddress <= ptAddress + mcRamAddress[31:12] * 32'd8;
              phReadReq <= 1'b1;
              savedPTReadAddr <= ptAddress + mcRamAddress[31:12] * 32'd8;
              savedRequest[63:32] <= mcRamAddress;
              savedRequest[64:64] <= mcReadReq;
              savedRequest[31:0] <= mcRamIn;
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
        if (savedRequest[64:64])
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
        phRamAddress <= savedPTReadAddr + 32'd4;
        mcStatus <= 1;
        fsmState <= `__VPTWait3;
      end
      `__VPTWait3: begin
        mcStatus <= 1;
        fsmState <= `__VPTWait4;
      end
      `__VPTWait4: begin
        tlbEntries[{ 4'd10, savedRequest[63:32][31:30] } ^ savedRequest[63:32][29:24] ^ savedRequest[63:32][23:18] ^ savedRequest[63:32][17:12] ^ savedRequest[63:32][11:6] ^ savedRequest[63:32][5:0]] <= { savedFirstWord[31:31], savedFirstWord[30:30], savedFirstWord[29:8], { savedFirstWord[7:0], phRamIn[31:20] }, phRamIn[19:0] };
        if (savedFirstWord[30:30] && mcExecMode)
        begin
          mcStatus <= 0;
          fsmState <= `__Error;
        end
        else
        begin
          phRamAddress <= { phRamIn[19:0], savedRequest[63:32][11:0] };
          phReadReq <= savedRequest[64:64];
          phWriteReq <= savedRequest[64:64];
          phRamOut <= savedRequest[31:0];
          savedRequest <= { savedRequest[64:64], { phRamIn[19:0], savedRequest[63:32][11:0] }, savedRequest[31:0] };
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
