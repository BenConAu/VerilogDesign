module EnumTest(
  clk,
  reset,
  in1,
  out1,
  out2
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire clk;
  input wire reset;
  input wire[31:0] in1;
  output reg[31:0] out1;
  output reg[0:0] out2;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        fsmState <= `__StartState;
        out1 <= 0;
        out2 <= 0;
      end
      `__StartState: begin
        out1 <= 1;
        out2 <= 1;
      end
    endcase
  end
endmodule
