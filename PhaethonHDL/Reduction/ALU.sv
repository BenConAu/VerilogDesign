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
  runningTotal,// [Output] Running total of instruction RAM
  );

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
  reg        [31:0] regValue;
  reg        [31:0] regValue2;
  reg        [31:0] regValue3;
  reg        [7:0]  regAddress;
  reg        [7:0]  regAddress2;
  reg        [7:0]  regAddress3;
  reg        [31:0] sentinel;

  //initial
  //   $monitor("%t, ram = %h, %h, %h, %h : %h, %h, %h, %h",
  //     $time, ramIn[7:0], ramIn[15:8], ramIn[23:16], ramIn[31:24], ramAddress, ramIn, opAddress, ramValue);

  always @(posedge clk)
  begin
    case (mode)
    // Mode 0: Schedule read of code at instruction pointer and clear
    //         out enable bits for auxillary modules.
    0: begin
		if (sentinel != 'h12345678)
		  begin
		    // This should only run on first power
          ipointer <= 0;
          opCode <= 0;
          rPos <= 2;
          mode <= 0;
          readReq <= 0;
			 sentinel <= 'h12345678;
			 runningTotal <= 0;
			 
			 debug2 <= 'h1;
			 // We will come back here on next clock
		  end
		  else
		  begin
          // Begin RAM read for instruction data
          readReq <= 1;
          ramAddress <= ipointer;

          debug[23:0] <= ipointer;
          debug[31:24] <= mode;

          // Clear out stuff for the pipeline
          mode <= 'h8;

          debug2 <= 'h3;
		  end
    end

    // Mode 8 - ramIn is set by RAM module
    'h8: begin
      // Stop request
      readReq <= 0;

		regarray[2][31:0] <= 'h7777f00d;
      mode <= 1;

      debug[23:0] <= 0;
      debug[31:24] <= mode;
		  
		debug2 <= 'h123;
	  
    end		
		
    // Mode 1: Handle ack of instruction pointer read request and
    //         decode the instruction data, including the opCode
    //         of the instruction and the affected registers.
    1: begin
		debug2 <= 'h4;
		  

   	//$display("Receiving value %h", ramIn);

      opCode <= ramIn[7:0];
      regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
      regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
      regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);
		  
		regValue <= ramIn;
		runningTotal <= runningTotal + ramIn;

      // Safe to move to next mode now
      mode <= 2;

      debug[23:0] <= ramIn[23:0];
      debug[31:24] <= mode;
    end

    // Mode 2: Schedule read of additional code for opCodes that
    //         store word data. Read in register values for
    //         registers referenced by the instruction.
    2: begin
		debug2 <= 'h5;

			// Read values from registers
      //regValue <= regarray[regAddress[7:0]];
      regValue2 <= regarray[regAddress2[7:0]];
      regValue3 <= regarray[regAddress3[7:0]];

      // Since there is no word data, there is no need
      // to wait for that word data to come back, and there
      // can be no further reads or writes since the word
      // data is where the address would go
      mode <= 6;

      debug[23:0] <= regAddress;
      debug[31:24] <= mode;
    end

    // Mode 6: Finalize the instruction operation, by performing
    //         the writes that are needed and moving the
    //         instruction pointer along.
    6: begin
		  debug2 <= 'h6;

      //$display("opDataWord == %h", opDataWord);

      debug[23:0] <= regAddress;
      debug[31:24] <= mode;

		  regarray[rPos] <= regValue;
		  		  
      //$display("Incrementing ip");

      //ipointer <= ipointer + 4;

      //$display("Finished instruction %h", opCode);

      // Mode change
      //mode <= 0;
    end
		
		default:
		  begin
		    debug2 <= 'habc;
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
