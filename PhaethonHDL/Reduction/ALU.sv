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
  debug,       // [Output] Debug port
  debug2,      // [Output] Another debug port
  debug3       // [Output] And yet another debug port
  );

  `include "../../PhaethonISA/Generated/PhaethonOpCode.v"

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
  output reg [17:0]  debug2;
  output reg [8:0]   debug3;
  output reg [7:0]   rPos;

  // Local registers
  reg        [31:0] regarray[0:65];
  reg        [7:0]  mode;
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
  reg        [31:0] sentinel;
  reg        [31:0] counter;

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

  `define InitialMode 0
  `define InstrReadWait 1
  `define InstrReadComplete 2
  `define RegValueSet 3
  `define DataWordWait 4
  `define DataWordComplete 5
  `define MemRWRequest 6
  `define MemRWWait 7
  `define MemRWComplete 8
  `define ProcessOpCode 9
  
  always @(posedge clk)
  begin
    `ifdef SLOWCLOCK
  
    // Use a counter to artificially slow the clock
    if (counter != 5000000)
    begin  
      counter <= counter + 1;
    end
    else
    begin
      counter <= 0;
  
    `endif
  
    // Regular code starts here
    if (reset == 'b1)
      begin
        ipointer <= 0;
        opCode <= 0;
        opDataWord <= 'hffffffff;
        rPos <= 2;
        mode <= `InitialMode;
        readReq <= 0;
        writeReq <= 0;
        fOpEnable <= 7'b0000000;
        condJump <= 1'b0;
      end
      else
      begin
  
      // Regular code starts here
      case (mode)
        // Mode InitialMode: Schedule read of code at instruction pointer and clear
        // out enable bits for auxillary modules.
        `InitialMode: begin
        if (sentinel == 'h12345678)
        begin
          // Begin RAM read for instruction data
          readReq <= 1;
          ramAddress <= ipointer;
          opDataWord <= 'h0badf00d;
    
          mode <= `InstrReadWait;
      
        end
        else
        begin
          // This should only run on first power
          ipointer <= 0;
          opCode <= 0;
          rPos <= 2;
          mode <= `InitialMode;
          readReq <= 0;
          sentinel <= 'h12345678;
          debug <= 0;
          fOpEnable <= 7'b0000000;
          condJump <= 1'b0;
          debug2 <= 0;
    
          // We will come back here on next clock
        end
      end
    
      // Mode InstrReadWait - wait while RAM registers address
      `InstrReadWait: begin
        mode <= `InstrReadComplete;
    
      end
  
      // Mode InstrReadComplete: Handle completion of instruction pointer read request and
      //         decode the instruction data, including the opCode
      //         of the instruction and the affected registers.
      `InstrReadComplete: begin
      
        // Stop request
        //readReq <= 0;
  
        opCode <= ramIn[7:0];
        regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
        regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
        regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);
    
        // Move to next mode now
        mode <= `RegValueSet;
      end
  
      // Mode RegValueSet: Schedule read of additional code for opCodes that
      //         store word data. Read in register values for
      //         registers referenced by the instruction.
      `RegValueSet: begin
  
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
          mode <= `DataWordWait;
        end
        else if (IsRAMOpcode(opCode) == 1)
        begin
          // We are not reading a constant, but we might still be
          // doing a RAM operation, move into the mode where we do that
          mode <= `MemRWRequest;
        end
        else
        begin
          // Since there is no word data, there is no need
          // to wait for that word data to come back, and there
          // can be no further reads or writes since the word
          // data is where the address would go
          mode <= `ProcessOpCode;
        end
      end
  
      // Mode DataWordWait - ramIn is set by RAM module for second word
      `DataWordWait: begin
        // Stop request
        readReq <= 0;
  
        mode <= `DataWordComplete;
      end
  
      // Mode DataWordComplete: Complete read of additional code for opCodes that
      //         store word data. We only end up in this mode if
      //         the appropriate opCode is set, so no need to check
      //         the opCode.
      `DataWordComplete: begin
        // Stop request
        readReq <= 0;
  
        // Store ram values requested
        opDataWord <= ramIn;
  
        // Move to next mode - only progress to data read / write
        // for opCodes that actually need it.
        if (IsRAMOpcode(opCode) == 1)
          mode <= `MemRWRequest;
        else
          mode <= `ProcessOpCode;
      end
  
      // Mode MemRWRequest: Initiate data read or write if the instruction
      //         requires it.
      `MemRWRequest: begin
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
  
        mode <= `MemRWWait;
      end
  
      // Mode `MemRWWait - ramIn is set by RAM module
      `MemRWWait: begin
        // Stop request
        readReq <= 0;
        writeReq <= 0;
  
        mode <= `MemRWComplete;
      end
  
      // Mode MemRWComplete: Complete data read or write if the instruction
      //         requires it.
      `MemRWComplete: begin
        if (opCode == `MovRdC || opCode == `MovRdRo || opCode == `MovRdRoR || opCode == `MovRdR || opCode == `PopR || opCode == `Ret)
        begin
          //$display("Receiving read address value %h", ramIn);
  
          // Store ram values requested
          ramValue <= ramIn;
        end
  
        mode <= `ProcessOpCode;
  
      end
    
      // Mode ProcessOpCode: Finalize the instruction operation, by performing
      //         the writes that are needed and moving the
      //         instruction pointer along.
      `ProcessOpCode: begin
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
            // In simulation we use $display for this
            $display("DebugOut %h", regValue[0]);
      
            // FPGA we hit the 7seg display with the value
            debug <= regValue[0];
          end
  
          `Stall: begin 
          end
  
          default: $display("Unknown instruction %h", opCode);
        endcase
          //$display("opDataWord == %h", opDataWord);
  
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
        mode <= `InitialMode; 
      end
  
      default: begin
      end
  
      endcase
    
    `ifdef SLOWCLOCK
    end
    `endif

    r0 <= regarray[rPos];
    r1 <= regarray[rPos + 1];
    r2 <= regarray[rPos + 2];
    r3 <= regarray[rPos + 3];
    r4 <= regarray[rPos + 4];
    r5 <= regarray[rPos + 5];
  
    debug3[8:0] <= mode;
    debug2 <= regarray[rPos];
	 
	 end
  end

endmodule
