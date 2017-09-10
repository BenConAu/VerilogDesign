module LittleModule(
	clock clk,
	uint8 input,
	out uint16 output
	)
{
	state initial
	{
		output = { input, input };
	}
}

module ModuleInstantiate(
	out uint<16> out1
	)
{
	clock clk;
	uint8 var1;
	uint16 var2;

	LittleModule m1 = LittleModule(clk, var1, out var2);

	drive
	{
		100: __finish;
	}

	state initial
	{
		__monitor("var1 = %h", var1);

		var1 = 123u8;
	}
}
