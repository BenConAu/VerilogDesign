/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg rxd;
  initial begin
    # 0 rxd = 1;
    # 0 reset = 1;
    # 1 reset = 0;
    # 19 rxd = 0;
    # 600 rxd = 1;
    # 3500 rxd = 0;
    # 600 $finish;
  end

  wire dataComplete;
  wire [7:0] data;
  
  UARTReceive uart1(
    clk, 
    reset,
    rxd,
    dataComplete,
    data
    );

endmodule // test
