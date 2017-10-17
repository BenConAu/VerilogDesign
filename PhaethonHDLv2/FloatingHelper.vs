struct PackedFloat
{
    bool Sign;
    uint8 Exponent;
    uint<23> Mantissa;
}

uint32 GetUnsignedMant(PackedFloat num)
{
    // Make an unsigned representation of the mantissa in 9.23 form
    return { 0b000000001, num.Mantissa };
}

struct UnpackedFloat
{
    uint32 Mantissa;
    uint8 Exponent;
}

PackedFloat FromUInt(uint32 inVal)
{
    return PackedFloat(
        inVal[31:31], 
        inVal[30:23], 
        inVal[22:0]);
}

UnpackedFloat UnpackFloat(
  PackedFloat num,
  bool neg)
{
    // Create 2s complement of that based on negation bit and sign
    // bit of the input
    if ((num.Sign ^ neg))
    {
        return UnpackedFloat(
            1 + ~GetUnsignedMant(num),
            num[30:23]);
    }
    else
    {
        return UnpackedFloat(
            GetUnsignedMant(num),
            num[30:23]);
    }
}

uint32 GetLeading(bool bit, uint8 shift)
{
    if (bit)
    {
        return (0xffffffff << (32 - shift));
    }
    else
    {
        return 0;
    }
}

uint32 SignedShiftRight(
  uint32 in,
  uint8 shift)
{
    // Blend together a leading value with the actual shift
    return (GetLeading(in[31:31], shift) | (in >> shift));
}

uint32 CLZ<4>(uint<4> in)
{
    switch (in)
    {
        case 0b0000: { return 4; }
        case 0b0001: { return 3; }
        case 0b0010: { return 2; }
        case 0b0011: { return 2; }
        case 0b0100: { return 1; }
        case 0b0101: { return 1; }
        case 0b0110: { return 1; }
        case 0b0111: { return 1; }
        case 0b1000: { return 0; }
        case 0b1001: { return 0; }
        case 0b1010: { return 0; }
        case 0b1011: { return 0; }
        case 0b1100: { return 0; }
        case 0b1101: { return 0; }
        case 0b1110: { return 0; }
        case 0b1111: { return 0; }
    }
}

// Counting power of two bits - break it down
uint32 CLZ<N>(uint<N> in)
{
    if (in[N - 1:N/2] == 0)
    {
        // Top half of input is zero, so count zeros of rest and add
        return (N/2 + CLZ<N/2>(in[N/2 - 1:0]));
    }
    else
    {
        // Top half is not zero, so count of top half is our value
        return CLZ<N/2>(in[N-1:N/2]);
    }
}

uint<23> NormalizeMantissa(uint32 Mantissa, uint32 LeadingZeroCount)
{
    // Leading zeros should be 8, so shift to that
    if (LeadingZeroCount >. 8)
    {
        return Mantissa << (LeadingZeroCount - 8);
    }
    else
    {
        return Mantissa >> (8 - LeadingZeroCount);
    }
}
