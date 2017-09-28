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

module GenericFunctionTest()
{
	clock clk;

	// Test something initialized
	uint32 HandyNum = 0xabc;
    uint32 CLZ_Handy;

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("TestVal = %h", CLZ_Handy);

        // Count leading zeroes
        CLZ_Handy = CLZ<32>(HandyNum);

        // Modify the count
        HandyNum = HandyNum << 3;
	}
}
