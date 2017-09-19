module SwitchSelectionTest(
	out uint<16> out1
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

		val = 0x1;

		transition StartState;
	}

	state StartState
	{
		switch (val)
		{
			case 0:
			{
				out1 = 0x123u16;
				val = 1;
			}

			case 1:
			{
				out1 = 0xabcu16;
				val = 0;
			}
		}
	}
}
