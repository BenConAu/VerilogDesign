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
    if (moduleInput > 32'd100)
    begin
      if (moduleInput[31:16] == 16'd1)
      begin
        if (moduleInput > 32'd100)
        begin
          if (moduleInput > 32'd100)
          begin
            moduleOutput <= { 16'd2748, moduleInput[31:16] + moduleInput[15:0] };
          end
          else
          begin
            moduleOutput <= { 16'd2748, moduleInput[31:16] + 16'd0 };
          end
        end
        else
        begin
          if (moduleInput > 32'd100)
          begin
            moduleOutput <= { 16'd2748, 16'd0 + moduleInput[15:0] };
          end
          else
          begin
            moduleOutput <= { 16'd2748, 16'd0 };
          end
        end
      end
      else
      begin
        moduleOutput <= { 16'd2748, 16'd1 };
      end
    end
    else
    begin
      if (16'd0 == 16'd1)
      begin
        if (moduleInput > 32'd100)
        begin
          if (moduleInput > 32'd100)
          begin
            moduleOutput <= { 16'd2748, moduleInput[31:16] + moduleInput[15:0] };
          end
          else
          begin
            moduleOutput <= { 16'd2748, moduleInput[31:16] + 16'd0 };
          end
        end
        else
        begin
          if (moduleInput > 32'd100)
          begin
            moduleOutput <= { 16'd2748, 16'd0 + moduleInput[15:0] };
          end
          else
          begin
            moduleOutput <= { 16'd2748, 16'd0 };
          end
        end
      end
      else
      begin
        moduleOutput <= { 16'd2748, 16'd1 };
      end
    end
  end
endmodule
