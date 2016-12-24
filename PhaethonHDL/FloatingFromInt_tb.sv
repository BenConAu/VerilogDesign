/* `timescale 10us/10ns */

module test;


  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg[31:0] a;
  reg[31:0] b;

  initial
  begin
    #5 a <= 49;
    #15 a <= 'hfffffff9;
    #20 $finish;
  end

  wire [31:0] value;
  wire [31:0] debug;
  FloatingFromInt ffi (a, value, debug, clk, 1'b1);

  initial
     $monitor("At time %t, value = %h, debug = %h",
              $time, value, debug);
endmodule // test