enum Foo
{
	Bar,
}

module EnumTest(
	uint<32> in1,
	out Foo out1
	)
{
	state initial
	{
		transition StartState;
	}

	state StartState
	{
		out1 = Foo.Bar;
	}
}
