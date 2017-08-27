module EnumTest(
	out uint32 out1,
	out bool out2
	)
{
	clock clk;

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("uint32 value = %h, boolean value = %h", out1, out2);

		out1 = 0;
		out2 = false;

		transition StartState;
	}

	state StartState
	{
		out1 = 1;
		out2 = true;
	}
}
