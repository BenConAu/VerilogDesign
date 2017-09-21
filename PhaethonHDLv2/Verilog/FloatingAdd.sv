module FloatingAdd(a, b, negate, out, debug, clk, enable);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;
  input wire [0:0] negate;
  input wire [0:0] enable;
  integer i;

  `include "FloatingHelper.sv"

  reg        sign;
  reg [7:0]  aExp;
  reg [7:0]  bExp;
  reg [31:0] aMant;
  reg [31:0] bMant;
  reg [31:0] aPrimeMant;
  reg [31:0] totalMant;
  reg [31:0] normMant;
  reg [31:0] clz;

  always @(posedge clk)
  begin
    if (enable == 1)
    begin
      // Unpack the mantissa, make b the one with larger exponent
      // Always negate b if negation is asked for since it is the
      // second operand.
      if (a[30 : 23] < b[30 : 23])      
      begin
        UnpackFloat(a, 0, aMant, aExp);
        UnpackFloat(b, negate, bMant, bExp);
      end
      else
      begin
        UnpackFloat(b, negate, aMant, aExp);
        UnpackFloat(a, 0, bMant, bExp);
      end

      // Add the mantissas together, shifting the smaller exp one
      SignedShiftRight(aMant, bExp - aExp, totalMant);
      totalMant = totalMant + bMant;
  
      // Figure out sign of total
      if (totalMant[31:31] == 1)
      begin
        sign = 1;
        totalMant = (~totalMant) + 1;
      end
      else
      begin
        sign = 0;
      end
  
      // Figure out leading zero count
      CLZ(totalMant, clz);
  
      // Leading zeros should be 8, so shift to that
      NormalizeMantissa(totalMant, clz, normMant);
  
      out[31:31] = sign;
      out[30:23] = bExp + (8 - clz);
      out[22:0] = normMant[22:0];
    end
    else
    begin
      out <= 'habc;
      debug <= 0;
    end
  end
  
endmodule // floating