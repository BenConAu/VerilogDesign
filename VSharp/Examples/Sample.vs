module DemoModule(
	byte in1,
	out byte out1
	)
{
	state initial
	{
		_ExampleRegister = 0;

		transition StartState;
	}

	state StartState
	{
		_ExampleRegister = ExampleRegister + 1;
		
		transition EndState;
	}

	state EndState
	{
		_ExampleRegister = ExampleRegister - 1;
		
		transition StartState;
	}

	byte _ExampleRegister;
}
