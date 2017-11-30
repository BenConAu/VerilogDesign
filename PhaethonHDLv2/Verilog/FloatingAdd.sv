import "FloatingHelper.vs";

struct PackedFloat
{
    bool Sign;
    uint8 Exponent;
    uint<23> Mantissa;
}

struct UnpackedFloat
{
    uint32 A_Mantissa;
    uint8 A_Exponent;
}

struct UnpackedArguments
{
    UnpackedFloat A;
    UnpackedFloat B;
}

UnpackedArguments UnpackArguments(PackedFloat a, PackedFloat b, bool negate)
{
    // Unpack the mantissa, make b the one with larger exponent
    // Always negate b if negation is asked for since it is the
    // second operand.
    if (a.Exponent < b.Exponent)      
    {
        return UnpackedArguments(
            UnpackFloat(a, false),
            UnpackFloat(b, negate));
    }
    else
    {
        return UnpackedArguments(
            UnpackFloat(b, negate),
            UnpackFloat(a, false));
        )
    }
}

uint32 CalculateTotalMantissa(UnpackedArguments args, )
{

}

// Stages for adding numbers
// Stage 1 - unpack into signed mantissas -> signedMantA, signedMantB
// Stage 2 - signed shift mantissas to same base -> signedShiftedMantA,  signedShiftedMantB
// Stage 2 - add mantissas -> totalMant
// Stage 3 - Set sign bit and de-sign the total mantissa -> signedTotalMant, sign
// Stage 4 - Adjust mantissa and exponent to correct leading bits -> OutValue

module FloatingAdd(
    out PackedFloat OutValue,
    out uint32 debug,
    PackedFloat a,
    PackedFloat b,
    bool negate)
{

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
      UnpackedArguments args = UnpackArguments(a, b, negate);

      // Add the mantissas together, shifting the smaller exp one
      totalMant = SignedShiftRight(aMant, bExp - aExp) + bMant;
  
      // Figure out sign of total
      if (totalMant[31:31] == 1)
      begin
        OutValue.Sign = true;
        totalMant = (~totalMant) + 1;
      end
      else
      begin
        OutValue.Sign = false;
      end
  
      // Leading zeros should be 8, so shift to that
      OutValue.Mantissa = NormalizeMantissa(totalMant, CLZ(totalMant))[22:0];
  
      OutValue.Exponent = bExp + (8 - clz);
    end
    else
    begin
      out <= 'habc;
      debug <= 0;
    end
  end
  
endmodule // floating