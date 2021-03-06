module ModuleInstantiate(
  out1,
  testOutWire
  );
  // State definitions
  `define __initial 0
  `define __EndState 1
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  output wire[31:0] testOutWire;
  reg clk = 0; always #5 clk = !clk;
  reg[7:0] var1;
  reg[31:0] inFoo;
  wire[15:0] var2;
  wire[31:0] outFoo;
  LittleModule m1(clk, var1, inFoo, var2, outFoo, testOutWire);
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("var1 = %h, var2 = %h, testWire = %h", var1, var2, testOutWire);
        var1 <= 8'd123;
        fsmState <= `__EndState;
      end
      `__EndState: begin
      end
    endcase
  end
endmodule
