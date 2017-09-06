module BitSelectionTest(
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
  reg[31:0] bogus;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("out1 = %h", out1);
        bogus <= 123;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= bogus;
      end
    endcase
  end
endmodule
