uint16 Contrived(uint32 in)
{
    return 1u16;
}

uint32 Contrived2(uint16 in)
{
    return in + 6u16;
}

module(nonblocking) StagingExample(
    uint32 moduleInput,         // Some value going to the module
    out uint32 moduleOutput     // Some value going out of the module
    )
{
    clock clk;

	drive
	{
		100: __finish;
	}

    stage Unpack(
        out uint16 firstStageOutput
        )
    {
        firstStageOutput = Contrived(moduleInput);
    }

    stage Finalize(
        uint16 firstStageOutput
        )
    {
        __monitor("Output = %h", moduleOutput);

        moduleOutput = Contrived2(firstStageOutput);
    }
}