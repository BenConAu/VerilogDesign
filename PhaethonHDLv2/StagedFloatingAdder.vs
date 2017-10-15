import "Verilog/FloatingHelper.vs";

// Stages for adding numbers
// Stage 1 - unpack into signed mantissas -> signedMantA, signedMantB
// Stage 2 - signed shift mantissas to same base -> signedShiftedMantA,  signedShiftedMantB
// Stage 2 - add mantissas -> totalMant
// Stage 3 - Set sign bit and de-sign the total mantissa -> signedTotalMant, sign
// Stage 4 - Adjust mantissa and exponent to correct leading bits -> OutValue

module(blocking) FloatingAdd(
    clock clk,
    out uint32 OutValue,
    uint32 inputA,
    uint32 inputB,
    bool negate)
{
    stage ConvertInputs(
        out PackedFloat a,
        out PackedFloat b)
    {
        a = FromUInt(inputA);
        b = FromUInt(inputB);
    }

    stage Unpack(
        PackedFloat a,
        PackedFloat b,
        out UnpackedFloat UnpackedA,
        out UnpackedFloat UnpackedB)
    {
        // Unpack the mantissa, make b the one with larger exponent
        // Always negate b if negation is asked for since it is the
        // second operand.
        if (a.Exponent .< b.Exponent)      
        {
            UnpackedA = UnpackFloat(a, false);
            UnpackedB = UnpackFloat(b, negate);
        }
        else
        {
            UnpackedA = UnpackFloat(b, negate);
            UnpackedB = UnpackFloat(a, false);
        }
    }

    stage AddMantissa(
        UnpackedFloat UnpackedA,
        UnpackedFloat UnpackedB,
        out uint32 TotalMantissa)
    {
        // Add the mantissas together, shifting the smaller exp one
        TotalMantissa = SignedShiftRight(UnpackedA.Mantissa, UnpackedB.Exponent - UnpackedA.Exponent) + UnpackedB.Mantissa;
    }

    stage CalculateSign(
        uint32 TotalMantissa,
        out uint32 SignedMantissa,
        out bool Sign
        )
    {
        // Figure out sign of total
        if (TotalMantissa[31:31])
        {
            Sign = true;
            SignedMantissa = (~TotalMantissa) + 1;
        }
        else
        {
            Sign = false;
            SignedMantissa = TotalMantissa;
        }
    }

    stage CalculateNormalizeParameters(
        uint32 SignedMantissa,
        out uint32 LeadingZeroCount
        )
    {
        LeadingZeroCount = CLZ<32>(SignedMantissa);
    }
  
    stage Complete(
        UnpackedFloat UnpackedB,
        bool Sign,
        uint32 SignedMantissa,
        uint32 LeadingZeroCount,
        out PackedFloat PackedResult
        )
    {
        PackedResult.Sign = Sign;

        // Leading zeros should be 8, so shift to that
        PackedResult.Mantissa = NormalizeMantissa(SignedMantissa, LeadingZeroCount);
  
        // Repack the exponent
        PackedResult.Exponent = UnpackedB.Exponent + (8 - LeadingZeroCount);
    }

    stage FinishConvert(
        PackedFloat PackedResult
        )
    {
        OutValue = { PackedResult.Sign, PackedResult.Exponent, PackedResult.Mantissa };
    }
}