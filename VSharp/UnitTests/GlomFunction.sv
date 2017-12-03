module BitSelectionTest(
  out1
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  output reg[63:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] inval;
  initial
  begin
    # 0 inval = 32'd2;
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("out = %h", out1);
        if (inval == 32'd1)
        begin
          if (inval == 32'd1)
          begin
            out1 <= { inval + 32'd10, inval + 32'd10 };
          end
          else
          begin
            out1 <= { inval + 32'd10, inval * 32'd10 };
          end
        end
        else
        begin
          if (inval == 32'd1)
          begin
            out1 <= { inval * 32'd10, inval + 32'd10 };
          end
          else
          begin
            out1 <= { inval * 32'd10, inval * 32'd10 };
          end
        end
      end
    endcase
  end
endmodule
