struct TestStruct
{
	bool a;
	uint32 b;
	uint8 c;
}

module StructTest(
	out uint32 out1
	)
{
	clock clk;
	TestStruct test;

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("%h", out1);

		test.a = false;
		test.b = 100;
		test.c = 10u8;
		out1 = 0;

		transition StartState;
	}

	state StartState
	{
		out1 = test.b;

		transition EndState;
	}

	state EndState
	{
		out1 = 200;
	}
}
