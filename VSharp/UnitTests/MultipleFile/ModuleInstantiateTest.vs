import "LittleModule.vs";

module ModuleInstantiate(
	out uint<16> out1,
	out wire uint32 testOutWire
	)
{
	clock clk;
	uint8 var1;
	Foo inFoo;
	wire uint16 var2;
	wire Foo outFoo;

	LittleModule m1 = LittleModule(clk, var1, inFoo, out var2, out outFoo, out testOutWire);

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("var1 = %h, var2 = %h, testWire = %h", var1, var2, testOutWire);

		var1 = 123u8;

		transition EndState;
	}

	state EndState
	{
	}
}
