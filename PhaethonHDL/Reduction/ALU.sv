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
  r2,          // [Debug]  current r2 value
  r3,          // [Debug]  current r3 value
  r4,          // [Debug]  current r4 value
  r5,          // [Debug]  current r5 value
  rPos,        // [Debug]  current rPos (register window) value
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
  reg        [3:0]  mode;
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
          regAddress <=  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
          regAddress2 <= (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
          regAddress3 <= (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);

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
        regValue[0] <= regarray[regAddress[7:0]];
        regValue2[0] <= regarray[regAddress2[7:0]];
        regValue3[0] <= regarray[regAddress3[7:0]];

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

        //$display("opDataWord == %h", opDataWord);

        debug[23:0] <= regAddress;
        debug[31:24] <= mode;

        //$display("Incrementing ip");

        ipointer <= ipointer + 4;

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
