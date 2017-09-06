module ShortCircuit(
	out uint32 out1
	)
{
	clock clk;
	uint<32> val;

	drive
	{
		100: __finish;
	}

	bool TestFunction(uint32 inp)
	{
		if (inp == 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	state initial
	{
		__monitor("val = %h, out1 = %h", val, out1);

		val = 0x123;

		transition StartState;
	}

	state StartState
	{
		if (TestFunction(val))
		{
			out1 = 25;
		}
		else
		{
			out1 = 15;
		}
	}
}
