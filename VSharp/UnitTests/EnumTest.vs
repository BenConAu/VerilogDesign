enum Foo
{
	Bar,
	Baz,
	Baffle,
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
			// Try out constructor
			out1 = Foo(2u2);
		}
	}
}
