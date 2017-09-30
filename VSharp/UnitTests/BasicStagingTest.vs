module StagingExample(
    uint32 moduleInput,         // Some value going to the module
    out uint32 moduleOutput     // Some value going out of the module
    )
{
    clock clk;

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
            firstStageOutput = 0u16;
        }
    }

    stage Finalize(
        uint16 firstStageOutput
        )
    {
        moduleOutput = { 1u16, firstStageOutput };
    }
}