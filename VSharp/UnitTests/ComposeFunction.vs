module DoubleExpansionTest(
	out uint32 out1
	)
{
	clock clk;

	drive
	{
		100: __finish;
	}

	uint32 TestFunc1(uint32 input)
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

	uint32 TestFunc2(uint32 input)
	{
		return input + 50;
	}

	state initial
	{
		__monitor("out1 = %h", out1);

		out1 = 0;

		transition StartState;
	}

	state StartState
	{
		out1 = TestFunc1(TestFunc2(1));

		//transition EndState;
	}

	//state EndState
	//{
		//out1 = TestFunc2(TestFunc1(1));
	//}
}
