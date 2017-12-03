module BitSelectionTest(
	out uint64 out1
	)
{
	clock clk;

	uint32 inval;

	drive
	{
		0: inval = 2;
		100: __finish;
	}

	uint32 DummyFunc(uint32 a)
	{
		if (a == 1)
		{
			return a + 10;
		}
		else
		{
			return a * 10;
		}
	}

	state initial
	{
		__monitor("out = %h", out1);

		out1 = { DummyFunc(inval), DummyFunc(inval) };
	}
}
