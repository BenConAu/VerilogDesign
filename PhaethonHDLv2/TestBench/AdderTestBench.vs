import "../StagedFloatingAdder.vs";

module AdderTest(
	out wire uint32 total
	)
{
	clock clk;

	uint32 a;
	uint32 b;

	FloatingAdd adder = FloatingAdd(clk, a, b, false, out total);

	drive
	{
		0: a = 0x3f800000;
		0: b = 0x40000000;
		100: __finish;
	}

	state initial
	{
		__monitor("total = %h", total);
	}
}
