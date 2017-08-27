enum Foo
{
	Bar,
	Baz,
}

module EnumTest(
	uint<32> in1,
	out Foo out1
	)
{
	clock clk;
	
	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("Foo enum = %h", out1);

		out1 = Foo.Bar;

		transition StartState;
	}

	state StartState
	{
		if (out1 == Foo.Bar)
		{
			out1 = Foo.Baz;
		}
		else
		{
			out1 = Foo.Bar;
		}
	}
}
