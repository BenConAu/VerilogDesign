module EnumTest(
	uint32 in1,
	out uint32 out1,
	out bool out2
	)
{
	state initial
	{
		transition StartState;

		out1 = 0;
		out2 = false;
	}

	state StartState
	{
		out1 = 1;
		out2 = true;
	}
}
