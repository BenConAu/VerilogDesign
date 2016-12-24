module FloatingMultiplyAdd(a, b, c, out, debug, clk, enable);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire enable;

  // The three inputs - we do a * b + c
  input wire [31:0] a;
  input wire [31:0] b;
  input wire [31:0] c;

  `include "FloatingHelper.sv"

  // Intermediates for a and b
  reg [7:0] aExp;
  reg [7:0] bExp;
  reg [31:0] aMant;
  reg [31:0] bMant;

  // Intermediates for a*b
  reg [1:0] abSign;
  reg [31:0] abMant;
  reg [31:0] abNormMant;
  reg [31:0] abClz;
  reg [15:0] abExp;
  reg [63:0] mulMant;

  // Final intermediates
  reg [7:0] alphaExp;
  reg [7:0] betaExp;
  reg [31:0] alphaMant;
  reg [31:0] betaMant;

  // Final bits
  reg [1:0] finalSign;
  reg [31:0] finalMant;
  reg [31:0] normFinalMant;

  reg [31:0] finalClz;

  always @(posedge clk or posedge enable)
  begin
    if (enable == 1)
    begin
      // Unpack the floats and force positive Mantissas by exploiting the negation
      UnpackFloat(a, a[31:31], aMant, aExp);
      UnpackFloat(b, b[31:31], bMant, bExp);
  
      // Multply the mantissas together and do shift compensation
      mulMant = aMant * bMant;
      abMant = mulMant[54:23];
  
      // Figure out leading zero count
      CLZ(abMant, abClz);
  
      // Normalize to 8 leading zeros
      NormalizeMantissa(abMant, abClz, abNormMant);
      abExp = aExp + bExp + (8 - abClz) - 127;

      // Figure out sign of abTotal
      abSign = a[31:31] ^ b[31:31];
      if (abSign == 1)
      begin
        abNormMant = (~abNormMant) + 1;
      end
  
      // Now figure out the large and small parts of the sum
      if (abExp < c[30:23])
      begin
        alphaExp = abExp;
        alphaMant = abNormMant;

        UnpackFloat(c, c[31:31], betaMant, betaExp);
      end
      else
      begin
        betaExp = abExp;
        betaMant = abNormMant;

        UnpackFloat(c, c[31:31], alphaMant, alphaExp);
      end

      // Add the mantissas together, shifting the smaller exp one
      SignedShiftRight(alphaMant, betaExp - alphaExp, finalMant);
      finalMant = finalMant + betaMant;
  
      // Figure out sign of total
      if (finalMant[31:31] == 1)
      begin
        finalSign = 1;
        finalMant = (~finalMant) + 1;
      end
      else
      begin
        finalSign = 0;
      end
  
      // Figure out leading zero count
      CLZ(finalMant, finalClz);
  
      // Leading zeros should be 8, so shift to that
      NormalizeMantissa(finalMant, finalClz, normFinalMant);
  
      // Save the result
      out[31:31] = finalSign;
      out[30:23] = betaExp + (8 - finalClz);
      out[22:0] = normFinalMant[22:0];
    end
    else
    begin
      out = 'hdef123;
    end
  end
  
endmodule // floating