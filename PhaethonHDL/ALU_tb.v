/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 10000 $finish;
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

  reg [31:0] reqAddress;
  reg [0:0] readAck;
  reg [0:0] writeAck;
  reg [7:0] mode = 0;

  parameter RAMSIZE = 64;

  ALU alu(
    clk,
    reset,
    ramValue,
    readAck,
    writeAck,
    ramAddress,
    ramOut,
    readReq,
    writeReq,
    iPointer,
    opCode,
    r0,
    r1,
    r2,
    r3,
    r4,
    r5,
    rPos,
    debug
    );

  //initial
     //$monitor("At time %t, ip = %h, opCode = %h, reset = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
              //$time, iPointer[15:0], opCode, reset, r0, r1, r2, r3, r4, r5, rPos, debug);

  always @(posedge clk)
  begin
    // Mode zero means ready to fill a request (so that you can't file
    // a new request in the middle of another one)
    if (mode == 0)
    begin
      // Ack bits are only set when read or write is done
      readAck <= 0;
      writeAck <= 0;

      if (readReq == 1)
      begin
        reqAddress <= ramAddress;
        mode <= 1;
      end

      if (writeReq == 1)
      begin
        reqAddress <= ramAddress;
        mode <= 2;
      end
    end

    // Mode one means the request from the outside is understood and
    // the read will be processed and the acknowledgement sent back
    if (mode == 1)
    begin
      //$display("Retrieving address %h", reqAddress);
      ramValue[7:0] <= fileRam[reqAddress];
      ramValue[15:8] <= fileRam[reqAddress + 1];
      ramValue[23:16] <= fileRam[reqAddress + 2];
      ramValue[31:24] <= fileRam[reqAddress + 3];
      readAck <= 1;
      mode <= 0;
    end

    if (mode == 2)
    begin
      //$display("Writing %h into %h", ramOut, reqAddress);
      fileRam[reqAddress] <= ramOut[7:0];
      fileRam[reqAddress + 1] <= ramOut[15:8];
      fileRam[reqAddress + 2] <= ramOut[23:16];
      fileRam[reqAddress + 3] <= ramOut[31:24];
      writeAck <= 1;
      mode <= 0;
    end
  end

endmodule // test
