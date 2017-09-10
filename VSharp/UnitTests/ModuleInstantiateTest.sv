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
module ModuleInstantiate(
  out1
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[7:0] var1;
  wire[15:0] var2;
  LittleModule m1(clk, var1, var2);
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("var1 = %h", var1);
        var1 <= 8'd123;
      end
    endcase
  end
endmodule
