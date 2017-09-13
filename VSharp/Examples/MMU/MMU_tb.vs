import "MemoryController.vs";

module MMU_TestBench()
{  
  // Define the clock to drive the circuit
  clock clk;

  // Storage for the fake RAM
  uint8 fileRam[65536];

  // The value that the controller returned
  wire uint32 RamOutput;

  // The controller reports its status
  wire ControllerStatus mcStatus;

  // The address that we provide to the controller
  uint32 mcRamAddress;

  // The value we want to write to RAM
  uint32 mcRamIn;

  // Whether we want a read or a write
  bool mcReadReq;
  bool mcWriteReq;

  // Whether we want virtual addressing
  bool mcAddrVirtual;

  // Whether we are in kernel mode
  bool mcExecMode;

  // The value that we want to write to physical RAM
  uint32 phRamRead;

  wire uint32 phRamWrite;
  wire uint32 phRamAddress;
  wire bool  phReadReq;
  wire bool  phWriteReq;
  wire uint32 debug;
  wire uint32 ptAddress;

	drive
	{
    0: mcRamAddress = 0;
    0: mcWriteReq = 0b1;
    0: mcReadReq = 0b0;
    0: mcRamIn = 0x123;
    100: mcWriteReq = 0b0;
		100: __finish;
	}

  // Fake RAM
  state initial
  {
    __monitor(
      "RAM = %h:%h:%h:%h:%h:%h:%h:%h | Status = %h | MMU value read = %h", 
      fileRam[0], 
      fileRam[1], 
      fileRam[2], 
      fileRam[3], 
      fileRam[4], 
      fileRam[5], 
      fileRam[6], 
      fileRam[7],
      mcStatus,
      RamOutput);

    // No funny business with kernel mode or virtual memory
    mcExecMode = 0b0;
    mcAddrVirtual = 0b0;

    if (phReadReq == 1)
    {
      //$display("Retrieving address %h", phRamAddress);
      phRamRead[7:0] = fileRam[phRamAddress];
      phRamRead[15:8] = fileRam[phRamAddress + 1];
      phRamRead[23:16] = fileRam[phRamAddress + 2];
      phRamRead[31:24] = fileRam[phRamAddress + 3];
    }

    if (phWriteReq == 1)
    {
      //$display("Writing %h into %h", phRamWrite, phRamAddress);
      fileRam[phRamAddress] = phRamWrite[7:0];
      fileRam[phRamAddress + 1] = phRamWrite[15:8];
      fileRam[phRamAddress + 2] = phRamWrite[23:16];
      fileRam[phRamAddress + 3] = phRamWrite[31:24];
    }
  }

  MemoryController MMU1 = MemoryController(
    clk,                      // [Input] The clock driving the controller
    out RamOutput,            // [Output] RAM at requested address
    out mcStatus,             // [Output] Status of controller (0 means not ready, 1 means ready, 2 means error)
    mcRamAddress,             // [Input] RAM address requested
    mcRamIn,                  // [Input] RAM to write
    mcReadReq,                // [Input] RAM read request
    mcWriteReq,               // [Input] RAM write request
    mcAddrVirtual,            // [Input] Virtual flag for RAM
    mcExecMode,               // [Input] Execution mode for RAM
    phRamRead,                // [Input]  RAM at requested address
    out phRamAddress,         // [Output] RAM address requested
    out phRamWrite,           // [Output] RAM to write
    out phReadReq,            // [Output] RAM read request
    out phWriteReq,           // [Output] RAM write request
    ptAddress,                // [Input] Page table address
    out debug                 // [Output] Debug port
    );
}
