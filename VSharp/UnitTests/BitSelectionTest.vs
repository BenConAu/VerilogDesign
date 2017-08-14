module BitSelectionTest(
	uint<32> in1,
	out uint<16> out1
	)
{
	state initial
	{
		transition StartState;
	}

	state StartState
	{
		out1 = in1[19:4];
	}
}
