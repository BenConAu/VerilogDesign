module StagingExample(
    uint32 a,       // Some value going to the module
    out uint32 b    // Some value going out of the module
    )
{
    stage Unpack(
        out uint16 up1,
        out uint16 up2
        )
    {
        if (a >. 100)
        {
            up1 = a[31:16];
            up2 = a[15:0];
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
        out uint16 middle
        )
    {
        if (up1 == 1u16)
        {
            middle = up1 + up2;
        }
        else
        {
            middle = 1u16;
        }
    }

    stage Finalize(
        uint16 middle
        )
    {
        b = { middle, middle };
    }
}