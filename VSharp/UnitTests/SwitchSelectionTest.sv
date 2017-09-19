module SwitchSelectionTest(
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
        val <= 32'd1;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        case (val)
          32'd0: begin
            out1 <= 16'd291;
            val <= 32'd1;
          end
          32'd1: begin
            out1 <= 16'd2748;
            val <= 32'd2;
          end
          default: begin
            out1 <= 16'd48879;
            val <= 32'd0;
          end
        endcase
      end
    endcase
  end
endmodule
