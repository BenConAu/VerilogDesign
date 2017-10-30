module AdderTest(
  total
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  output wire[31:0] total;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] a;
  reg[31:0] b;
  FloatingAdd adder(clk, a, b, 1'b0, total);
  initial
  begin
    # 0 a = 32'd1065353216;
    # 0 b = 32'd1073741824;
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("total = %h", total);
      end
    endcase
  end
endmodule
