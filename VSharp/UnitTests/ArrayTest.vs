module ArrayTest(
	uint32 in1,
	out uint32 out1
	)
{
	clock clk;
	uint32 arr[4];
	uint32 index;

	drive
	{
		10: index = 1;
		10: index = 2;
		100: __finish;
	}

	state initial
	{
		__monitor("%h", out1);

		out1 = 0;
		arr[0] = 1;
		arr[1] = 3;
		arr[2] = 5;
		arr[3] = 7;
		transition StartState;
	}

	state StartState
	{
		out1 = arr[index];

		if (index .< 3)
		{
			index = index + 1;
		}
	}
}
