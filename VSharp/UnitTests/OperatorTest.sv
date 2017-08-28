module OperatorTest(
  reset,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] a;
  reg[31:0] b;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("a = %h and b = %h and out1 = %h", a, b, out1);
        a <= 0;
        b <= 1;
        out1 <= 0;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        if (a == 0 && b == 1)
        begin
          out1 <= 1;
        end
      end
    endcase
  end
endmodule
