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
  runningTotal // [Output] Running total of instruction RAM
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
  output reg [7:0]   rPos;
  output reg [31:0]  runningTotal;

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
    case (mode)
      // Mode InitialMode: Schedule read of code at instruction pointer and clear
    //         out enable bits for auxillary modules.
      `InitialMode: begin
      if (sentinel == 'h12345678)
      begin
        // Begin RAM read for instruction data
        readReq <= 1;
        ramAddress <= (ipointer / 4);

        debug[23:0] <= ipointer;
        debug[31:24] <= mode;

        debug2 <= 1;

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
        runningTotal <= 0;
        fOpEnable <= 7'b0000000;
        condJump <= 1'b0;
        debug2 <= 0;

        // We will come back here on next clock
      end
    end

    // Mode InstrReadWait - wait while RAM registers address
    `InstrReadWait: begin
      mode <= `InstrReadComplete;

      debug[23:0] <= 0;
      debug[31:24] <= mode;

      debug2 <= 2;
   		
		end
	 
    // Mode InstrReadComplete: Handle completion of instruction pointer read request and
    //         decode the instruction data, including the opCode
    //         of the instruction and the affected registers.
    `InstrReadComplete: begin
      debug2 <= 3;
    
      // Stop request
      //readReq <= 0;

      opCode <= ramIn[7:0];
      regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
      regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
      regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);
    
      regValue[0] <= ramIn;
      runningTotal <= ramIn;

      // Move to next mode now
      mode <= `RegValueSet;

      debug[23:0] <= ramIn[23:0];
      debug[31:24] <= mode;
    end

    // Mode RegValueSet: Schedule read of additional code for opCodes that
    //         store word data. Read in register values for
    //         registers referenced by the instruction.
    `RegValueSet: begin
      debug2 <= 4;

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
		
      // Since there is no word data, there is no need
      // to wait for that word data to come back, and there
      // can be no further reads or writes since the word
      // data is where the address would go
      mode <= `ProcessOpCode;

      debug[23:0] <= regAddress;
      debug[31:24] <= mode;
    end

    // Mode ProcessOpCode: Finalize the instruction operation, by performing
    //         the writes that are needed and moving the
    //         instruction pointer along.
    `ProcessOpCode: begin
      debug2 <= 5;

      debug[23:0] <= regAddress;
      debug[31:24] <= mode;

      regarray[rPos] <= 0;
        
      if (opCode == 47 || ipointer == 8)
      begin
        // This will hit the 'default' path
        mode <= 42;
      end
      else
      begin
        if (Is8ByteOpcode(opCode) == 1)
          ipointer <= ipointer + 8;
        else
          ipointer <= ipointer + 4;

		  mode <= `InitialMode;    
      end
    
    end

    default: begin
      debug2 <= 'hF;
    end

    endcase

    r0 <= regarray[rPos];
    r1 <= regarray[rPos + 1];
    r2 <= regarray[rPos + 2];
    r3 <= regarray[rPos + 3];
    r4 <= regarray[rPos + 4];
    r5 <= regarray[rPos + 5];
  end

endmodule
