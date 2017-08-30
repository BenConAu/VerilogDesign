module StructTest(
  reset,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  `define __EndState 2
  // inputs / outputs
  input wire reset;
  output reg[31:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[40:0] test;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%h", out1);
        test[40:40] <= 0;
        test[39:8] <= 100;
        test[7:0] <= 10;
        out1 <= 0;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= test[39:8];
        fsmState <= `__EndState;
      end
      `__EndState: begin
        out1 <= 200;
      end
    endcase
  end
endmodule
