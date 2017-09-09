module DoubleExpansionTest(
  reset,
  out1,
  out2,
  out3
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
  output reg[31:0] out2;
  output reg[31:0] out3;
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
        $monitor("out1 = %h, out2 = %h, out3 = %h", out1, out2, out3);
        out1 <= 32'd10;
        out2 <= 32'd20;
        out3 <= 32'd30;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        if (32'd10 == 32'd0)
        begin
          out1 <= 32'd1;
          out2 <= 32'd3;
          out3 <= 32'd1;
        end
        else
        begin
          out1 <= 32'd2;
          out2 <= 32'd5;
          out3 <= 32'd7;
        end
      end
    endcase
  end
endmodule
