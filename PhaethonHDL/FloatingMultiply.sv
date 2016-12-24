module FloatingMultiply(a, b, out, debug, clk, enable);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire enable;
  input wire [31:0] a;
  input wire [31:0] b;
  integer i;

  `include "FloatingHelper.sv"

  reg [1:0] sign;
  reg [7:0] aExp;
  reg [7:0] bExp;
  reg [15:0] totalExp;
  reg [31:0] aMant;
  reg [31:0] bMant;
  reg [31:0] aPrimeMant;
  reg [31:0] aNormMant;
  reg [63:0] totalMant;
  reg [31:0] clz;

  always @(posedge clk or posedge enable)
  begin
    if (enable == 1)
    begin
      // Unpack the floats and force positive Mantissas by exploiting the negation
      UnpackFloat(a, a[31:31], aMant, aExp);
      UnpackFloat(b, b[31:31], bMant, bExp);
  
      // Multply the mantissas together and do shift compensation
      totalMant = aMant * bMant;
      aPrimeMant = totalMant[54:23];
  
      // Figure out sign of total
      sign = a[31:31] ^ b[31:31];
  
      // Figure out leading zero count
      CLZ(aPrimeMant, clz);
  
      // Normalize to 8 leading zeros
      NormalizeMantissa(aPrimeMant, clz, aNormMant);
  
      totalExp = aExp + bExp + (8 - clz) - 127;
      debug = totalExp;
  
      out[31:31] = sign;
      out[30:23] = totalExp[7:0];
      out[22:0] = aNormMant[22:0];
    end
    else
    begin
      out = 'hdef;
    end
  end
  
endmodule // floating