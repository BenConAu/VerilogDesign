module AlwaysStateTest(
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  `define __EndState 2
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] val;
  reg[31:0] val2;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("val = %h, val2 = %h", val, val2);
        val <= 32'd291;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        val <= 32'd2748;
        fsmState <= `__EndState;
      end
      `__EndState: begin
        val <= 32'd48879;
      end
    endcase
    if (val == 32'd291)
    begin
      val2 <= 32'd3735928559;
    end
    else
    begin
      val2 <= 32'd1611513583;
    end
  end
endmodule
