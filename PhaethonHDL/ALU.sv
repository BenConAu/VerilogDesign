module ALU(
  clk,         // [Input]  Clock driving the ALU
  reset,       // [Input]  Reset pin
  ramIn,       // [Input]  RAM at requested address
  ramAddress,  // [Output] RAM address requested
  ramOut,      // [Output] RAM to write
  readReq,     // [Output] RAM read request
  writeReq,    // [Output] RAM write request
  ipointer,    // [Debug]  Instruction pointer value
  opCode,      // [Debug]  current opCode value
  r0,          // [Debug]  current r0 value
  r1,          // [Debug]  current r1 value
  r2,          // [Debug]  current r2 value
  r3,          // [Debug]  current r3 value
  r4,          // [Debug]  current r4 value
  r5,          // [Debug]  current r5 value
  rPos,        // [Debug]  current rPos (register window) value
  debug        // [Output] Debug port
  );

  `include "../PhaethonISA/Generated/PhaethonOpCode.v"

  // Input / output
  input  wire        clk;
  input  wire        reset;
  input  wire [31:0] ramIn;
  output reg [31:0]  ramAddress;
  output reg [31:0]  ramOut;
  output reg [0:0]   readReq;
  output reg [0:0]   writeReq;
  output reg [31:0]  ipointer;
  output reg [7:0]   opCode;
  output reg [31:0]  r0;
  output reg [31:0]  r1;
  output reg [31:0]  r2;
  output reg [31:0]  r3;
  output reg [31:0]  r4;
  output reg [31:0]  r5;
  output reg [31:0]  debug;
  output reg [7:0]   rPos;

  // Local registers
  reg        [31:0] regarray[0:65];
  reg        [4:0]  mode;
  reg        [31:0] ramValue;
  reg        [31:0] regValue[0:3];
  reg        [31:0] regValue2[0:3];
  reg        [31:0] regValue3[0:3];
  reg        [31:0] opDataWord;
  reg        [7:0]  regAddress;
  reg        [7:0]  regAddress2;
  reg        [7:0]  regAddress3;
  reg        [6:0]  fOpEnable;
  reg        [0:0]  condJump;

  // Wire up the results from the floating units
  wire       [31:0] fAddResult[0:3];
  wire       [31:0] fSubResult;
  wire       [31:0] fConvResult;
  wire       [31:0] fMulResult;
  wire       [31:0] fMulAddResult;
  wire       [31:0] fDivResult;
  wire       [31:0] floatDebug;
  wire       [1:0]  fCompareResult;

  FloatingAdd         fAdd0(regValue2[0], regValue3[0], 1'b0, fAddResult[0], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd         fAdd1(regValue2[1], regValue3[1], 1'b0, fAddResult[1], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd         fAdd2(regValue2[2], regValue3[2], 1'b0, fAddResult[2], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd         fAdd3(regValue2[3], regValue3[3], 1'b0, fAddResult[3], floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd         fSub(regValue[0], regValue2[0], 1'b1, fSubResult, floatDebug, clk, fOpEnable[1:1]);
  FloatingFromInt     fConv(regValue[0], fConvResult, floatDebug, clk, fOpEnable[2:2]);
  FloatingMultiply    fMul(regValue2[0], regValue3[0], fMulResult, floatDebug, clk, fOpEnable[3:3]);
  FloatingMultiplyAdd fMulAdd(regValue[0], regValue2[0], regValue3[0], fMulAddResult, floatDebug, clk, fOpEnable[4:4]);
  FloatingCompare     fComp(regValue[0], regValue2[0], fCompareResult, floatDebug, clk, fOpEnable[5:5]);
  FloatingDivide      fDiv(regValue[0], regValue2[0], fDivResult, floatDebug, clk, fOpEnable[6:6]);

  //initial
  //   $monitor("%t, ram = %h, %h, %h, %h : %h, %h, %h, %h",
  //     $time, ramIn[7:0], ramIn[15:8], ramIn[23:16], ramIn[31:24], ramAddress, ramIn, opAddress, ramValue);

  always @(posedge clk or posedge reset)
  begin
    if (reset)
    begin
      ipointer <= 0;
      opCode <= 0;
      opDataWord <= 'hffffffff;
      rPos <= 2;
      mode <= 0;
      readReq <= 0;
      writeReq <= 0;
      fOpEnable <= 7'b0000000;
      condJump <= 1'b0;
    end
    else
    begin
      case (mode)
      // Mode 0: Schedule read of code at instruction pointer and clear
      //         out enable bits for auxillary modules.
      0: begin
        // Begin RAM read for instruction data
        readReq <= 1;
        ramAddress <= ipointer;
        opDataWord <= 'h0badf00d;

        debug[23:0] <= ipointer;
        debug[31:24] <= mode;

        // Clear out stuff for the pipeline
        fOpEnable <= 7'b0000000;
        condJump <= 1'b0;
        mode <= 'ha;
      end

      // Mode a - ramIn is set by RAM module
      'ha: begin
        // Stop request
        readReq <= 0;

        mode <= 1;

        debug[23:0] <= 0;
        debug[31:24] <= mode;
      end

      // Mode 1: Handle ack of instruction pointer read request and
      //         decode the instruction data, including the opCode
      //         of the instruction and the affected registers.
      1: begin
        // Since we did read request on mode 0, ram should be ready now
        //$display("Receiving value %h", ramIn);

        opCode <= ramIn[7:0];
        regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
        regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
        regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);

        // Move to next mode now
        mode <= 2;

        debug[23:0] <= ramIn[23:0];
        debug[31:24] <= mode;
      end

      // Mode 2: Schedule read of additional code for opCodes that
      //         store word data. Read in register values for
      //         registers referenced by the instruction.
      2: begin
        // Read values from registers
        regValue[0] <= regarray[regAddress[7:0]];
        if (opCode == `VfaddRRR)
        begin
          regValue[1] <= regarray[regAddress[7:0] + 1];
          regValue[2] <= regarray[regAddress[7:0] + 2];
          regValue[3] <= regarray[regAddress[7:0] + 3];
        end

        regValue2[0] <= regarray[regAddress2[7:0]];
        if (opCode == `VfaddRRR)
        begin
          regValue2[1] <= regarray[regAddress2[7:0] + 1];
          regValue2[2] <= regarray[regAddress2[7:0] + 2];
          regValue2[3] <= regarray[regAddress2[7:0] + 3];
        end

        regValue3[0] <= regarray[regAddress3[7:0]];
        if (opCode == `VfaddRRR)
        begin
          regValue3[1] <= regarray[regAddress3[7:0] + 1];
          regValue3[2] <= regarray[regAddress3[7:0] + 2];
          regValue3[3] <= regarray[regAddress3[7:0] + 3];
        end

        // Enable operation for module
        if (opCode == `FaddRRR || opCode == `VfaddRRR) fOpEnable[0:0] <= 1;
        if (opCode == `FsubRR) fOpEnable[1:1] <= 1;
        if (opCode == `FconvR) fOpEnable[2:2] <= 1;
        if (opCode == `FmulRRR) fOpEnable[3:3] <= 1;
        if (opCode == `FmuladdRRR) fOpEnable[4:4] <= 1;
        if (opCode == `FminRR) fOpEnable[5:5] <= 1;
        if (opCode == `FmaxRR) fOpEnable[5:5] <= 1;
        if (opCode == `FdivRR) fOpEnable[6:6] <= 1;

        // Determine if a conditional jump needs to happen
        if (opCode == `JneC && regarray[1][0:0] == 1'b0) condJump <= 1'b1;
        if (opCode == `JeC && regarray[1][0:0] == 1'b1) condJump <= 1'b1;
        if (opCode == `JzRC && regarray[regAddress3[7:0]] == 0) condJump <= 1'b1;
        if (opCode == `JnzRC && regarray[regAddress3[7:0]] != 0) condJump <= 1'b1;

        if (Is8ByteOpcode(opCode) == 1)
        begin
          // Read values from ram requested by instruction
          readReq <= 1;
          ramAddress <= ipointer + 4;

          // We need to move into further modes
          mode <= 9;
        end
        else if (IsRAMOpcode(opCode) == 1)
        begin
          // We are not reading a constant, but we might still be
          // doing a RAM operation, move into the mode where we do that
          mode <= 5;
        end
        else
        begin
          // Since there is no word data, there is no need
          // to wait for that word data to come back, and there
          // can be no further reads or writes since the word
          // data is where the address would go
          mode <= 8;
        end

        debug[23:0] <= regAddress;
        debug[31:24] <= mode;
      end

      // Mode 9 - ramIn is set by RAM module for second word
      9: begin
        // Stop request
        readReq <= 0;

        mode <= 4;

        debug[23:0] <= 0;
        debug[31:24] <= mode;
      end

      // Mode 4: Complete read of additional code for opCodes that
      //         store word data. We only end up in this mode if
      //         the appropriate opCode is set, so no need to check
      //         the opCode.
      4: begin
        // Stop request
        readReq <= 0;

        // Store ram values requested
        opDataWord <= ramIn;

        // Move to next mode - only progress to data read / write
        // for opCodes that actually need it.
        if (IsRAMOpcode(opCode) == 1)
          mode <= 5;
        else
          mode <= 8;

        debug[23:0] <= ramIn;
        debug[31:24] <= mode;
      end

      // Mode 5: Initiate data read or write if the instruction
      //         requires it.
      5: begin
        if (opCode == `MovRdC)
        begin
          // Read values from address encoded in code
          readReq <= 1;
          ramAddress <= opDataWord;

          //$display("Requesting RdC read from %h", opDataWord);
        end

        if (opCode == `MovRdRo)
        begin
          // First register is destination, second register is base address, 
          // constant stores offset in bytes.
          readReq <= 1;
          ramAddress <= opDataWord + regValue2[0];

          //$display("Requesting read from %h", opDataWord + regValue2);
        end

        if (opCode == `MovRdRoR)
        begin
          // First register is destination, second register is base address, 
          // constant stores size of item, and third register stores index of item.
          readReq <= 1;
          ramAddress <= regValue2[0] + opDataWord * regValue3[0];

          //$display("Requesting read from %h", regValue2[0] + opDataWord * regValue3[0]);
        end

        if (opCode == `MovRdR)
        begin
          // Read values from address encoded in code
          readReq <= 1;
          ramAddress <= regValue2[0];

          //$display("Requesting read from %h", opDataWord + regValue2);
        end

        if (opCode == `PopR || opCode == `Ret)
        begin
          // Read value from stack
          readReq <= 1;
          ramAddress <= regarray[0] - 4;

          //$display("Requesting read from %h - 4", regarray[0]);
        end

        if (opCode == `MovdCR)
        begin
          // Write values to ram requested by instruction
          writeReq <= 1;
          ramAddress <= opDataWord;
          ramOut <= regValue2[0];

          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord);
        end

        if (opCode == `MovdRoR)
        begin
          // Write values to ram requested by instruction
          writeReq <= 1;
          ramAddress <= opDataWord + regValue[0];
          ramOut <= regValue2[0];

          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord + regValue[0]);
        end

        if (opCode == `MovdRoRR)
        begin
          // first register is base address, constant stores size of items, 
          // second register stores index of item, third register is destination, 
          writeReq <= 1;
          ramAddress <= regValue[0] + opDataWord * regValue2[0];
          ramOut <= regValue3[0];

          //$display("Reqesting write %h to address value %h", regValue2[0], regValue[0] + opDataWord * regValue2[0]);
        end

        if (opCode == `PushR)
        begin
          // Write register value to stack
          writeReq <= 1;
          ramAddress <= regarray[0];
          ramOut <= regValue[0];

          //$display("Reqesting push %h", regValue);
        end

        if (opCode == `CallR)
        begin
          // Write ip to stack
          writeReq <= 1;
          ramAddress <= regarray[0];
          ramOut <= ipointer;

          //$display("Reqesting push %h", regValue);
        end

        debug[23:0] <= opDataWord;
        debug[31:24] <= mode;

        mode <= 6;
      end

      // Mode 6 - ramIn is set by RAM module
      6: begin
        // Stop request
        readReq <= 0;
        writeReq <= 0;

        mode <= 7;

        debug[23:0] <= 0;
        debug[31:24] <= mode;
      end

      // Mode 7: Complete data read or write if the instruction
      //         requires it.
      7: begin
        if (opCode == `MovRdC || opCode == `MovRdRo || opCode == `MovRdRoR || opCode == `MovRdR || opCode == `PopR || opCode == `Ret)
        begin
          //$display("Receiving read address value %h", ramIn);

          // Store ram values requested
          ramValue <= ramIn;
        end

        mode <= 8;

        debug[23:0] <= ramIn[23:0];
        debug[31:24] <= mode;

      end

      // Mode 6: Finalize the instruction operation, by performing
      //         the writes that are needed and moving the
      //         instruction pointer along.
      8: begin
        // Now we can do writes to non-ram things
        case (opCode)
          `MovRC:    regarray[regAddress[7:0]] <= opDataWord;             // mov reg, const
          `MovRdC:   regarray[regAddress[7:0]] <= ramValue;               // mov reg, [addr]
          `MovRR:    regarray[regAddress[7:0]] <= regValue2[0];           // mov reg, reg
          `MovRdRo:  regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg + const]
          `MovRdRoR: regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg + const * reg]
          `MovRdR:   regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg]
          `MovdCR:   begin end // Done above
          `MovdRoR:  begin end // Done above
          `MovdRoRR: begin end // Done above

          `PushR: begin
            regarray[0] <= regarray[0] + 4;                             // push reg
          end

          `PopR: begin
            regarray[regAddress[7:0]] <= ramValue;                        // pop reg
            regarray[0] <= regarray[0] - 4;
          end

          `CallR: begin
            // Stack pointer increases like a push
            regarray[0] <= regarray[0] + 4;                             // call reg

            // Jump to the function
            ipointer <= regValue[0];

            //$display("Doing a call");
          end

          `Ret: begin
            // Stack pointer decreases like a pop
            regarray[0] <= regarray[0] - 4;                             // ret

            // Return to the saved position, after the call
            ipointer <= ramValue + 4;

            //$display("Doing a ret");
          end

          `RCallRC: begin
            // Store return address
            regarray[rPos + opDataWord] <= ipointer;

            // Store arg value
            regarray[rPos + opDataWord + 1] <= opDataWord;

            // Shift register window
            rPos <= rPos + opDataWord + 2;

            // Jump to the function
            ipointer <= regValue[0];

            //$display("Doing a register shift call to %h", regValue[0]);
          end

          `RRet: begin
            // Get the return address
            ipointer <= regarray[rPos - 2] + 8;

            // Get the window value
            rPos <= rPos - (regarray[rPos - 1] + 2);

            //$display("Doing an rret");
          end

          `CmpRR: begin                                                   // cmp reg, reg
            regarray[1][0:0] <= (regValue[0] == regValue2[0] ? 1 : 0);
            regarray[1][1:1] <= (regValue[0] < regValue2[0] ? 1 : 0);
            regarray[1][2:2] <= (regValue[0] > regValue2[0] ? 1 : 0);
          end

          `CmpRC: begin
            regarray[1][0:0] <= (regValue[0] == opDataWord ? 1 : 0);
            regarray[1][1:1] <= (regValue[0] < opDataWord ? 1 : 0);
            regarray[1][2:2] <= (regValue[0] > opDataWord ? 1 : 0);
          end

          `CmpERRR: begin                                                 // cmpe reg, reg, reg
            regarray[regAddress[7:0]] <= (regValue2[0] == regValue3[0] ? 1 : 0);
          end

          `CmpNeRRR: begin                                                 // cmpne reg, reg, reg
            regarray[regAddress[7:0]] <= (regValue2[0] != regValue3[0] ? 1 : 0);
          end

          `CmpLtRRR: begin                                                 // cmplt reg, reg, reg
            regarray[regAddress[7:0]] <= (regValue2[0] < regValue3[0] ? 1 : 0);
          end

          `CmpGtRRR: begin                                                 // cmpgt reg, reg, reg
            regarray[regAddress[7:0]] <= (regValue2[0] > regValue3[0] ? 1 : 0);
          end

          `JmpC:  ipointer <= opDataWord;                              // jmp address

          `JneC: begin end // Done above
          `JeC: begin end   // Done above
          `JzRC: begin end // Done above
          `JnzRC: begin end   // Done above

          `FaddRRR:    regarray[regAddress[7:0]] <= fAddResult[0];          // fadd reg, reg, reg
          `FsubRR:     regarray[regAddress[7:0]] <= fSubResult;             // fsub reg, reg
          `FconvR:     regarray[regAddress[7:0]] <= fConvResult;            // fconv reg
          `FmulRRR:    regarray[regAddress[7:0]] <= fMulResult;             // fmul reg, reg, reg
          `FdivRR:     regarray[regAddress[7:0]] <= fDivResult;
          `FmuladdRRR: regarray[regAddress[7:0]] <= fMulAddResult;          // fmul reg, reg
          `FminRR:     regarray[regAddress[7:0]] <= (fCompareResult == 'b01 ? regValue2[0] : regValue[0]);
          `FmaxRR:     regarray[regAddress[7:0]] <= (fCompareResult == 'b11 ? regValue2[0] : regValue[0]);

          `VfaddRRR: begin
            regarray[regAddress[7:0]] <= fAddResult[0];
            regarray[regAddress[7:0] + 1] <= fAddResult[1];
            regarray[regAddress[7:0] + 2] <= fAddResult[2];
            regarray[regAddress[7:0] + 3] <= fAddResult[3];
          end

          `AddRRC:     regarray[regAddress[7:0]] <= regValue2[0] + opDataWord;   // add reg, reg, const
          `AddRRR:     regarray[regAddress[7:0]] <= regValue2[0] + regValue3[0]; // add reg, reg, reg
          `SubRRC:     regarray[regAddress[7:0]] <= regValue2[0] - opDataWord;   // add reg, reg, const
          `SubRRR:     regarray[regAddress[7:0]] <= regValue2[0] - regValue3[0]; // add reg, reg, reg
          `IncR:       regarray[regAddress[7:0]] <= regValue[0] + 1;             // dec reg
          `DecR:       regarray[regAddress[7:0]] <= regValue[0] - 1;             // dec reg
          `ShlRRR:     regarray[regAddress[7:0]] <= regValue2[0] << regValue3[0];// shl reg, reg, reg
          `ShrRRR:     regarray[regAddress[7:0]] <= regValue2[0] >> regValue3[0];// shl reg, reg, reg
          `NegRR:      regarray[regAddress[7:0]] <= -regValue2[0];               // neg reg, reg

          `MulAddRRC:  regarray[regAddress[7:0]] <= regValue[0] + regValue2[0] * opDataWord;

          `DoutR: begin
            $display("DebugOut %h", regValue[0]);
          end

          `Stall: begin 
          end

          default: $display("Unknown instruction %h", opCode);
        endcase

        //$display("opDataWord == %h", opDataWord);

        debug[23:0] <= regAddress;
        debug[31:24] <= mode;

        // Move the instruction pointer along
        if (condJump == 1'b1)
        begin
          ipointer <= opDataWord;
        end
        else if (opCode != `JmpC &&
            opCode != `CallR &&
            opCode != `Ret &&
            opCode != `RCallRC &&
            opCode != `RRet &&
            opCode != `Stall
            )
        begin
          //$display("Incrementing ip");

          if (Is8ByteOpcode(opCode) == 1)
            ipointer <= ipointer + 8;
          else
            ipointer <= ipointer + 4;
        end

        //$display("Finished instruction %h", opCode);

        // Mode change
        mode <= 0;
      end

      endcase

      r0 <= regarray[rPos];
      r1 <= regarray[rPos + 1];
      r2 <= regarray[rPos + 2];
      r3 <= regarray[rPos + 3];
      r4 <= regarray[rPos + 4];
      r5 <= regarray[rPos + 5];
    end
  end

endmodule
