/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg[7:0] data;

  initial begin
    # 0 reset = 1;
    # 0 data = 'h12;
    # 1 reset = 0;
    # 10 data = 'h23;
    # 10 data = 'h34;
    # 10 data = 'h45;
    # 10 data = 'h56;
    # 10 data = 'h78;
    # 20 $finish;
  end

  wire dataReadAck;
  wire[7:0] dataRead;
  
  UARTRingBuffer ring(
    clk,
    reset,
    1'b1,
    data,
    1'b0,
    dataReadAck,      // Flag to indicate read success
    dataRead          // Actual data read
    );

endmodule // test
