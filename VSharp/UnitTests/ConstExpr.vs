module ConstExprTest(
	out uint<16> out1
	)
{
	clock clk;
	const uint32 TestConstant = 4;
	uint32 TestArray1[TestConstant];

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("TestVal = %h", TestArray1[TestConstant - 1]);

		TestArray1[TestConstant - 1] = 0x123;

		transition EndState;
	}

	state EndState
	{
		TestArray1[TestConstant - 1] = 0xabc;
	}
}
