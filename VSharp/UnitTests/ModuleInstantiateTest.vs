module LittleModule(
	clock clk,
	uint8 mIn,
	out uint16 mOut
	)
{
	state initial
	{
		mOut = { mIn, mIn };
	}
}

module ModuleInstantiate(
	out uint<16> out1
	)
{
	clock clk;
	uint8 var1;
	wire uint16 var2;

	LittleModule m1 = LittleModule(clk, var1, out var2);

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("var1 = %h, var2 = %h", var1, var2);

		var1 = 123u8;

		transition EndState;
	}

	state EndState
	{
	}
}
