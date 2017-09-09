module EnumTest(
  reset,
  out1,
  out2,
  out3
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  `define __EndState 2
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
  output reg[0:0] out2;
  output reg[3:0] out3;
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
        out1 <= 32'd0;
        out2 <= 1'b0;
        out3 <= 4'd1;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= 32'd1;
        out2 <= 1'b1;
        out3 <= 4'd1;
        fsmState <= `__EndState;
      end
      `__EndState: begin
        out1 <= 32'd15;
        out2 <= 1'b1;
        out3 <= 4'd9;
      end
    endcase
  end
endmodule
