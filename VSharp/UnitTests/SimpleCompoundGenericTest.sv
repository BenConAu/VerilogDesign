module GenericFunctionTest(
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] HandyNum = 32'd2748;
  reg[31:0] CLZ_Handy;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("TestVal = %h", CLZ_Handy);
        CLZ_Handy <= { 16'd0, HandyNum[31:16] };
      end
    endcase
  end
endmodule
