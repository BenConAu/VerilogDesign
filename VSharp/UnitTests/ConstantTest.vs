module EnumTest(
	out uint32 out1,
	out bool out2,
	out uint<4> out3
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
		out3 = 1u4;

		transition StartState;
	}

	state StartState
	{
		out1 = 0x1u32;
		out2 = true;
		out3 = 1u4;

		transition EndState;
	}

	state EndState
	{
		out1 = 0xf;
		out2 = true;
		out3 = 0b1001;
	}
}
