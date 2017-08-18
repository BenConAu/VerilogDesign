module ArrayTest(
	uint32 in1,
	out uint32 out1
	)
{
	uint32 arr[8];

	state initial
	{
		transition StartState;
	}

	state StartState
	{
		out1 = arr[0];
	}
}
