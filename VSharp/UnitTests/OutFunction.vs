module DoubleExpansionTest(
	out uint32 out1
	)
{
	clock clk;

	drive
	{
		100: __finish;
	}

	void TestOutFunc(uint32 input, out uint32 outVal)
	{
		if (input == 0)
		{
			outVal = 1;
		}
		else
		{
			outVal = 2;
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
		TestOutFunc(10, out out1);
	}
}
