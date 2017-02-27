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
  wire [31:0] mcRamAddress;
  wire [31:0] mcRamRead;
  wire [31:0] mcRamWrite;
  wire [0:0] mcReadReq;
  wire [0:0] mcWriteReq;
  wire [0:0] uartReadReq;
  reg [31:0] phRamRead;
  wire [31:0] phRamWrite;
  wire [31:0] phRamAddress;
  wire [0:0] phReadReq;
  wire [0:0] phWriteReq;

  reg  [7:0] uartData = 'hab;
  reg  [0:0] uartReadAck = 1'b0;

  wire uartWriteReq;
  wire [7:0] uartWriteData;
  reg uartWriteReady = 1'b1;

  wire mcAddrVirtual = 0;

  ALU alu(
    clk,
    reset,
    mcRamRead,
    mcRamReady,
    mcRamAddress,
    mcRamWrite,
    mcReadReq,
    mcWriteReq,
    mcAddrVirtual,
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
     //$monitor("At time %t, ip = %h, opCode = %h, readReq = %h, mcRamReady = %h, ramValue = %h, uartRR = %h, uartRA = %h, uartD = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
        //$time, iPointer[15:0], opCode, mcReadReq, mcRamReady, mcRamRead, uartReadReq, uartReadAck, uartData, r0, r1, r2, r3, r4, r5, rPos, debug);

  wire [31:0] mcDebug;

  MemoryController mc1(
    clk,              // Global clock
    reset,            // Reset
    mcRamRead,        // [Output] RAM at requested address
    mcRamReady,       // [Output] RAM is ready to be picked up
    mcRamAddress,     // [Input] RAM address requested
    mcRamWrite,       // [Input] RAM to write
    mcReadReq,        // [Input] RAM read request
    mcWriteReq,       // [Input] RAM write request
    mcAddrVirtual,    // [Input] Virtual flag for RAM
    phRamRead,        // [Input]  RAM at requested address
    phRamAddress,     // [Output] RAM address requested
    phRamWrite,       // [Output] RAM to write
    phReadReq,        // [Output] RAM read request
    phWriteReq,       // [Output] RAM write request
    mcDebug           // [Output] Debug port
  );

  // Fake RAM
  always @(posedge clk)
  begin
    if (phReadReq == 1)
    begin
      //$display("Retrieving address %h", phRamAddress);
      phRamRead[7:0] <= fileRam[phRamAddress];
      phRamRead[15:8] <= fileRam[phRamAddress + 1];
      phRamRead[23:16] <= fileRam[phRamAddress + 2];
      phRamRead[31:24] <= fileRam[phRamAddress + 3];
    end

    if (phWriteReq == 1)
    begin
      //$display("Writing %h into %h", ramOut, ramAddress);
      fileRam[phRamAddress] <= phRamWrite[7:0];
      fileRam[phRamAddress + 1] <= phRamWrite[15:8];
      fileRam[phRamAddress + 2] <= phRamWrite[23:16];
      fileRam[phRamAddress + 3] <= phRamWrite[31:24];
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
