module ALU(
  clk,            // [Input]  Clock driving the ALU
  reset,          // [Input]  Reset pin
  ramIn,          // [Input]  RAM at requested address
  ramReady,       // [Input]  RAM ready signal
  ramAddress,     // [Output] RAM address requested
  ramOut,         // [Output] RAM to write
  readReq,        // [Output] RAM read request
  writeReq,       // [Output] RAM write request
  addrVirtual,    // [Output] Virtual flag for RAM
  ptAddress,      // [Output] Page Table Address
  uartReadReq,    // [Output] uart read requested
  uartReadAck,    // [Input]  Flag to indicate read success
  uartReadData,   // [Input]  Actual data read 
  uartWriteReq,   // [Output] uart write requested
  uartWriteData,  // [Output] uart data to write
  uartWriteReady, // [Input]  uart ready to send
  ipointer,       // [Debug]  Instruction pointer value
  opCode,         // [Debug]  current opCode value
  r0,             // [Debug]  current r0 value
  r1,             // [Debug]  current r1 value
  r2,             // [Debug]  current r2 value
  r3,             // [Debug]  current r3 value
  r4,             // [Debug]  current r4 value
  r5,             // [Debug]  current r5 value
  rPos,           // [Debug]  current rPos (register window) value
  debug,          // [Output] Debug port
  debug2,         // [Output] Another debug port
  debug3          // [Output] And yet another debug port
  );

  `include "../PhaethonISA/Generated/PhaethonOpCode.v"

  // Make modes easier to read and to insert new ones
  `define InitialMode 0
  `define InstrReadComplete 1
  `define RegValueSet 2
  `define DataWordComplete 3
  `define RWRequest 4
  `define MemRWComplete 5
  `define IORWWait 6
  `define IORWComplete 7
  `define MemRWComplete 8
  `define ProcessOpCode 9  

  // Input / output
  input  wire        clk;
  input  wire        reset;
  input  wire [31:0] ramIn;
  input  wire [0:0]  ramReady;
  output reg [31:0]  ramAddress;
  output reg [31:0]  ramOut;
  output reg [0:0]   readReq;
  output reg [0:0]   writeReq;
  output reg [0:0]   addrVirtual;
  output reg [31:0]  ptAddress;
  output reg [0:0]   uartReadReq;
  input  wire [0:0]  uartReadAck;
  input  wire [7:0]  uartReadData;
  output reg         uartWriteReq;
  output reg [7:0]   uartWriteData;
  input wire         uartWriteReady;
  output reg [31:0]  ipointer;
  output reg [7:0]   opCode;
  output reg [31:0]  r0;
  output reg [31:0]  r1;
  output reg [31:0]  r2;
  output reg [31:0]  r3;
  output reg [31:0]  r4;
  output reg [31:0]  r5;
  output reg [31:0]  debug;
  output reg [31:0]  debug2;
  output reg [8:0]   debug3;
  output reg [7:0]   rPos;

  // Local registers that need initialization
  reg        [7:0]  mode = `InitialMode;
  reg        [31:0] counter = 0;
  reg               initComplete = 1'b0;
  
  `define StackPointerReg 0
  `define FlagsReg 1
  `define CodeSegmentReg 2
  `define CodeReturnReg 3
  `define PageTableReg 4
  `define FixedRegCount 5

  // Other local registers that are initialized elsewhere
  reg        [31:0] regarray[0:(63 + `FixedRegCount)];
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
  reg        [0:0]  inExec;
  reg        [31:0] sentinel;

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

  wire       [31:0] dbgBufDbg1;
  wire       [31:0] dbgBufDbg2;
  reg        [0:0]  dbgBufferWriteReq;
  reg        [31:0] dbgBufferWriteData;
  wire       [31:0] dbgBufferReadData;
  wire       [0:0]  dbgBufferReadComplete;
  reg        [0:0]  dbgBufferReadReq;
  wire       [31:0] dbgBufferLength;

  RingBuffer #(32, 5) debugBuffer(
    clk,                    // Global clock
    reset,                  // Reset
    dbgBufferWriteReq,      // Flag to indicate request to write
    dbgBufferWriteData,     // Data to write
    dbgBufferReadReq,       // Flag to indicate request to read
    dbgBufferReadComplete,  // Flag to indicate read success
    dbgBufferReadData,      // Actual data read
    dbgBufferLength,        // Buffer length
    dbgBufDbg1,             // Debug1
    dbgBufDbg2              // Debug2
  );

  //initial
     //$monitor("%t, ram = %h, %h, %h, %h : %h, %h, %h, %h",
       //$time, ramIn[7:0], ramIn[15:8], ramIn[23:16], ramIn[31:24], ramAddress, ramIn, opAddress, ramValue);

  //`define SLOWCLOCK 1
  
  always @(posedge clk or posedge reset)
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
      mode <= `InitialMode;
      initComplete <= 1'b0;
    end
    else
    begin
      // Regular code starts here
      case (mode)
      // Mode InitialMode: Schedule read of code at instruction pointer and clear
      //         out enable bits for auxillary modules.
      `InitialMode: begin
        if (initComplete == 1'b0)
        begin
          // We initialize most stuff here because it can be done once
          // here and work both with the reset input and with an initializer
          // for the registers.
          debug <= 0;
          debug2 <= 0;
          debug3 <= 1;
          
          writeReq <= 0;
          uartReadReq <= 0;
          readReq <= 0;
          opDataWord <= 'hffffffff;
          opCode <= 0;
          fOpEnable <= 7'b0000000;
          ipointer <= 0;
          condJump <= 1'b0;
          dbgBufferWriteReq <= 1'b0;
          dbgBufferReadReq <= 1'b0;
          inExec <= 1'b0;
          addrVirtual <= 1'b0;

          // First real register position
          rPos <= `FixedRegCount;

          // Some stuff is hard to do with initializers, so we do it here
          regarray[`StackPointerReg] <= 0;
          regarray[`FlagsReg] <= 0;
          regarray[`CodeSegmentReg] <= 0; // Code segment

          // Mark initialization as complete
          initComplete <= 1'b1;

          // Mode won't change, so next clock we will be back but skip init
        end
        else
        begin
          // Begin RAM read for instruction data
          readReq <= 1;
          ramAddress <= ipointer + regarray[`CodeSegmentReg];
          opDataWord <= 'h0badf00d;

          // Clear out stuff for the pipeline
          fOpEnable <= 7'b0000000;
          condJump <= 1'b0;
          mode <= `InstrReadComplete;
        end
      end

      // Mode InstrReadComplete: Handle completion of instruction pointer read request and
      //         decode the instruction data, including the opCode
      //         of the instruction and the affected registers.
      `InstrReadComplete: begin
        // Stop request
        readReq <= 0;

        if (ramReady == 1)
        begin
          // If ramReady is high then we have received something
          //$display("Receiving value %h from MemoryController", ramIn);

          opCode <= ramIn[7:0];
          regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
          regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
          regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);

          // Move to next mode now
          mode <= `RegValueSet;
        end
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
        if (opCode == `JneC && regarray[`FlagsReg][0:0] == 1'b0) condJump <= 1'b1;
        if (opCode == `JeC && regarray[`FlagsReg][0:0] == 1'b1) condJump <= 1'b1;
        if (opCode == `JzRC && regarray[regAddress[7:0]] == 0) condJump <= 1'b1;
        if (opCode == `JnzRC && regarray[regAddress[7:0]] != 0) condJump <= 1'b1;

        if (Is8ByteOpcode(opCode) == 1)
        begin
          // Read values from ram requested by instruction
          readReq <= 1;
          ramAddress <= ipointer + regarray[`CodeSegmentReg] + 4;

          // We need to move into further modes
          mode <= `DataWordComplete;
        end
        else if (IsRAMOpcode(opCode) == 1|| IsIOOpcode(opCode) == 1)
        begin
          // We are not reading a constant, but we might still be
          // doing a RAM operation, move into the mode where we do that
          mode <= `RWRequest;
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

      // Mode DataWordComplete: Complete read of additional code for opCodes that
      //         store word data. We only end up in this mode if
      //         the appropriate opCode is set, so no need to check
      //         the opCode.
      `DataWordComplete: begin
        // Stop request
        readReq <= 0;

        if (ramReady == 1)
        begin
          //$display("DataWordComplete with word %h", ramIn);

          // Store ram values requested
          opDataWord <= ramIn;

          // Move to next mode - only progress to data read / write
          // for opCodes that actually need it.
          if (IsRAMOpcode(opCode) == 1 || IsIOOpcode(opCode) == 1)
          begin
            //$display("DataWordComplete getting another RW %h", opCode);
            mode <= `RWRequest;
          end
          else
          begin
            //$display("DataWordComplete processing an OpCode %h", opCode);
            mode <= `ProcessOpCode;
          end
        end
      end

      `RWRequest: begin
        if (IsRAMOpcode(opCode) == 1)
        begin
          //$display("RWRequest for RAM opcode");

          case (opCode)
            `MovRdC: begin
              // Read values from address encoded in code
              readReq <= 1;
              ramAddress <= opDataWord + regarray[`CodeSegmentReg];

              //$display("Requesting RdC read from %h", opDataWord);
            end

            `MovRdRo: begin
              // First register is destination, second register is base address, 
              // constant stores offset in bytes.
              readReq <= 1;
              ramAddress <= opDataWord + regValue2[0] + regarray[`CodeSegmentReg];

              //$display("Requesting read from %h", opDataWord + regValue2);
            end

            `MovRdRoR: begin
              // First register is destination, second register is base address, 
              // constant stores size of item, and third register stores index of item.
              readReq <= 1;
              ramAddress <= regValue2[0] + opDataWord * regValue3[0] + regarray[`CodeSegmentReg];

              //$display("Requesting read from %h", regValue2[0] + opDataWord * regValue3[0]);
            end

            `MovRdR: begin
              // Read values from address encoded in code
              readReq <= 1;
              ramAddress <= regValue2[0] + regarray[`CodeSegmentReg];

              //$display("Requesting read from %h", opDataWord + regValue2);
            end

            `PopR: begin
              // Read value from stack
              readReq <= 1;
              ramAddress <= regarray[`StackPointerReg] - 4;

              //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
            end

            `Ret: begin
              // Read value from stack
              readReq <= 1;
              ramAddress <= regarray[`StackPointerReg] - 4;
            
              //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
            end
          
            `MovdCR: begin
              // Write values to ram requested by instruction
              writeReq <= 1;
              ramAddress <= opDataWord + regarray[`CodeSegmentReg];
              ramOut <= regValue2[0];
            
              //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord);
            end

            `MovdRoR: begin
              // Write values to ram requested by instruction
              writeReq <= 1;
              ramAddress <= opDataWord + regValue[0] + regarray[`CodeSegmentReg];
              ramOut <= regValue2[0];
            
              //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord + regValue[0]);
            end
          
            `MovdRoRR: begin
              // first register is base address, constant stores size of items, 
              // second register stores index of item, third register is destination, 
              writeReq <= 1;
              ramAddress <= regValue[0] + opDataWord * regValue2[0] + regarray[`CodeSegmentReg];
              ramOut <= regValue3[0];
            
              //$display("Reqesting write %h to address value %h", regValue2[0], regValue[0] + opDataWord * regValue2[0]);
            end

            `PushR: begin
              // Write register value to stack
              writeReq <= 1;
              ramAddress <= regarray[`StackPointerReg];
              ramOut <= regValue[0];
            
              //$display("Reqesting push %h", regValue);
            end
          
            `CallR: begin
              // Write ip to stack
              writeReq <= 1;
              ramAddress <= regarray[`StackPointerReg];
              ramOut <= ipointer;
            
              //$display("Reqesting push %h", regValue);
            end
          endcase

          mode <= `MemRWComplete;
        end
        else if (IsIOOpcode(opCode) == 1)
        begin
          //$display("IO opcode");

          // Stop request
          readReq <= 0;

          case (opCode)
            `ReadPortRR: begin
              case (regValue2[0])
                1: begin
                  // Port 1 is read from UART
                  uartReadReq <= 1;
                end
            
                2: begin
                  // Port 2 is UART write ready status
                end
            
                default: begin
                  $display("Unknown port %h being read", regValue[0]);
                end
              endcase
            end

            `WritePortRR: begin
              uartWriteReq <= 1;
              uartWriteData <= regValue2[0][7:0];
            end

            `DoutR: begin
              //$display("DoutR write req");

              dbgBufferWriteReq <= 1;
              dbgBufferWriteData <= regValue[0];
            end

            `DinR: begin
              dbgBufferReadReq <= 1;
            end
          endcase

          mode <= `IORWWait;
        end
      end

      `IORWWait: begin
        uartReadReq <= 1'b0;
        uartWriteReq <= 1'b0;
        dbgBufferWriteReq <= 1'b0;
        dbgBufferReadReq <= 1'b0;

        mode <= `IORWComplete;
      end

      // Mode MemRWComplete: Complete data read or write if the instruction
      //         requires it.
      `MemRWComplete: begin
        // Stop request
        readReq <= 1'b0;
        writeReq <= 1'b0;

        if (ramReady == 1)
        begin
          if (opCode == `MovRdC || opCode == `MovRdRo || opCode == `MovRdRoR || opCode == `MovRdR || opCode == `PopR || opCode == `Ret)
          begin
            //$display("Receiving read address value %h", ramIn);

            // Store ram values requested
            ramValue <= ramIn;
          end
  
          mode <= `ProcessOpCode;
        end

      end

      `IORWComplete: begin
        if (opCode == `ReadPortRR)
        begin
          case (regValue2[0])

          1: begin
            // Read from UART is now complete, return
            if (uartReadAck == 1'b1)
            begin
              ramValue[7:0] <= uartReadData;
              ramValue[31:8] <= 1;
            end
            else
            begin
              // Sorry, no value for you
              ramValue <= 0;
            end
          end

          2: begin
            // Port 2 is UART write ready status
            begin
              ramValue[0:0] <= uartWriteReady;
              ramValue[31:1] <= 0;
            end
          end

          default: begin
            $display("Unknown port %h being read", regValue[0]);
          end

          endcase
        end
        else if (opCode == `DinR)
        begin
          ramValue <= dbgBufferReadData;
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

          `PackRRR: begin
            case (regValue3[0][1:0])
              0: regarray[regAddress[7:0]][7:0] <= regValue2[0][7:0];
              1: regarray[regAddress[7:0]][15:8] <= regValue2[0][7:0];
              2: regarray[regAddress[7:0]][23:16] <= regValue2[0][7:0];
              3: regarray[regAddress[7:0]][31:24] <= regValue2[0][7:0];
              default: begin
                $display("Out of range byte position");
              end
            endcase
          end

          `MovRdRo:  regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg + const]
          `MovRdRoR: regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg + const * reg]
          `MovRdR:   regarray[regAddress[7:0]] <= ramValue;               // mov reg, [reg]
          `MovdCR:   begin end // Done above
          `MovdRoR:  begin end // Done above
          `MovdRoRR: begin end // Done above

          `LeaRRoR: begin
            //$display("Doing lea with opDataWord %h", opDataWord);
            regarray[regAddress[7:0]] <= regValue2[0] + opDataWord * regValue3[0] + regarray[`CodeSegmentReg];
          end

          `ReadPortRR: regarray[regAddress[7:0]] <= ramValue;             // ReadPort reg, reg
          `WritePortRR: begin end // Done above

          `PushR: begin
            regarray[`StackPointerReg] <= regarray[`StackPointerReg] + 4;                             // push reg
          end

          `PopR: begin
            regarray[regAddress[7:0]] <= ramValue;                        // pop reg
            regarray[`StackPointerReg] <= regarray[`StackPointerReg] - 4;
          end

          `CallR: begin
            // Stack pointer increases like a push
            regarray[`StackPointerReg] <= regarray[`StackPointerReg] + 4;                             // call reg

            // Jump to the function
            ipointer <= regValue[0];
            debug3 <= 3;

            //$display("Doing a call");
          end

          `Ret: begin
            // Stack pointer decreases like a pop
            regarray[`StackPointerReg] <= regarray[`StackPointerReg] - 4;                             // ret

            // Return to the saved position, after the call
            ipointer <= ramValue + 4;
            debug3 <= 4;

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
            debug3 <= 5;

            //$display("Doing a register shift call to %h", regValue[0]);
          end

          `RRet: begin
            // Get the return address
            ipointer <= regarray[rPos - 2] + 8;
            debug3 <= 6;

            // Get the window value
            rPos <= rPos - (regarray[rPos - 1] + 2);

            //$display("Doing an rret");
          end

          `CmpRR: begin                                                   // cmp reg, reg
            regarray[`FlagsReg][0:0] <= (regValue[0] == regValue2[0] ? 1 : 0);
            regarray[`FlagsReg][1:1] <= (regValue[0] < regValue2[0] ? 1 : 0);
            regarray[`FlagsReg][2:2] <= (regValue[0] > regValue2[0] ? 1 : 0);
          end

          `CmpRC: begin
            regarray[`FlagsReg][0:0] <= (regValue[0] == opDataWord ? 1 : 0);
            regarray[`FlagsReg][1:1] <= (regValue[0] < opDataWord ? 1 : 0);
            regarray[`FlagsReg][2:2] <= (regValue[0] > opDataWord ? 1 : 0);
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

          `JmpC: begin  
            ipointer <= opDataWord;                              // jmp address
            debug3 <= 7;
          end

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

          `ExecR: begin
            if (inExec == 1'b0)
            begin
              // This basically sets the code segment register
              regarray[`CodeSegmentReg] <= regValue[0];

              // Also set where to go when it returns (the next instruction)
              regarray[`CodeReturnReg] <= ipointer + 4;

              // IP is reset to zero
              ipointer <= 0;

              // We are in an exec now
              inExec <= 1'b1;
            end
          end

          `Exit: begin
            // If we are not in an exec this will stall because the IP
            // will not change at all.
            if (inExec == 1'b1)
            begin
              // Return control by clearing code segment
              regarray[`CodeSegmentReg] <= 0;

              // Set IP back to where we need it to be
              ipointer <= regarray[`CodeReturnReg];

              // We are out of an exec now
              inExec <= 1'b0;
            end
          end

          `DoutR: begin
            // In simulation we use $display for this
            $display("DebugOut %h", regValue[0]);
      
            // FPGA we hit the 7seg display with the value
            debug <= regValue[0];
          end

          `DinR: begin
            regarray[regAddress[7:0]] <= ramValue;
          end

          `DlenR: begin
            regarray[regAddress[7:0]] <= dbgBufferLength;
          end

          `VpEnable: begin
            addrVirtual <= 1;
          end

          default: $display("Unknown instruction %h", opCode);
        endcase

        //$display("opDataWord == %h", opDataWord);


        // Move the instruction pointer along
        if (condJump == 1'b1)
        begin
          ipointer <= opDataWord;
          debug3 <= 8;
        end
        else if (opCode != `JmpC &&
            opCode != `CallR &&
            opCode != `Ret &&
            opCode != `RCallRC &&
            opCode != `RRet &&
            opCode != `ExecR &&
            opCode != `Exit
            )
        begin
          //$display("Incrementing ip");

          if (Is8ByteOpcode(opCode) == 1)
          begin
            ipointer <= ipointer + 8;
            debug3 <= 9;
          end
          else
          begin
            ipointer <= ipointer + 4;
            debug3 <= 10;
          end
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
    //debug3[8:0] <= mode;
    //debug2[7:0] <= mode;
    //debug2[15:8] <= opCode;
    debug2[11:0] <= ipointer;
    debug2[31:12] <= opCode;
    
    end
  end

endmodule
