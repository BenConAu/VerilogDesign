module FloatingMultiply(a, b, out, debug, clk);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;
  integer i;

  `include "FloatingHelper.v"

  reg [1:0] sign;
  reg [7:0] aExp;
  reg [7:0] bExp;
  reg [15:0] totalExp;
  reg [31:0] aMant;
  reg [31:0] bMant;
  reg [31:0] aPrimeMant;
  reg [63:0] totalMant;
  reg [31:0] clz;

  always @(posedge clk)
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

    // Leading zeros should be 8, so shift to that
    if (clz > 8)
      aPrimeMant = aPrimeMant << (clz - 8);
    else
      aPrimeMant = aPrimeMant >> (8 - clz);

    totalExp = aExp + bExp + (8 - clz) - 127;
    debug = totalExp;

    out[31:31] = sign;
    out[30:23] = totalExp[7:0];
    out[22:0] = aPrimeMant[22:0];
  end
  
endmodule // floating