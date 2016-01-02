/* `timescale 10us/10ns */

module test;


  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 1000 $finish;
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  wire [7:0] iPointer;
  wire [7:0] opCode;

  wire [31:0] r0;
  wire [31:0] r1;

  wire [31:0] debug;

  reader reader1 (iPointer, opCode, clk, reset, r0, r1, debug);

  initial
     $monitor("At time %t, ip = %h, opCode = %h, reset = %h, r[0:1] = %h:%h, debug = %h",
              $time, iPointer, opCode, reset, r0, r1, debug);
endmodule // test