struct TestStruct
{
	uint32 TestMember;
	uint32 OtherMember;
}

module BitSelectionTest(
	out uint<16> out1
	)
{
	clock clk;
	uint<32> val;
	TestStruct val2;

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("val = %h, val2 = %h, out1 = %h", val, val2.TestMember, out1);

		val = 0x123;
		val2.TestMember = 0x456;

		transition StartState;
	}

	state StartState
	{
		out1 = val[19:4];

		transition EndState;
	}

	state EndState
	{
		out1 = val2.TestMember[19:4];
	}
}
