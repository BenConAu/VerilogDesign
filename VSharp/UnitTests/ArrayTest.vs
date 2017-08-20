module ArrayTest(
	uint32 in1,
	out uint32 out1
	)
{
	uint32 arr[8];
	uint32 index;

	drive
	{
		10: index = 1;
		10: index = 2;
	}

	state initial
	{
		transition StartState;
	}

	state StartState
	{
		out1 = arr[index];
		index = index + 1;
	}
}
