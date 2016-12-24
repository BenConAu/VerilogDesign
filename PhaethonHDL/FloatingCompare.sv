module FloatingCompare(a, b, out, debug, clk, enable);
  output reg [1:0] out;
  output reg [31:0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;
  input wire [0:0] enable;

  `include "FloatingHelper.sv"

  reg [7:0] aExp;
  reg [7:0] bExp;
  reg [31:0] aMant;
  reg [31:0] bMant;
  reg [31:0] totalMant;

  always @(posedge clk or posedge enable)
  begin
    if (enable == 1)
    begin
      // Unpack the mantissa, make b the one with larger exponent
      // Always negate b if negation is asked for since it is the
      // second operand.
      if (a[30 : 23] < b[30 : 23])      
      begin
        UnpackFloat(a, 0, aMant, aExp);
        UnpackFloat(b, 1, bMant, bExp);
      end
      else
      begin
        UnpackFloat(b, 1, aMant, aExp);
        UnpackFloat(a, 0, bMant, bExp);
      end

      // Add the mantissas together, shifting the smaller exp one
      SignedShiftRight(aMant, bExp - aExp, totalMant);
      totalMant = totalMant + bMant;

      if (totalMant == 0)
        out = 0;
      else
      begin
        // Figure out sign of total
        if (totalMant[31:31] == 1)
          out = 'b11;
        else
          out = 'b01;
      end
    end
  end
  
endmodule // floating