module OperatorTest(
  clk,
  reset,
  in1,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire clk;
  input wire reset;
  input wire[31:0] in1;
  output reg[31:0] out1;
  reg[31:0] arr[7:0];
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        fsmState <= `__StartState;
      end
      `__StartState: begin
        if (in1 == 0 && in1 == 1)
        begin
          out1 <= 1;
        end
      end
    endcase
  end
endmodule
