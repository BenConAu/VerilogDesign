module ALU(
  clk,
  reset,
  ramIn,
  mcStatus,
  ramAddress,
  ramOut,
  readReq,
  writeReq,
  addrVirtual,
  execMode,
  ptAddress,
  uartReadReq,
  uartReadAck,
  uartReadData,
  uartWriteReq,
  uartWriteData,
  uartWriteReady,
  ipointer,
  opCode,
  r0,
  r1,
  r2,
  r3,
  r4,
  r5,
  rPos,
  debug,
  debug2,
  debug3
  );
  // State definitions
  `define __initial 0
  `define __always 1
  `define __InitialMode 2
  `define __InstrReadComplete 3
  `define __RegValueSet 4
  `define __DataWordComplete 5
  `define __RWRequest 6
  `define __IORWWait 7
  `define __MemRWComplete 8
  `define __IORWComplete 9
  `define __ProcessOpCode 10
  `define __ErrorHalt 11
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[0:0] reset;
  input wire[31:0] ramIn;
  input wire[1:0] mcStatus;
  output reg[31:0] ramAddress;
  output reg[31:0] ramOut;
  output reg[0:0] readReq;
  output reg[0:0] writeReq;
  output reg[0:0] addrVirtual;
  output reg[0:0] execMode;
  output reg[31:0] ptAddress;
  output reg[0:0] uartReadReq;
  input wire[0:0] uartReadAck;
  input wire[7:0] uartReadData;
  output reg[0:0] uartWriteReq;
  output reg[7:0] uartWriteData;
  input wire[0:0] uartWriteReady;
  output reg[31:0] ipointer;
  output reg[5:0] opCode;
  output reg[31:0] r0;
  output reg[31:0] r1;
  output reg[31:0] r2;
  output reg[31:0] r3;
  output reg[31:0] r4;
  output reg[31:0] r5;
  output reg[7:0] rPos;
  output reg[31:0] debug;
  output reg[31:0] debug2;
  output reg[8:0] debug3;
  reg[31:0] counter = 32'd0;
  reg[0:0] initComplete = 1'b0;
  reg[31:0] regarray[68:0];
  reg[31:0] ramValue;
  reg[31:0] regValue[68:0];
  reg[31:0] regValue2[68:0];
  reg[31:0] regValue3[68:0];
  reg[31:0] opDataWord;
  reg[7:0] regAddress;
  reg[7:0] regAddress2;
  reg[7:0] regAddress3;
  reg[6:0] fOpEnable;
  reg[0:0] condJump;
  reg[31:0] sentinel;
  reg[1:0] errorHaltCode;
  reg[31:0] errorHaltData;
  wire[31:0] fAddResult[68:0];
  wire[31:0] fSubResult;
  wire[31:0] fConvResult;
  wire[31:0] fMulResult;
  wire[31:0] fMulAddResult;
  wire[31:0] fDivResult;
  wire[31:0] floatDebug;
  wire[1:0] fCompareResult;
  FloatingAdd fAdd0(regValue2[32'd0], regValue3[32'd0], 1'b0, fAddResult[32'd0], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd fAdd1(regValue2[32'd1], regValue3[32'd1], 1'b0, fAddResult[32'd1], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd fAdd2(regValue2[32'd2], regValue3[32'd2], 1'b0, fAddResult[32'd2], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd fAdd3(regValue2[32'd3], regValue3[32'd3], 1'b0, fAddResult[32'd3], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd fSub(regValue[32'd0], regValue2[32'd0], 1'b1, fSubResult, floatDebug, clk, fOpEnable[1:1]);
  wire[31:0] dbgBufDbg1;
  wire[31:0] dbgBufDbg2;
  reg[0:0] dbgBufferWriteReq;
  reg[31:0] dbgBufferWriteData;
  wire[31:0] dbgBufferReadData;
  wire[0:0] dbgBufferReadComplete;
  reg[0:0] dbgBufferReadReq;
  wire[31:0] dbgBufferLength;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        debug <= 32'd0;
        debug2 <= 32'd0;
        debug3 <= 9'd1;
        writeReq <= 1'b0;
        uartReadReq <= 1'b0;
        readReq <= 1'b0;
        opDataWord <= 32'd4294967295;
        opCode <= 0;
        fOpEnable <= 7'd0;
        ipointer <= 32'd0;
        condJump <= 1'b0;
        dbgBufferWriteReq <= 1'b0;
        dbgBufferReadReq <= 1'b0;
        execMode <= 1'b0;
        addrVirtual <= 1'b0;
        rPos <= 32'd5;
        regarray[32'd0] <= 32'd0;
        regarray[32'd1] <= 32'd0;
        regarray[32'd2] <= 32'd0;
        regarray[32'd3] <= 32'd0;
        regarray[32'd4] <= 32'd0;
        initComplete <= 1'b1;
      end
      `__always: begin
        r0 <= regarray[rPos];
        r1 <= regarray[rPos + 32'd1];
        r2 <= regarray[rPos + 32'd2];
        r3 <= regarray[rPos + 32'd3];
        r4 <= regarray[rPos + 32'd4];
        r5 <= regarray[32'd0];
        ptAddress <= regarray[32'd4];
        debug2[11:0] <= ipointer[11:0];
        debug2[31:12] <= { 14'd0, opCode };
      end
      `__InitialMode: begin
        readReq <= 1'b1;
        ramAddress <= ipointer;
        opDataWord <= 32'd195948557;
        fOpEnable <= 7'd0;
        condJump <= 1'b0;
        fsmState <= `__InstrReadComplete;
      end
      `__InstrReadComplete: begin
        readReq <= 1'b0;
        if (mcStatus == 2)
        begin
          opCode <= { ramIn[5:0] };
          regAddress <= (ramIn[15:8] >= 32'd64) ? (ramIn[15:8] - 32'd64) : (ramIn[15:8] + rPos);
          regAddress2 <= (ramIn[23:16] >= 32'd64) ? (ramIn[23:16] - 32'd64) : (ramIn[23:16] + rPos);
          regAddress3 <= (ramIn[31:24] >= 32'd64) ? (ramIn[31:24] - 32'd64) : (ramIn[31:24] + rPos);
          fsmState <= `__RegValueSet;
        end
        else
        begin
          if (mcStatus == 0)
          begin
            $display("Memory controller error when reading instruction, halting");
            errorHaltCode <= 0;
            errorHaltData <= ramAddress;
            fsmState <= `__ErrorHalt;
          end
        end
      end
      `__RegValueSet: begin
        regValue[32'd0] <= regarray[regAddress[7:0]];
        if (opCode == 46)
        begin
          regValue[32'd1] <= regarray[regAddress[7:0] + 32'd1];
          regValue[32'd2] <= regarray[regAddress[7:0] + 32'd2];
          regValue[32'd3] <= regarray[regAddress[7:0] + 32'd3];
        end
        regValue2[32'd0] <= regarray[regAddress2[7:0]];
        if (opCode == 46)
        begin
          regValue2[32'd1] <= regarray[regAddress2[7:0] + 32'd1];
          regValue2[32'd2] <= regarray[regAddress2[7:0] + 32'd2];
          regValue2[32'd3] <= regarray[regAddress2[7:0] + 32'd3];
        end
        regValue3[32'd0] <= regarray[regAddress3[7:0]];
        if (opCode == 46)
        begin
          regValue3[32'd1] <= regarray[regAddress3[7:0] + 32'd1];
          regValue3[32'd2] <= regarray[regAddress3[7:0] + 32'd2];
          regValue3[32'd3] <= regarray[regAddress3[7:0] + 32'd3];
        end
        if (opCode == 38 || opCode == 46)
        begin
          fOpEnable[0:0] <= 1'b1;
        end
        if (opCode == 39)
        begin
          fOpEnable[1:1] <= 1'b1;
        end
        if (opCode == 40)
        begin
          fOpEnable[2:2] <= 1'b1;
        end
        if (opCode == 41)
        begin
          fOpEnable[3:3] <= 1'b1;
        end
        if (opCode == 43)
        begin
          fOpEnable[4:4] <= 1'b1;
        end
        if (opCode == 44)
        begin
          fOpEnable[5:5] <= 1'b1;
        end
        if (opCode == 45)
        begin
          fOpEnable[5:5] <= 1'b1;
        end
        if (opCode == 42)
        begin
          fOpEnable[6:6] <= 1'b1;
        end
        if (opCode == 20 && regarray[32'd1][0:0] == 1'b0)
        begin
          condJump <= 1'b1;
        end
        if (opCode == 21 && regarray[32'd1][0:0] == 1'b1)
        begin
          condJump <= 1'b1;
        end
        if (opCode == 22 && regarray[regAddress[7:0]] == 32'd0)
        begin
          condJump <= 1'b1;
        end
        if (opCode == 23 && regarray[regAddress[7:0]] != 32'd0)
        begin
          condJump <= 1'b1;
        end
        if (opCode == 2 || opCode == 4 || opCode == 5 || opCode == 6 || opCode == 7 || opCode == 8 || opCode == 9 || opCode == 14 || opCode == 19 || opCode == 20 || opCode == 21 || opCode == 22 || opCode == 23 || opCode == 26 || opCode == 28 || opCode == 30 || opCode == 32 || opCode == 55)
        begin
          readReq <= 1'b1;
          ramAddress <= ipointer + 32'd4;
          fsmState <= `__DataWordComplete;
        end
        else
        begin
          if (opCode == 3 || opCode == 4 || opCode == 5 || opCode == 6 || opCode == 7 || opCode == 8 || opCode == 9 || opCode == 11 || opCode == 12 || opCode == 24 || opCode == 25 || opCode == 56)
          begin
            if (opCode == 47 || opCode == 48 || opCode == 50 || opCode == 51)
            begin
              if (1'b1 || 1'b1)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
            else
            begin
              if (1'b1 || 1'b0)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
          end
          else
          begin
            if (opCode == 47 || opCode == 48 || opCode == 50 || opCode == 51)
            begin
              if (1'b0 || 1'b1)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
            else
            begin
              if (1'b0 || 1'b0)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
          end
        end
      end
      `__DataWordComplete: begin
        readReq <= 1'b0;
        if (mcStatus == 2)
        begin
          opDataWord <= ramIn;
          if (opCode == 3 || opCode == 4 || opCode == 5 || opCode == 6 || opCode == 7 || opCode == 8 || opCode == 9 || opCode == 11 || opCode == 12 || opCode == 24 || opCode == 25 || opCode == 56)
          begin
            if (opCode == 47 || opCode == 48 || opCode == 50 || opCode == 51)
            begin
              if (1'b1 || 1'b1)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
            else
            begin
              if (1'b1 || 1'b0)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
          end
          else
          begin
            if (opCode == 47 || opCode == 48 || opCode == 50 || opCode == 51)
            begin
              if (1'b0 || 1'b1)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
            else
            begin
              if (1'b0 || 1'b0)
              begin
                fsmState <= `__RWRequest;
              end
              else
              begin
                fsmState <= `__ProcessOpCode;
              end
            end
          end
        end
        else
        begin
          if (mcStatus == 0)
          begin
            errorHaltCode <= 1;
            errorHaltData <= ramAddress;
            fsmState <= `__ErrorHalt;
          end
        end
      end
      `__RWRequest: begin
        if (opCode == 3 || opCode == 4 || opCode == 5 || opCode == 6 || opCode == 7 || opCode == 8 || opCode == 9 || opCode == 11 || opCode == 12 || opCode == 24 || opCode == 25 || opCode == 56)
        begin
          case (opCode)
            6: begin
              readReq <= 1'b1;
              ramAddress <= opDataWord;
            end
            4: begin
              readReq <= 1'b1;
              ramAddress <= opDataWord + regValue2[32'd0];
            end
            5: begin
              readReq <= 1'b1;
              ramAddress <= regValue2[32'd0] + opDataWord * regValue3[32'd0];
            end
            3: begin
              readReq <= 1'b1;
              ramAddress <= regValue2[32'd0];
            end
            12: begin
              readReq <= 1'b1;
              ramAddress <= regarray[32'd0] - 32'd4;
            end
            25: begin
              readReq <= 1'b1;
              ramAddress <= regarray[32'd0] - 32'd4;
            end
            7: begin
              writeReq <= 1'b1;
              ramAddress <= opDataWord;
              ramOut <= regValue2[32'd0];
            end
            8: begin
              writeReq <= 1'b1;
              ramAddress <= opDataWord + regValue[32'd0];
              ramOut <= regValue2[32'd0];
            end
            9: begin
              writeReq <= 1'b1;
              ramAddress <= regValue[32'd0] + opDataWord * regValue2[32'd0];
              ramOut <= regValue3[32'd0];
            end
            11: begin
              writeReq <= 1'b1;
              ramAddress <= regarray[32'd0];
              ramOut <= regValue[32'd0];
            end
            24: begin
              writeReq <= 1'b1;
              ramAddress <= regarray[32'd0];
              ramOut <= ipointer;
            end
            56: begin
              readReq <= 1'b1;
              ramAddress <= regValue[32'd0];
            end
          endcase
          fsmState <= `__MemRWComplete;
        end
        else
        begin
          if (opCode == 47 || opCode == 48 || opCode == 50 || opCode == 51)
          begin
            readReq <= 1'b0;
            case (opCode)
              50: begin
                case (regValue2[32'd0])
                  32'd1: begin
                    uartReadReq <= 1'b1;
                  end
                  default: begin
                    $display("Unknown port %h being read", regValue[32'd0]);
                  end
                endcase
              end
              51: begin
                uartWriteReq <= 1'b1;
                uartWriteData <= regValue2[32'd0][7:0];
              end
              47: begin
                dbgBufferWriteReq <= 1'b1;
                dbgBufferWriteData <= regValue[32'd0];
              end
              48: begin
                dbgBufferReadReq <= 1'b1;
              end
            endcase
            fsmState <= `__IORWWait;
          end
          else
          begin
          end
        end
      end
      `__IORWWait: begin
        uartReadReq <= 1'b0;
        uartWriteReq <= 1'b0;
        dbgBufferWriteReq <= 1'b0;
        dbgBufferReadReq <= 1'b0;
        fsmState <= `__IORWComplete;
      end
      `__MemRWComplete: begin
        readReq <= 1'b0;
        writeReq <= 1'b0;
        if (mcStatus == 2)
        begin
          if (opCode == 6 || opCode == 4 || opCode == 5 || opCode == 3 || opCode == 12 || opCode == 25)
          begin
            ramValue <= ramIn;
          end
          fsmState <= `__ProcessOpCode;
        end
        else
        begin
          if (mcStatus == 0)
          begin
            if (!execMode)
            begin
              $display("Memory controller says access to protected page from kernel mode, execMode = %h", execMode);
              fsmState <= `__ErrorHalt;
              errorHaltCode <= 2;
              errorHaltData <= ramAddress;
            end
            else
            begin
              $display("Memory controller says access to protected page from user mode, execMode = %h", execMode);
              opCode <= 53;
              fsmState <= `__ProcessOpCode;
            end
          end
        end
      end
      `__IORWComplete: begin
        if (opCode == 50)
        begin
          case (regValue2[32'd0])
            32'd1: begin
              if (uartReadAck == 1'b1)
              begin
                ramValue[7:0] <= uartReadData;
                ramValue[31:8] <= 24'd1;
              end
              else
              begin
                ramValue <= 32'd0;
              end
            end
            32'd2: begin
              ramValue[0:0] <= uartWriteReady;
              ramValue[31:1] <= 31'd0;
            end
            default: begin
              $display("Unknown port %h being read", regValue[32'd0]);
            end
          endcase
        end
        else
        begin
          if (opCode == 48)
          begin
            ramValue <= dbgBufferReadData;
          end
        end
        fsmState <= `__ProcessOpCode;
      end
      `__ProcessOpCode: begin
        case (opCode)
          2: begin
            regarray[regAddress[7:0]] <= opDataWord;
          end
          6: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          1: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0];
          end
          10: begin
            case (regValue3[32'd0][1:0])
              32'd0: begin
                regarray[regAddress[7:0]][7:0] <= regValue2[32'd0][7:0];
              end
              32'd1: begin
                regarray[regAddress[7:0]][15:8] <= regValue2[32'd0][7:0];
              end
              32'd2: begin
                regarray[regAddress[7:0]][23:16] <= regValue2[32'd0][7:0];
              end
              32'd3: begin
                regarray[regAddress[7:0]][31:24] <= regValue2[32'd0][7:0];
              end
              default: begin
                $display("Out of range byte position");
              end
            endcase
          end
          4: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          5: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          3: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          55: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] + opDataWord * regValue3[32'd0];
          end
          50: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          11: begin
            regarray[32'd0] <= regarray[32'd0] + 32'd4;
          end
          12: begin
            regarray[regAddress[7:0]] <= ramValue;
            regarray[32'd0] <= regarray[32'd0] - 32'd4;
          end
          24: begin
            regarray[32'd0] <= regarray[32'd0] + 32'd4;
            ipointer <= regValue[32'd0];
            debug3 <= 9'd3;
          end
          25: begin
            regarray[32'd0] <= regarray[32'd0] - 32'd4;
            ipointer <= ramValue + 32'd4;
            debug3 <= 9'd4;
          end
          26: begin
            regarray[rPos + opDataWord] <= ipointer;
            regarray[rPos + opDataWord + 32'd1] <= opDataWord;
            rPos <= rPos + opDataWord + 32'd2;
            ipointer <= regValue[32'd0];
            debug3 <= 9'd5;
          end
          27: begin
            ipointer <= regarray[rPos - 32'd2] + 32'd8;
            debug3 <= 9'd6;
            rPos <= rPos - (regarray[rPos - 32'd1] + 32'd2);
          end
          13: begin
            regarray[32'd1][0:0] <= (regValue[32'd0] == regValue2[32'd0] ? 1'b1 : 1'b0);
            regarray[32'd1][1:1] <= (regValue[32'd0] < regValue2[32'd0] ? 1'b1 : 1'b0);
            regarray[32'd1][2:2] <= (regValue[32'd0] > regValue2[32'd0] ? 1'b1 : 1'b0);
          end
          14: begin
            regarray[32'd1][0:0] <= (regValue[32'd0] == opDataWord ? 1'b1 : 1'b0);
            regarray[32'd1][1:1] <= (regValue[32'd0] < opDataWord ? 1'b1 : 1'b0);
            regarray[32'd1][2:2] <= (regValue[32'd0] > opDataWord ? 1'b1 : 1'b0);
          end
          15: begin
            regarray[regAddress[7:0]] <= (regValue2[32'd0] == regValue3[32'd0] ? 32'd1 : 32'd0);
          end
          16: begin
            regarray[regAddress[7:0]] <= (regValue2[32'd0] != regValue3[32'd0] ? 32'd1 : 32'd0);
          end
          17: begin
            regarray[regAddress[7:0]] <= (regValue2[32'd0] < regValue3[32'd0] ? 32'd1 : 32'd0);
          end
          18: begin
            regarray[regAddress[7:0]] <= (regValue2[32'd0] > regValue3[32'd0] ? 32'd1 : 32'd0);
          end
          19: begin
            ipointer <= opDataWord;
            debug3 <= 9'd7;
          end
          38: begin
            regarray[regAddress[7:0]] <= fAddResult[32'd0];
          end
          39: begin
            regarray[regAddress[7:0]] <= fSubResult;
          end
          40: begin
            regarray[regAddress[7:0]] <= fConvResult;
          end
          41: begin
            regarray[regAddress[7:0]] <= fMulResult;
          end
          42: begin
            regarray[regAddress[7:0]] <= fDivResult;
          end
          43: begin
            regarray[regAddress[7:0]] <= fMulAddResult;
          end
          44: begin
            regarray[regAddress[7:0]] <= (fCompareResult == 2'd1 ? regValue2[32'd0] : regValue[32'd0]);
          end
          45: begin
            regarray[regAddress[7:0]] <= (fCompareResult == 2'd3 ? regValue2[32'd0] : regValue[32'd0]);
          end
          46: begin
            regarray[regAddress[7:0]] <= fAddResult[32'd0];
            regarray[regAddress[7:0] + 32'd1] <= fAddResult[32'd1];
            regarray[regAddress[7:0] + 32'd2] <= fAddResult[32'd2];
            regarray[regAddress[7:0] + 32'd3] <= fAddResult[32'd3];
          end
          28: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] + opDataWord;
          end
          29: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] + regValue3[32'd0];
          end
          30: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] - opDataWord;
          end
          31: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] - regValue3[32'd0];
          end
          33: begin
            regarray[regAddress[7:0]] <= regValue[32'd0] + 32'd1;
          end
          34: begin
            regarray[regAddress[7:0]] <= regValue[32'd0] - 32'd1;
          end
          35: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] << regValue3[32'd0];
          end
          36: begin
            regarray[regAddress[7:0]] <= regValue2[32'd0] >> regValue3[32'd0];
          end
          37: begin
            regarray[regAddress[7:0]] <= -regValue2[32'd0];
          end
          32: begin
            regarray[regAddress[7:0]] <= regValue[32'd0] + regValue2[32'd0] * opDataWord;
          end
          52: begin
            if (execMode == 1'b0)
            begin
              regarray[32'd3] <= ipointer + 32'd4;
              ipointer <= 32'd0;
              execMode <= 1'b1;
            end
          end
          53: begin
            if (execMode == 1'b1)
            begin
              ipointer <= regarray[32'd3];
              execMode <= 1'b0;
            end
          end
          47: begin
            $display("DebugOut %h", regValue[32'd0]);
            debug <= regValue[32'd0];
          end
          48: begin
            regarray[regAddress[7:0]] <= ramValue;
          end
          49: begin
            regarray[regAddress[7:0]] <= dbgBufferLength;
          end
          54: begin
            addrVirtual <= 1'b1;
          end
          default: begin
            $display("Unknown instruction %h", opCode);
          end
        endcase
        if (condJump == 1'b1)
        begin
          ipointer <= opDataWord;
          debug3 <= 9'd8;
        end
        else
        begin
          if (opCode != 19 && opCode != 24 && opCode != 25 && opCode != 26 && opCode != 27 && opCode != 52 && opCode != 53)
          begin
            if (opCode == 2 || opCode == 4 || opCode == 5 || opCode == 6 || opCode == 7 || opCode == 8 || opCode == 9 || opCode == 14 || opCode == 19 || opCode == 20 || opCode == 21 || opCode == 22 || opCode == 23 || opCode == 26 || opCode == 28 || opCode == 30 || opCode == 32 || opCode == 55)
            begin
              ipointer <= ipointer + 32'd8;
              debug3 <= 9'd9;
            end
            else
            begin
              ipointer <= ipointer + 32'd4;
              debug3 <= 9'd10;
            end
          end
        end
        if (opCode != 0 && opCode <= 56)
        begin
          fsmState <= `__InitialMode;
        end
        else
        begin
          fsmState <= `__ErrorHalt;
        end
      end
      `__ErrorHalt: begin
        $display("Halt with error code %h and data %h", errorHaltCode, errorHaltData);
        debug <= errorHaltData;
      end
    endcase
  end
endmodule
