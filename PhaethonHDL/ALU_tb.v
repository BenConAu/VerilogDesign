/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 400 $finish;
  end

  reg [7:0] fileRam[0:255];

  initial
  begin
    $readmemh("test.pao", fileRam, 0, 19);
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

  reg [7:0] reqAddress;
  reg [0:0] readAck;
  reg [7:0] mode = 0;

  parameter RAMSIZE = 64;

  ALU alu(
    clk, 
    reset, 
    ramValue, 
    readAck, 
    ramAddress, 
    readReq, 
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
    if (readReq == 1 && mode == 0)
    begin
      reqAddress <= ramAddress;
      mode <= 1;
      readAck <= 0;
    end

    if (readReq == 1 && mode == 1)
    begin
      ramValue[7:0] <= fileRam[ramAddress];
      ramValue[15:8] <= fileRam[ramAddress + 1];
      ramValue[23:16] <= fileRam[ramAddress + 2];
      ramValue[31:24] <= fileRam[ramAddress + 3];
      readAck <= 1;
      mode <= 0;
    end

  end

endmodule // test