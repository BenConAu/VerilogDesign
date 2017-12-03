module test;

  // State definitions
  `define __initial 0
  `define __MemReadDone 1

  /* Make a reset that pulses once. */
  reg reset = 0;
  initial begin
    # 0 reset = 1;
    # 1 reset = 0;
    # 30000 $finish;
  end

  /* Make a regular pulsing clock. */
  reg clk = 0;
  always #5 clk = !clk;

  reg[7:0] fileRam[0:65535];
  reg[1023:0] testName;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        if ($value$plusargs("ROMFILE=%s", testName))
          begin
            $readmemh(testName, fileRam, 32'd0);
          end
        fsmState <= `__MemReadDone;
      end
      `__MemReadDone: begin
      end
    endcase
  end
endmodule
