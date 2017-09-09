module BitSelectionTest(
  reset,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  `define __EndState 2
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] val;
  reg[63:0] val2;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("val = %h, val2 = %h, out1 = %h", val, val2[63:32], out1);
        val <= 32'd291;
        val2[63:32] <= 32'd1110;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= val[19:4];
        fsmState <= `__EndState;
      end
      `__EndState: begin
        out1 <= val2[51:36];
      end
    endcase
  end
endmodule
