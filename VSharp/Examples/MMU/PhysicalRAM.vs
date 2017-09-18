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

  state initial
  {
    __monitor(
      "%d | RAM = %h:%h:%h:%h:%h:%h:%h:%h | WriteEnable = %h | RAM value read = %h",
      __time,
      fileRam[0], 
      fileRam[1], 
      fileRam[2], 
      fileRam[3], 
      fileRam[4], 
      fileRam[5], 
      fileRam[6], 
      fileRam[7],
      WriteEnable,
      ReadValue);

    if (WriteEnable)
    {
      //$display("Writing %h into %h", phRamWrite, phRamAddress);
      fileRam[address] = WriteValue[7:0];
      fileRam[address + 1] = WriteValue[15:8];
      fileRam[address + 2] = WriteValue[23:16];
      fileRam[address + 3] = WriteValue[31:24];
    }
    else
    {
      //$display("Retrieving address %h", phRamAddress);
      ReadValue[7:0] = fileRam[address];
      ReadValue[15:8] = fileRam[address + 1];
      ReadValue[23:16] = fileRam[address + 2];
      ReadValue[31:24] = fileRam[address + 3];
    }
  }
}
