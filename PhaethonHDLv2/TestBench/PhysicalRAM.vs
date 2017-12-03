module PhysicalRAM(
  clock clk,
  uint32 address,
  bool WriteEnable,
  uint32 WriteValue,
  out uint32 ReadValue
  )
{
  // Storage for the fake RAM
  uint8 fileRam[65536];

  // Filename that we get the RAM init from
  uint<1024> testName;

  state initial
  {
    if (__valueargs("ROMFILE=%s", testName))
    {
      __readmemh(testName, fileRam, 0);
    }

    transition MemReadDone;    
  }

  state MemReadDone
  {
    // We stay here forever, the always state does the rest
  }

  state always
  {
    // __monitor(
    //   "%d | RAM 0x0 = %h:%h:%h:%h:%h:%h:%h:%h | RAM 0x7000 = %h:%h:%h:%h:%h:%h:%h:%h | WriteEnable = %h | RAM value read = %h",
    //   __time,
    //   fileRam[0], 
    //   fileRam[1], 
    //   fileRam[2], 
    //   fileRam[3], 
    //   fileRam[4], 
    //   fileRam[5], 
    //   fileRam[6], 
    //   fileRam[7],
    //   fileRam[0x7000], 
    //   fileRam[0x7001], 
    //   fileRam[0x7002], 
    //   fileRam[0x7003], 
    //   fileRam[0x7004], 
    //   fileRam[0x7005], 
    //   fileRam[0x7006], 
    //   fileRam[0x7007], 
    //   WriteEnable,
    //   ReadValue);

    if (WriteEnable)
    {
      //__display("Writing %h into %h", WriteValue, address);
      fileRam[address] = WriteValue[7:0];
      fileRam[address + 1] = WriteValue[15:8];
      fileRam[address + 2] = WriteValue[23:16];
      fileRam[address + 3] = WriteValue[31:24];
    }
    else
    {
      //__display("Retrieving address %h", address);

      ReadValue[7:0] = fileRam[address];
      ReadValue[15:8] = fileRam[address + 1];
      ReadValue[23:16] = fileRam[address + 2];
      ReadValue[31:24] = fileRam[address + 3];
    }
  }
}
