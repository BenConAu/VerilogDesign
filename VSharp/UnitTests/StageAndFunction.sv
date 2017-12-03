module StagingExample(
  moduleInput,
  moduleOutput
  );
  // inputs / outputs
  input wire reset;
  input wire[31:0] moduleInput;
  output reg[31:0] moduleOutput;
  reg clk = 0; always #5 clk = !clk;
  initial
  begin
    # 100 $finish;
  end
  always @(posedge clk)
  begin
    $monitor("Output = %h", moduleOutput);
    moduleOutput <= 16'd1 + 16'd6;
  end
endmodule
