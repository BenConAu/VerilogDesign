module MemoryController(
  clk,
  mcRamOut,
  mcStatus,
  RequestIn,
  mcCommand,
  mcAddrVirtual,
  mcExecMode,
  phRamIn,
  phRamAddress,
  phRamOut,
  phRequest,
  phWriteEnable,
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
  input wire[64:0] RequestIn;
  input wire[0:0] mcCommand;
  input wire[0:0] mcAddrVirtual;
  input wire[0:0] mcExecMode;
  input wire[31:0] phRamIn;
  output reg[31:0] phRamAddress;
  output reg[31:0] phRamOut;
  output reg[0:0] phRequest;
  output reg[0:0] phWriteEnable;
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
        fsmState <= `__Ready;
      end
      `__Ready: begin
        if (mcCommand == 1)
        begin
          if (!mcAddrVirtual)
          begin
            phRamAddress <= RequestIn[64:33];
            phRequest <= 1'b1;
            phWriteEnable <= RequestIn[0:0];
            phRamOut <= RequestIn[32:1];
            savedRequest <= RequestIn;
            mcStatus <= 1;
            fsmState <= `__PRamWait1;
          end
          else
          begin
            if (tlbEntries[{ 4'd10, RequestIn[64:63] } ^ RequestIn[62:57] ^ RequestIn[56:51] ^ RequestIn[50:45] ^ RequestIn[44:39] ^ RequestIn[38:33]][39:20] == RequestIn[64:45] && tlbEntries[{ 4'd10, RequestIn[64:63] } ^ RequestIn[62:57] ^ RequestIn[56:51] ^ RequestIn[50:45] ^ RequestIn[44:39] ^ RequestIn[38:33]][63:63])
            begin
              if (tlbEntries[{ 4'd10, RequestIn[64:63] } ^ RequestIn[62:57] ^ RequestIn[56:51] ^ RequestIn[50:45] ^ RequestIn[44:39] ^ RequestIn[38:33]][62:62] && mcExecMode)
              begin
                mcStatus <= 0;
                fsmState <= `__Error;
              end
              else
              begin
                phRamAddress <= { tlbEntries[{ 4'd10, RequestIn[64:63] } ^ RequestIn[62:57] ^ RequestIn[56:51] ^ RequestIn[50:45] ^ RequestIn[44:39] ^ RequestIn[38:33]][19:0], RequestIn[44:33] };
                phRequest <= 1'b1;
                phWriteEnable <= RequestIn[0:0];
                phRamOut <= RequestIn[32:1];
                savedRequest <= { { tlbEntries[{ 4'd10, RequestIn[64:63] } ^ RequestIn[62:57] ^ RequestIn[56:51] ^ RequestIn[50:45] ^ RequestIn[44:39] ^ RequestIn[38:33]][19:0], RequestIn[44:33] }, RequestIn[32:1], RequestIn[0:0] };
                mcStatus <= 1;
                fsmState <= `__PRamWait1;
              end
            end
            else
            begin
              phRamAddress <= ptAddress + RequestIn[64:45] * 32'd8;
              phRequest <= 1'b1;
              phWriteEnable <= 1'b0;
              savedPTReadAddr <= ptAddress + RequestIn[64:45] * 32'd8;
              savedRequest <= RequestIn;
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
        phRequest <= 1'b0;
        mcStatus <= 1;
        fsmState <= `__PRamWait2;
      end
      `__PRamWait2: begin
        if (!savedRequest[0:0])
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
        phRequest <= 1'b0;
        mcStatus <= 1;
        fsmState <= `__VPTWait2;
      end
      `__VPTWait2: begin
        savedFirstWord <= phRamIn;
        phRequest <= 1'b1;
        phRamAddress <= savedPTReadAddr + 32'd4;
        mcStatus <= 1;
        fsmState <= `__VPTWait3;
      end
      `__VPTWait3: begin
        phRequest <= 1'b0;
        mcStatus <= 1;
        fsmState <= `__VPTWait4;
      end
      `__VPTWait4: begin
        tlbEntries[{ 4'd10, savedRequest[64:63] } ^ savedRequest[62:57] ^ savedRequest[56:51] ^ savedRequest[50:45] ^ savedRequest[44:39] ^ savedRequest[38:33]] <= { savedFirstWord[31:31], savedFirstWord[30:30], savedFirstWord[29:8], { savedFirstWord[7:0], phRamIn[31:20] }, phRamIn[19:0] };
        if (savedFirstWord[30:30] && mcExecMode)
        begin
          mcStatus <= 0;
          fsmState <= `__Error;
        end
        else
        begin
          phRamAddress <= { phRamIn[19:0], savedRequest[44:33] };
          phRequest <= 1'b1;
          phWriteEnable <= savedRequest[0:0];
          phRamOut <= savedRequest[32:1];
          savedRequest <= { { phRamIn[19:0], savedRequest[44:33] }, savedRequest[32:1], savedRequest[0:0] };
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
