module(nonblocking) StagingExample(
    uint32 moduleInput,       // Some value going to the module
    out uint32 moduleOutput   // Some value going out of the module
    )
{
    clock clk;

	drive
	{
		100: __finish;
	}
    
    stage Unpack(
        out uint16 up1,
        out uint16 up2
        )
    {
        if (moduleInput >. 100)
        {
            up1 = moduleInput[31:16];
            up2 = moduleInput[15:0];
        }
        else
        {
            up1 = 0u16;
            up2 = 0u16;
        }
    }

    stage Process(
        uint16 up1,
        uint16 up2,
        out uint16 Processed
        )
    {
        if (up1 == 1u16)
        {
            Processed = up1 + up2;
        }
        else
        {
            Processed = 1u16;
        }
    }

    stage Finalize(
        uint16 Processed
        )
    {
        __monitor("Output = %h", moduleOutput);

        moduleOutput = { 0xabcu16, Processed };
    }
}