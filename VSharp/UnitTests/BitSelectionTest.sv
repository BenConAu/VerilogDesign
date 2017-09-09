module BitSelectionTest(
  reset,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] val;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("val = %h, out1 = %h", val, out1);
        val <= 32'd291;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= val[19:4];
      end
    endcase
  end
endmodule
