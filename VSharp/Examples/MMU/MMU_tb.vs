import "MemoryController.vs";

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

module MMU_TestBench()
{  
  // Define the clock to drive the circuit
  clock clk;

  // The value that the controller returned
  wire uint32 RamOutput;

  // The controller reports its status
  wire ControllerStatus mcStatus;

  // The address that we provide to the controller
  uint32 mcRamAddress;

  // The value we want to write to RAM
  uint32 mcRamIn;

  // Whether we want a read or a write
  bool mcRequest;
  bool mcWriteEnable;

  // Whether we want virtual addressing
  bool mcAddrVirtual;

  // Whether we are in kernel mode
  bool mcExecMode;

  // The value that we want to write to physical RAM
  wire uint32 phRamRead;

  wire uint32 phRamWrite;
  wire uint32 phRamAddress;
  wire bool  phRequest;
  wire bool  phWriteEnable;
  wire uint32 debug;
  wire uint32 ptAddress;

  PhysicalRAM ram = PhysicalRAM(clk, phRamAddress, phWriteEnable, phRamWrite, out phRamRead);

	drive
	{
		100: __finish;
	}

  // Fake RAM
  state initial
  {
    // No funny business with kernel mode or virtual memory
    mcExecMode = 0b0;
    mcAddrVirtual = 0b0;

    mcRamAddress = 0;
    mcRequest = true;
    mcWriteEnable = true;
    mcRamIn = 0x123;

    transition WaitWrite1;
  }

  state WaitWrite1
  {
    //__display("WaitWrite1 Status = %h", mcStatus);

    if (mcStatus == ControllerStatus.MCReady)
    {
      //__display("First write complete!");

      mcRequest = true;
      mcWriteEnable = false;

      transition WaitRead1;
    }
    else
    {
      mcRequest = false;
    }
  }

  state WaitRead1
  {
    //__display("WaitRead1 Status = %h", mcStatus);

    mcRequest = false;

    if (mcStatus == ControllerStatus.MCReady)
    {
      //__display("First read of %h complete!", RamOutput);

      transition End;
    }
  }

  state End
  {
  }

  MemoryController MMU1 = MemoryController(
    clk,                      // [Input] The clock driving the controller
    out RamOutput,            // [Output] RAM at requested address
    out mcStatus,             // [Output] Status of controller (0 means not ready, 1 means ready, 2 means error)
    mcRamAddress,             // [Input] RAM address requested
    mcRamIn,                  // [Input] RAM to write
    mcRequest,                // [Input] RAM read request
    mcWriteEnable,            // [Input] RAM write request
    mcAddrVirtual,            // [Input] Virtual flag for RAM
    mcExecMode,               // [Input] Execution mode for RAM
    phRamRead,                // [Input]  RAM at requested address
    out phRamAddress,         // [Output] RAM address requested
    out phRamWrite,           // [Output] RAM to write
    out phRequest,            // [Output] RAM read request
    out phWriteEnable,        // [Output] RAM write request
    ptAddress,                // [Input] Page table address
    out debug                 // [Output] Debug port
    );
}
