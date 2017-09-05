module GlomTest(
	out uint32 out1
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

		val = 0x12345678;

		transition StartState;
	}

	state StartState
	{
		out1 = { val[31:28], val[3:0] };
	}
}
