module StagingExample(
  moduleInput,
  moduleOutput
  );
  // inputs / outputs
  input wire reset;
  input wire[31:0] moduleInput;
  output reg[31:0] moduleOutput;
  reg clk = 0; always #5 clk = !clk;
  always @(posedge clk)
  begin
    if (moduleInput > 32'd100)
    begin
      moduleOutput <= { 16'd1, moduleInput[31:16] };
    end
    else
    begin
      moduleOutput <= { 16'd1, 16'd0 };
    end
  end
endmodule
