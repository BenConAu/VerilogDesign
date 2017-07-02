module DemoModule(
	word in1,
	out word out1
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

	word _ExampleRegister;
}
