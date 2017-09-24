// Counting a single bit is easy
//uint32 CLZ<1>(uint<1> in)
//{
    //return { 0u31, in };
//}

// Counting power of two bits - break it down
//uint32 CLZ<N>(uint<N> in)
//{
    //if (in[N - 1:N/2] == 0)
    //{
        //return (N/2 + CLZ<N/2>(in[N/2 - 1:0]));
    //}
    //else
    //{
        //return CLZ<N/2>(in[N/2 - 1:0]);
    //}
//}


// Counting power of two bits - break it down
uint32 TestFunc<N>(uint32 in)
{
    return N;
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

        //CLZ_Handy = CLZ<32>(HandyNum);
        CLZ_Handy = TestFunc<32>(HandyNum);
	}
}
