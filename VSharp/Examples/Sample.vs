module DemoModule(
	reg<32> in1,
	out reg<32> out1
	)
{
	state initial
	{
		_ExampleRegister = 0;

		transition StartState;
	}

	state StartState
	{
		_ExampleRegister = _ExampleRegister + 1;
		
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
