module BitSelectionTest(
	out uint32 out1
	)
{
	clock clk;

	drive
	{
		100: __finish;
	}

	uint32 TestFunc(uint32 input)
	{
		if (input == 0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	state initial
	{
		__monitor("out1 = %h", out1);

		out1 = 0;

		transition StartState;
	}

	state StartState
	{
		out1 = 1 + TestFunc(10);
	}
}
