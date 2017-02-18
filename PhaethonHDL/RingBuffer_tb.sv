/* `timescale 10us/10ns */

module test;

  /* Make a reset that pulses once. */
  reg reset = 0;

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg[7:0] data;
  reg writeEnable;
  reg readEnable;

  initial begin
    # 0 reset = 1;
    # 0 data = 'h1;
    # 0 writeEnable = 1;
    # 0 readEnable = 0;
    # 1 reset = 0;
    # 10 data = 'h2;      // Write first
    # 10 data = 'h3;      // Write second
    # 10 data = 'h4;      // Write third
    # 0 writeEnable = 0;
    # 0 readEnable = 1;
    # 10 data = 'h5;      // Read first
    # 10 data = 'h6;      // Read second
    # 0 writeEnable = 1;
    # 0 readEnable = 0;    
    # 10 data = 'h7;      // Write fourth
    # 10 data = 'h8;      // Write fifth
    # 10 data = 'h9;      // Write sixth (should not work)
    # 10 data = 'ha;      // Read third
    # 0 writeEnable = 0;
    # 0 readEnable = 1;
    # 100 $finish;
  end

  wire dataReadAck;
  wire[7:0] dataRead;
  wire[31:0] debug;
  wire[31:0] debug2;
  
  RingBuffer #(8, `BITLENGTH) ring(
    clk,
    reset,
    writeEnable,
    data,
    readEnable,
    dataReadAck,      // Flag to indicate read success
    dataRead,         // Actual data read
    debug,
    debug2
    );

endmodule // test
