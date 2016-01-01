module floating(a, b, negate, out, debug, clk);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;
  input wire [0:0] negate;
  integer i;

  `include "FloatingHelper.v"

  reg [1:0] sign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [31 : 0] aMant;
  reg [31 : 0] bMant;
  reg [31 : 0] aPrimeMant;
  reg [31 : 0] totalMant;
  reg [31:0] clz;

  always @(posedge clk)
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
      totalMant = ~(totalMant - 1);
    end
    else
    begin
      sign = 0;
    end

    // Figure out leading zero count
    CLZ(totalMant, clz);

    // Leading zeros should be 8, so shift to that
    if (clz > 8)
      totalMant = totalMant << (clz - 8);
    else
      totalMant = totalMant >> (8 - clz);

    out[31:31] = sign;
    out[30:23] = bExp + (8 - clz);
    out[22:0] = totalMant[22:0];
  end
  
endmodule // floating