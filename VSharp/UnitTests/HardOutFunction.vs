module DoubleExpansionTest(
	out uint32 out1,
	out uint32 out2,
	out uint32 out3
	)
{
	clock clk;

	drive
	{
		100: __finish;
	}

	uint32 TestOutFunc(uint32 input, out uint32 outVal, out uint32 outVal2)
	{
		if (input == 0)
		{
			outVal = 1;
			outVal2 = 3;
			return 1;
		}
		else
		{
			outVal = 2;
			outVal2 = 5;
			return 7;
		}
	}

	state initial
	{
		__monitor("out1 = %h, out2 = %h, out3 = %h", out1, out2, out3);

		out1 = 10;
		out2 = 20;
		out3 = 30;

		transition StartState;
	}

	state StartState
	{
		out3 = TestOutFunc(10, out out1, out out2);
	}
}
