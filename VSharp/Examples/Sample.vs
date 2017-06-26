module DemoModule(
	bit<8> in1,
	out bit<8> out1
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

	bit<8> _ExampleRegister;
}
