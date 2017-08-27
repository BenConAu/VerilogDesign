module BitSelectionTest(
	out uint<16> out1
	)
{
	clock clk;
	uint<32> val;

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("val = %h, out1 = %h", val, out1);

		val = 0x123;

		transition StartState;
	}

	state StartState
	{
		out1 = val[19:4];
	}
}
