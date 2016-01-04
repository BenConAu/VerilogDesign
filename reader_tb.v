/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;
  reg run = 0;
  reg [7:0] ramAddress = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 1000 $finish;
  end

  reg [7:0] fileRam[0:255];

  initial
  begin
    $readmemh("test.pao", fileRam, 0, 19);
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;
  reg [7:0] ramValue;

  wire [7:0] iPointer;
  wire [7:0] opCode;
  wire [31:0] r0;
  wire [31:0] r1;
  wire [31:0] debug;

  parameter RAMSIZE = 64;

  reader reader1 (iPointer, opCode, clk, reset, r0, r1, debug, ramAddress, ramValue, run);

  initial
     $monitor("At time %t, ramAddress = %h, ip = %h, opCode = %h, reset = %h, r[0:1] = %h:%h, debug = %h",
              $time, ramAddress, iPointer, opCode, reset, r0, r1, debug);

  always @(posedge clk)
  begin
    ramValue = fileRam[ramAddress];
    ramAddress = ramAddress + 1;
    if (ramAddress == 21)
    begin
      run = 1;
    end
  end
endmodule // test