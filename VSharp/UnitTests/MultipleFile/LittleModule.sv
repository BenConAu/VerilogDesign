module LittleModule(
  clk,
  mIn,
  inFoo,
  mOut,
  outFoo
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[7:0] mIn;
  input wire[31:0] inFoo;
  output reg[15:0] mOut;
  output reg[31:0] outFoo;
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
