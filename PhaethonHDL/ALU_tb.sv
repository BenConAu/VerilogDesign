/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 20000 $finish;
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
  wire [31:0] debug2;
  wire [8:0] debug3;
  wire [31:0] ramAddress;
  wire [31:0] ramOut;
  wire [0:0] readReq;
  wire [0:0] writeReq;
  wire [0:0] uartReadReq;

  reg  [7:0] uartData = 'hab;
  reg  [0:0] uartReadAck = 1'b0;

  wire uartWriteReq;
  wire [7:0] uartWriteData;
  reg uartWriteReady = 1'b1;

//  parameter RAMSIZE = 64;

  ALU alu(
    clk,
    reset,
    ramValue,
    ramAddress,
    ramOut,
    readReq,
    writeReq,
    uartReadReq,    // [Output] uart read requested
    uartReadAck,    // [Input]  Flag to indicate read success
    uartData,       // [Input] Actual data read 
    uartWriteReq,   // [Output] uart write requested
    uartWriteData,  // [Output] uart data to write
    uartWriteReady, // [Input]  uart ready to send
    iPointer,
    opCode,
    r0,
    r1,
    r2,
    r3,
    r4,
    r5,
    rPos,
    debug,
    debug2,
    debug3
    );

  //initial
     //$monitor("At time %t, ip = %h, opCode = %h, readReq = %h, ramValue = %h, uartRR = %h, uartRA = %h, uartD = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
        //$time, iPointer[15:0], opCode, readReq, ramValue, uartReadReq, uartReadAck, uartData, r0, r1, r2, r3, r4, r5, rPos, debug);

  // Fake RAM
  always @(posedge clk)
  begin
    if (readReq == 1)
    begin
      //$display("Retrieving address %h", ramAddress);
      ramValue[7:0] <= fileRam[ramAddress];
      ramValue[15:8] <= fileRam[ramAddress + 1];
      ramValue[23:16] <= fileRam[ramAddress + 2];
      ramValue[31:24] <= fileRam[ramAddress + 3];
    end

    if (writeReq == 1)
    begin
      //$display("Writing %h into %h", ramOut, ramAddress);
      fileRam[ramAddress] <= ramOut[7:0];
      fileRam[ramAddress + 1] <= ramOut[15:8];
      fileRam[ramAddress + 2] <= ramOut[23:16];
      fileRam[ramAddress + 3] <= ramOut[31:24];
    end
  end

  // Fake UART receiver
  always @(posedge clk)
  begin
    if (uartReadReq == 1'b1)
    begin
      uartReadAck <= 1;
    end
  end  

  // Fake UART sender
  always @(posedge clk)
  begin
    if (uartWriteReq == 1)
    begin
      $display("UART send with data %h", uartWriteData);
    end
  end  

endmodule // test
