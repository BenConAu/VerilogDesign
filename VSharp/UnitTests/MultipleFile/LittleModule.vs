struct Foo
{
	uint32 x;
}

module LittleModule(
	clock clk,
	uint8 mIn,
	Foo inFoo,
	out uint16 mOut,
	out Foo outFoo
	)
{
	state initial
	{
		mOut = { mIn, mIn };
	}
}
