module AlwaysStateTest()
{
	clock clk;
	uint32 val;
	uint32 val2;

	drive
	{
		100: __finish;
	}

	state always
	{
		if (val == 0x123)
		{
			val2 = 0xdeadbeef;
		}
		else
		{
			val2 = 0x600dbeef;
		}
	}

	state initial
	{
		__monitor("val = %h, val2 = %h", val, val2);

		val = 0x123;

		transition StartState;
	}

	state StartState
	{
		val = 0xabc;

		transition EndState;
	}

	state EndState
	{
		val = 0xbeef;
	}
}
