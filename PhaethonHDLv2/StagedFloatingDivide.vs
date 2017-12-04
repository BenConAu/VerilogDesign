import "FloatingHelper.vs";

module(blocking) FloatingDivide(
    clock clk,
    uint32 inputA,
    uint32 inputB,
    out uint32 OutValue)
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
        out UnpackedFloat UnpackedB,
        out bool TotalSign)   
    {
        // Sign is derived from arguments
        TotalSign = a.Sign ^ b.Sign;    

        // Use sign bit to force unpacked to be positive 
        UnpackedA = UnpackFloat(a, a[31:31]);
        UnpackedB = UnpackFloat(b, b[31:31]);
    }

    stage BeginCalc(
        UnpackedFloat UnpackedA,
        UnpackedFloat UnpackedB,
        out uint64 LongMantissa)
    {
        // Make a 64 bit LHS
        LongMantissa = { 0, UnpackedA.Mantissa };
    }

    stage EndCalc(
        UnpackedFloat UnpackedA,
        UnpackedFloat UnpackedB,
        uint64 LongMantissa,
        out uint64 TotalMantissa)
    {
        // Divide the mantissas together and do shift compensation
        TotalMantissa = LongMantissa << 23 / UnpackedB.Mantissa;
    }

    stage CalculateNormalizeParameters(
        uint32 TotalMantissa,
        out uint32 LeadingZeroCount)
    {
        LeadingZeroCount = CLZ<32>(TotalMantissa[31:0]);
    }
  
    stage Complete(
        UnpackedFloat UnpackedA,
        UnpackedFloat UnpackedB,
        bool TotalSign,
        uint64 TotalMantissa,
        uint32 LeadingZeroCount,
        out PackedFloat PackedResult)
    {
        // Sign is easy
        PackedResult.Sign = TotalSign;

        // Leading zeros should be 8, so shift to that
        PackedResult.Mantissa = NormalizeMantissa(TotalMantissa[31:0], LeadingZeroCount);
  
        // Repack the exponent
        PackedResult.Exponent = UnpackedA.Exponent - UnpackedB.Exponent + (8 - LeadingZeroCount) + 127;
    }

    stage FinishConvert(
        PackedFloat PackedResult
        )
    {
        OutValue = { PackedResult.Sign, PackedResult.Exponent, PackedResult.Mantissa };
    }    
}
