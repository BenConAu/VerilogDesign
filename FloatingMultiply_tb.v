/* `timescale 10us/10ns */

module test;


  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg[31:0] a;
  reg[31:0] b;

  initial
  begin
    a <= 'h447a0000; // 1000
    //a <= 'h42000000; // 32
    //b = 'h40a00000; // 5
    //b <= 'h42000000; // 32
    b <= 'hc1200000; // -10
    #20 $finish;
  end

  wire [31:0] value;
  wire [31:0] debug;
  FloatingMultiply c1 (a, b, value, debug, clk);

  initial
     $monitor("At time %t, value = %h, debug = %h",
              $time, value, debug);
endmodule // test