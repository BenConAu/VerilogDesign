module ALU(
  clk,         // [Input]  Clock driving the ALU
  reset,       // [Input]  Reset pin
  ramIn,       // [Input]  RAM at requested address
  readAck,     // [Input]  RAM read acknowledge
  writeAck,    // [Input]  RAM write acknowledge
  ramAddress,  // [Output] RAM address requested
  ramOut,      // [Output] RAM to write
  readReq,     // [Output] RAM read request
  writeReq,    // [Output] RAM write request
  ipointer,    // [Debug]  Instruction pointer value
  opCode,      // [Debug]  current opCode value
  r0,          // [Debug]  current r0 value
  r1,          // [Debug]  current r1 value
  debug        // [Output] Debug port
  );

  // Input / output
  input  wire        clk;
  input  wire        reset;
  input  wire [31:0] ramIn;
  input  wire        readAck;
  input  wire        writeAck;
  output reg [31:0]  ramAddress;
  output reg [31:0]  ramOut;
  output reg [0:0]   readReq;
  output reg [0:0]   writeReq;
  output reg [7:0]   ipointer;
  output reg [7:0]   opCode;
  output reg [31:0]  r0;
  output reg [31:0]  r1;
  output reg [31:0]  debug;

  // Local registers
  reg        [31:0] regarray[0:31];
  reg        [3:0]  mode;
  reg        [31:0] ramValue;
  reg        [31:0] regValue;
  reg        [31:0] regValue2;
  reg        [31:0] regValue3;
  reg        [31:0] opDataWord;
  reg        [7:0]  regAddress;
  reg        [7:0]  regAddress2;
  reg        [7:0]  regAddress3;
  reg        [4:0]  fOpEnable;
  
  // Wire up the results from the floating units
  wire       [31:0] fAddResult;
  wire       [31:0] fSubResult;
  wire       [31:0] fConvResult;
  wire       [31:0] fMulResult;
  wire       [31:0] fMulAddResult;
  wire       [31:0] floatDebug;

  FloatingAdd         fAdd(regValue, regValue2, 1'b0, fAddResult, floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd         fSub(regValue, regValue2, 1'b1, fSubResult, floatDebug, clk, fOpEnable[1:1]);
  FloatingFromInt     fConv(regValue, fConvResult, floatDebug, clk, fOpEnable[2:2]);
  FloatingMultiply    fMul(regValue, regValue2, fMulResult, floatDebug, clk, fOpEnable[3:3]);
  FloatingMultiplyAdd fMulAdd(regValue, regValue2, regValue3, fMulAddResult, floatDebug, clk, fOpEnable[4:4]);

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
      mode <= 0;
      readReq <= 0;
      fOpEnable <= 5'b00000;
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
        fOpEnable <= 5'b00000;
        mode <= 1;
      end

      // Mode 1: Handle ack of instruction pointer read request and
      //         decode the instruction data, including the opCode
      //         of the instruction and the affected registers.
      1: begin
        // Stop request
        readReq <= 0;

        // If ram is ready, read it and get the next instruction
        if (readAck)
        begin
          //$display("Receiving value %h", ramIn);

          opCode <= ramIn[7:0];
          regAddress <= ramIn[15:8];
          regAddress2 <= ramIn[23:16];
          regAddress3 <= ramIn[31:24];

          // Safe to move to next mode now
          mode <= 2;
        end

        debug[23:0] <= ramIn[23:0];
        debug[31:24] <= mode;
      end
        
      // Mode 2: Schedule read of additional code for opCodes that
      //         store word data. Read in register values for
      //         registers referenced by the instruction. 
      2: begin
        // Read values from registers
        regValue <= regarray[regAddress[3:0]];
        regValue2 <= regarray[regAddress2[3:0]];
        regValue3 <= regarray[regAddress3[3:0]];
  
        // Enable operation for module
        if (opCode == 20) fOpEnable[0:0] <= 1;
        if (opCode == 21) fOpEnable[1:1] <= 1;
        if (opCode == 22) fOpEnable[2:2] <= 1;
        if (opCode == 23) fOpEnable[3:3] <= 1;
        if (opCode == 24) fOpEnable[4:4] <= 1;

        if (opCode == 1 || opCode == 2 || opCode == 4 || opCode == 6)
        begin
          // Read values from ram requested by instruction
          readReq <= 1;
          ramAddress <= ipointer + 4;

          // We need to move into further modes
          mode <= 3;
        end
        else
        begin
          // Since there is no word data, there is no need
          // to wait for that word data to come back, and there
          // can be no further reads or writes since the word
          // data is where the address would go
          mode <= 6;
        end

        debug[23:0] <= regAddress;
        debug[31:24] <= mode;
      end

      // Mode 3: Complete read of additional code for opCodes that
      //         store word data. We only end up in this mode if
      //         the appropriate opCode is set, so no need to check
      //         the opCode.
      3: begin
        // Stop request
        readReq <= 0;
  
        if (readAck == 1)
        begin
          // Store ram values requested
          opDataWord <= ramIn;

          // Move to next mode - only progress to data read / write
          // for opCodes that actually need it.
          if (opCode == 2 || opCode == 4)
            mode <= 4;
          else
            mode <= 6;
        end

        debug[23:0] <= ramIn;
        debug[31:24] <= mode;
      end
  
      // Mode 4: Initiate data read or write if the instruction
      //         requires it.
      4: begin
        if (opCode == 2)
        begin
          // Read values from address encoded in code
          readReq <= 1;
          ramAddress <= opDataWord;        
        end

        if (opCode == 4)
        begin
          // Write values to ram requested by instruction
          writeReq <= 1;
          ramAddress <= opDataWord;
          ramOut <= regValue2;
        end

        debug[23:0] <= opDataWord;
        debug[31:24] <= mode;

        mode <= 5;
      end

      // Mode 5: Complete data read or write if the instruction
      //         requires it.
      5: begin
        if (opCode == 2)
        begin
          // Stop request
          readReq <= 0;
  
          if (readAck)
          begin
            $display("Receiving read address value %h", ramIn);

            // Store ram values requested
            ramValue <= ramIn;

            // Now we can move on
            mode <= 6;
          end
        end
        else if (opCode == 4)
        begin
          // Stop request
          writeReq <= 0;

          if (writeAck == 1)
          begin
            // Can move to next mode
            mode <= 6;
          end
        end
        else
          mode <= 6;

        debug[23:0] <= ramIn[23:0];
        debug[31:24] <= mode;

      end

      // Mode 6: Finalize the instruction operation, by performing
      //         the writes that are needed and moving the
      //         instruction pointer along.
      6: begin
        // Now we can do writes to non-ram things
        case (opCode)
          1:  regarray[regAddress[3:0]] <= opDataWord;             // mov reg, const
          2:  regarray[regAddress[3:0]] <= ramValue;               // mov reg, [addr]
          3:  regarray[regAddress[3:0]] <= regValue2;              // mov reg, reg

          // 4 is done above
          
          5: begin                                                 // cmp reg, reg
            regarray[31][0:0] <= (regValue == regValue2 ? 1 : 0);
            regarray[31][1:1] <= (regValue < regValue2 ? 1 : 0);
            regarray[31][2:2] <= (regValue > regValue2 ? 1 : 0);
          end
          
          6:  ipointer <= opDataWord;                              // jmp address
          10: regarray[regAddress[3:0]] <= regValue + regValue2;   // add reg, reg
  
          20: regarray[regAddress[3:0]] <= fAddResult;             // fadd reg, reg
          21: regarray[regAddress[3:0]] <= fSubResult;             // fsub reg, reg
          22: regarray[regAddress[3:0]] <= fConvResult;            // fconv reg
          23: regarray[regAddress[3:0]] <= fMulResult;             // fmul reg, reg
          24: regarray[regAddress[3:0]] <= fMulAddResult;          // fmul reg, reg
  
          30: debug <= regValue;                                   // setdebug reg
        endcase
  
        debug[23:0] <= regAddress;
        debug[31:24] <= mode;

        // Move the instruction pointer along
        if (opCode != 6)
        begin
          if (opCode == 1 || opCode == 2 || opCode == 4)
            ipointer <= ipointer + 8;
          else
            ipointer <= ipointer + 4;
        end
  
        $display("Finished instruction %h", opCode);

        // Mode change
        mode <= 0;      
      end

      endcase
  
      r0 <= regarray[0];
      r1 <= regarray[1];
    end
  end

endmodule