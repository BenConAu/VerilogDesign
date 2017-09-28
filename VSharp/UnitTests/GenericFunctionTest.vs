// Counting a single bit is easy
uint32 CLZ<1>(uint<1> in)
{
    if (in)
    {
        return 0;
    }
    else
    {
        return 1;
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
