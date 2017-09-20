module ConstExprTest(
  out1
  );
  // State definitions
  `define __initial 0
  `define __EndState 1
  // inputs / outputs
  input wire reset;
  output reg[15:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] TestArray1[3:0];
  reg[31:0] TestMutable = 32'd1;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("TestVal = %h", TestArray1[32'd3]);
        TestArray1[32'd3] <= 32'd291;
        fsmState <= `__EndState;
      end
      `__EndState: begin
        TestArray1[32'd3] <= 32'd2748;
      end
    endcase
  end
endmodule
