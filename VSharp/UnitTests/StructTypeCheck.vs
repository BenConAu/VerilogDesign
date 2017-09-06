struct Foo
{
	uint32 bar;
}

module BitSelectionTest(
	out uint32 out1
	)
{
	clock clk;
	uint32 bogus;

	drive
	{
		100: __finish;
	}

	uint32 Crack(Foo f)
	{
		return f.bar;
	}

	state initial
	{
		__monitor("out1 = %h", out1);

		bogus = 123;

		transition StartState;
	}

	state StartState
	{
		out1 = Crack(Foo(bogus));		
	}
}
