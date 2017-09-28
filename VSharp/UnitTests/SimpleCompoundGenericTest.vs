uint32 Foo<16>(uint<16> in)
{
    return { 0u16, in };
}

// Counting power of two bits - break it down
uint32 Foo<N>(uint<N> in)
{
    return Foo<N/2>(in[31:16]);
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

        CLZ_Handy = Foo<32>(HandyNum);
	}
}
