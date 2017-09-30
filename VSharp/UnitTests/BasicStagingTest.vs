module StagingExample(
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
        if (moduleInput >. 100)
        {
            firstStageOutput = moduleInput[31:16];
        }
        else
        {
            firstStageOutput = 10u16;
        }
    }

    stage Finalize(
        uint16 firstStageOutput
        )
    {
        __monitor("Output = %h", moduleOutput);

        moduleOutput = { 1u16, firstStageOutput };
    }
}