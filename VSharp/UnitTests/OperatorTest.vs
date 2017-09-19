module OperatorTest(
	out uint32 out1
	)
{
	clock clk;
	uint32 a;
	uint32 b;
	
	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("a = %h and b = %h and out1 = %h", a, b, out1);

		a = 0;
		b = 1;
		out1 = 0;

		transition StartState;
	}

	state StartState
	{
		if (a == 0 && b == 1)
		{
			out1 = (2 + b) * (1 + b);
		}
	}
}
