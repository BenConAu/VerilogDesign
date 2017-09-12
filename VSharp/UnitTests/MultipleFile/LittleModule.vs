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
