/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 20000 $finish;
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg [7:0] fileRam[0:65535];
  reg [511:0] testname;
  reg fileFound;

  initial
  begin
    fileFound = $value$plusargs("ROMFILE=%s", testname);
    $readmemh(testname, fileRam, 0);
  end

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

  reg  [7:0] uartReadData = 'hab;
  reg  [0:0] uartReadAck = 1'b0;

  // Fake UART receiver
  always @(posedge clk)
  begin
    if (uartReadReq == 1'b1)
    begin
      uartReadAck <= 1;
    end
  end  

  wire       uartWriteReq;
  wire [7:0] uartWriteData;
  reg        uartWriteReady = 1'b1;

  // Fake UART sender
  always @(posedge clk)
  begin
    if (uartWriteReq == 1)
    begin
      $display("UART send with data %h", uartWriteData);
    end
  end  

  wire [0:0]  uartReadReq;
  reg  [31:0] phRamRead;
  wire [31:0] phRamWrite;
  wire [31:0] phRamAddress;
  wire [0:0]  phReadReq;
  wire [0:0]  phWriteReq;
  wire [31:0] debug;
  wire [31:0] debug2;
  wire [8:0] debug3;

  CPU cpu1(
    clk,            // [Input]  Clock driving the ALU
    reset,          // [Input]  Reset pin
    phRamRead,      // [Input]  RAM at requested address
    phRamAddress,   // [Output] RAM address requested
    phRamWrite,     // [Output] RAM to write
    phReadReq,      // [Output] RAM read request
    phWriteReq,     // [Output] RAM write request  
    uartReadReq,    // [Output] uart read requested
    uartReadAck,    // [Input]  Flag to indicate read success
    uartReadData,   // [Input]  Actual data read 
    uartWriteReq,   // [Output] uart write requested
    uartWriteData,  // [Output] uart data to write
    uartWriteReady, // [Input]  uart ready to send
    debug,          // [Output] Debug port
    debug2,         // [Output] Another debug port
    debug3          // [Output] And yet another debug port
    );

endmodule // test
