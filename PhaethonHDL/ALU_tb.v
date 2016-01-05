/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 1000 $finish;
  end

  reg [7:0] fileRam[0:255];

  initial
  begin
    $readmemh("test.pao", fileRam, 0, 31);
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;
  reg [31:0] ramValue;

  wire [7:0] iPointer;
  wire [7:0] opCode;
  wire [31:0] r0;
  wire [31:0] r1;
  wire [31:0] debug;
  wire [7:0] ramAddress;
  wire [31:0] ramOut;
  wire [0:0] readReq;
  wire [0:0] writeReq;

  reg [7:0] reqAddress;
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
    debug
    );

  initial
     $monitor("At time %t, ramAddress = %h, ip = %h, opCode = %h, reset = %h, r[0:1] = %h:%h, debug = %h",
              $time, ramAddress, iPointer, opCode, reset, r0, r1, debug);

  always @(posedge clk)
  begin
    // If ready to fill request
    if (readReq == 1)
    begin
      if (mode == 0)
      begin
        reqAddress <= ramAddress;
        mode <= 1;
        readAck <= 0;
      end
      else
      begin
        ramValue[7:0] <= fileRam[ramAddress];
        ramValue[15:8] <= fileRam[ramAddress + 1];
        ramValue[23:16] <= fileRam[ramAddress + 2];
        ramValue[31:24] <= fileRam[ramAddress + 3];
        readAck <= 1;
        mode <= 0;
      end
    end

    if (writeReq == 1)
    begin
      if (mode == 0)
      begin
        reqAddress <= ramAddress;
        mode <= 1;
        writeAck <= 0;
      end
      else
      begin
        fileRam[ramAddress] <= ramOut[7:0];
        fileRam[ramAddress + 1] <= ramOut[15:8];
        fileRam[ramAddress + 2] <= ramOut[23:16];
        fileRam[ramAddress + 3] <= ramOut[31:24];
        writeAck <= 1;
        mode <= 0;
      end
    end

  end

endmodule // test