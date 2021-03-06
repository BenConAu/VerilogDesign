/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 400 $finish;
  end

  reg [7:0] fileRam[0:2047];
  reg [511:0] testname;
  reg fileFound;

  initial
  begin
    fileFound = $value$plusargs("ROMFILE=%s", testname);
    $readmemh(testname, fileRam, 0);
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;
  reg [31:0] ramValue;

  wire [31:0] iPointer;
  wire [7:0] opCode;
  wire [31:0] r0;
  wire [31:0] r1;
  wire [31:0] r2;
  wire [31:0] r3;
  wire [31:0] r4;
  wire [31:0] r5;
  wire [7:0] rPos;
  wire [31:0] debug;
  wire [31:0] ramAddress;
  wire [31:0] ramOut;
  wire [0:0] readReq;
  wire [0:0] writeReq;
  wire [17:0] debug2;
  wire [31:0] runningTotal;
  wire [7:0] mode;

//  parameter RAMSIZE = 64;

  ALU alu(
    clk,
    reset,
    ramValue,
    ramAddress,
    ramOut,
    readReq,
    writeReq,
    iPointer,
    opCode,
    mode,
    r0,
    r1,
    r2,
    r3,
    r4,
    r5,
    rPos,
    debug,
    debug2,
    runningTotal
    );

  initial
     $monitor("At time %t, ip = %h, mode = %h, opCode = %h, readReq = %h, ramValue = %h, r[0:1] = %h:%h, rPos = %h, debug2 = %h, runningTotal = %h",
              $time, iPointer[15:0], mode, opCode, readReq, ramValue, r0, r1, rPos, debug2, runningTotal);

  always @(posedge clk)
  begin
    if (readReq == 1)
    begin
      //$display("Retrieving address %h", ramAddress);
      ramValue[7:0] <= fileRam[ramAddress * 4];
      ramValue[15:8] <= fileRam[ramAddress * 4 + 1];
      ramValue[23:16] <= fileRam[ramAddress * 4 + 2];
      ramValue[31:24] <= fileRam[ramAddress * 4 + 3];
    end

    if (writeReq == 1)
    begin
      //$display("Writing %h into %h", ramOut, ramAddress);
      fileRam[ramAddress * 4] <= ramOut[7:0];
      fileRam[ramAddress * 4 + 1] <= ramOut[15:8];
      fileRam[ramAddress * 4 + 2] <= ramOut[23:16];
      fileRam[ramAddress * 4 + 3] <= ramOut[31:24];
    end
  end

endmodule // test
