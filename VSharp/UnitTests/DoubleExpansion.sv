module DoubleExpansionTest(
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
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
        $monitor("out1 = %h", out1);
        out1 <= 32'd0;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        if (32'd10 == 32'd0)
        begin
          if (32'd20 == 32'd100)
          begin
            out1 <= 32'd52;
          end
          else
          begin
            out1 <= 32'd7;
          end
        end
        else
        begin
          if (32'd20 == 32'd100)
          begin
            out1 <= 32'd53;
          end
          else
          begin
            out1 <= 32'd8;
          end
        end
      end
    endcase
  end
endmodule
