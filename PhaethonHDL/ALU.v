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
  output reg [7:0]   ramAddress;
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
  reg        [2:0]  mode;
  reg        [31:0] ramValue;
  reg        [31:0] regValue;
  reg        [31:0] regValue2;
  reg        [31:0] regValue3;
  reg        [15:0] opAddress;
  reg        [7:0]  regAddress;
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
      opAddress <= 'hffff;
      mode <= 0;
      readReq <= 0;
      fOpEnable <= 5'b00000;
    end
    else
    begin
      case (mode)
      0: begin
        // Begin RAM read for instruction data
        readReq <= 1;
        ramAddress <= ipointer;
        
        debug[23:0] <= ipointer;
        debug[31:24] <= mode;

        // Clear out stuff for the pipeline 
        fOpEnable <= 5'b00000;
        mode <= 1;
      end

      1: begin
        // If ram is ready, read it and get the next instruction
        if (readAck)
        begin
          // Stop request
          readReq <= 0;

          opCode <= ramIn[7:0];
          regAddress <= ramIn[15:8];
          opAddress[7 : 0] <= ramIn[23:16];
          opAddress[15 : 8] <= ramIn[31:24];

          debug[23:0] <= ramIn[7:0];
          debug[31:24] <= mode;

          // Safe to move to next mode now
          mode <= 2;
        end
      end
        
      2: begin
        // Read values from ram requested by instruction
        readReq <= 1;
        ramAddress <= opAddress;

        // Read values from registers
        regValue <= regarray[regAddress[3:0]];
        regValue2 <= regarray[opAddress[3:0]];
        regValue3 <= regarray[opAddress[11:8]];
  
        debug[23:0] <= opCode;
        debug[31:24] <= mode;

        // Move to next mode        
        mode <= 3;
      end

      3: begin
        if (readAck)
        begin
          // Stop request
          readReq <= 0;

          // Store ram values requested
          ramValue[7:0] <= ramIn[7:0];
          ramValue[15:8] <= ramIn[15:8];
          ramValue[23:16] <= ramIn[23:16];
          ramValue[31:24] <= ramIn[31:24];
  
          debug[23:0] <= ramIn[7:0];
          debug[31:24] <= mode;

          // Enable operation for module
          if (opCode == 20) fOpEnable[0:0] <= 1;
          if (opCode == 21) fOpEnable[1:1] <= 1;
          if (opCode == 22) fOpEnable[2:2] <= 1;
          if (opCode == 23) fOpEnable[3:3] <= 1;
          if (opCode == 24) fOpEnable[4:4] <= 1;

          // Mode change
          if (opCode == 4)
            mode <= 4; // Need to write ram
          else
            mode <= 6; // Skip ahead, no ram write needed
        end
      end
  
      4: begin
        // Write values to ram requested by instruction
        writeReq <= 1;
        ramAddress <= opAddress;

        // Store ram values requested
        ramOut[7:0] <= regValue[7:0];
        ramOut[15:8] <= regValue[15:8];
        ramOut[23:16] <= regValue[23:16];
        ramOut[31:24] <= regValue[31:24];

        debug[23:0] <= opAddress;
        debug[31:24] <= mode;

        // Move to next mode        
        mode <= 5;        
      end

      5: begin
        if (writeAck == 1)
        begin
          // Stop request
          writeReq <= 0;
          
          debug[23:0] <= opAddress;
          debug[31:24] <= mode;

          // Now you can move along
          mode <= 6;
        end
      end

      6: begin
        // Now we can do writes to non-ram things
        case (opCode)
          1:  regarray[regAddress[3:0]] <= opAddress;              // mov reg, const
          2:  regarray[regAddress[3:0]] <= ramValue;               // mov reg, [addr]
          3:  regarray[regAddress[3:0]] <= regValue2;              // mov reg, reg
          // 4 is done above
          5: begin                                                 // cmp reg, reg
            regarray[31][0:0] <= (regValue == regValue2 ? 1 : 0);
            regarray[31][1:1] <= (regValue < regValue2 ? 1 : 0);
            regarray[31][2:2] <= (regValue > regValue2 ? 1 : 0);
          end
          6:  ipointer <= opAddress;                               // jmp address
          10: regarray[regAddress[3:0]] <= regValue + regValue2;   // add reg, reg
  
          20: regarray[regAddress[3:0]] <= fAddResult;             // fadd reg, reg
          21: regarray[regAddress[3:0]] <= fSubResult;             // fsub reg, reg
          22: regarray[regAddress[3:0]] <= fConvResult;            // fconv reg
          23: regarray[regAddress[3:0]] <= fMulResult;             // fmul reg, reg
          24: regarray[regAddress[3:0]] <= fMulAddResult;          // fmul reg, reg
  
          30: debug <= regValue;                                   // setdebug reg
        endcase
  
        //debug <= floatDebug;

        // Move the instruction pointer along
        if (opCode != 6)
          ipointer <= ipointer + 4;
  
        // Mode change
        mode <= 0;      
      end

      endcase
  
      r0 <= regarray[0];
      r1 <= regarray[1];
    end
  end

endmodule