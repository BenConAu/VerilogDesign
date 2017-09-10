module LittleModule(
  reset,
  clk,
  input,
  output
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[7:0] input;
  output reg[15:0] output;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        output <= { input, input };
      end
    endcase
  end
endmodule
module ModuleInstantiate(
  reset,
  out1
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[7:0] var1;
  reg[15:0] var2;
  m1;
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
