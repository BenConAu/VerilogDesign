module OperatorTest(
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
		if (in1 == 0 && in1 == 1)
		{
			out1 = 1;
		}
	}
}
