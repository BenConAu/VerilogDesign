module EnumTest(
  reset,
  out1,
  out2
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
  output reg[0:0] out2;
  reg clk = 0; always #5 clk = !clk;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("uint32 value = %h, boolean value = %h", out1, out2);
        out1 <= 0;
        out2 <= 0;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= 1;
        out2 <= 1;
      end
    endcase
  end
endmodule
