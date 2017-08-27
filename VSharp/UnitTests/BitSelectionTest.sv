module BitSelectionTest(
  reset,
  in1,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  input wire[31:0] in1;
  output reg[15:0] out1;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= in1[19:4];
      end
    endcase
  end
endmodule
