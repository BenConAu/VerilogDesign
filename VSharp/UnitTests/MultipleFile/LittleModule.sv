module LittleModule(
  clk,
  mIn,
  mOut
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[7:0] mIn;
  output reg[15:0] mOut;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        mOut <= { mIn, mIn };
      end
    endcase
  end
endmodule
