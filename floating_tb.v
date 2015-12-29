/* `timescale 10us/10ns */

module test;


  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
     # 17 reset = 1;
     # 11 reset = 0;
     # 29 reset = 1;
     # 11 reset = 0;
     # 240 $finish;
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  wire [31:0] value;
  wire [31:0] debug;
  floating c1 (value, debug, clk, reset);

  initial
     $monitor("At time %t, value = %h, debug = %h, reset = %h",
              $time, value, debug, reset);
endmodule // test