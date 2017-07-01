module DemoModule(
	byte in1,
	out byte out1
	)
{
	DemoModule()
	{
		_ExampleRegister = 0;
	}

	initial state StartState
	{
		_ExampleRegister = ExampleRegister + 1;
		
		transition(EndState);
	}

	state EndState
	{
		_ExampleRegister = ExampleRegister - 1;
		
		transition(StartState);
	}

	byte _ExampleRegister;
}
