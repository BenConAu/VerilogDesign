module DemoModule(
	uint<32> in1,
	out uint<32> out1
	)
{
	void CalcOtherThing(
		uint32 input,
		uint32 add,
		out uint32 output)
	{
		output = input + add;
	}

	void CalcThing(
		uint32 input,
		out uint32 output)
	{
		CalcOtherThing(input, 2, out output);
	}

	state initial
	{
		_ExampleRegister = 0;

		transition StartState;
	}

	state StartState
	{
		CalcThing(_ExampleRegister, out _ExampleRegister);
		
		transition EndState;
	}

	state EndState
	{
		_ExampleRegister = _ExampleRegister - 1;
		
		transition StartState;
	}

	uint32 _ExampleRegister;
	uint16 _ExampleWord;
	uint8 _ExampleByte;
}
