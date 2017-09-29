module StagingExample(
  a,
  b
  );
  // inputs / outputs
  input wire reset;
  input wire[31:0] a;
  output reg[31:0] b;
  always @(posedge clk)
  begin
    b <= { middle, middle };
  end
endmodule
