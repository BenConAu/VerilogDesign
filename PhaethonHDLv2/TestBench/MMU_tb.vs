import "MemoryController.vs";
import "PhysicalRAM.vs";

module MMU_TestBench()
{  
  // Define the clock to drive the circuit
  clock clk;

  // The value that the controller returned
  wire uint32 RamOutput;

  // The controller reports its status
  wire ControllerStatus mcStatus;

  // The request that we provide to the controller
  MemoryRequest mcRequest;

  // Whether we are making a request from the controller
  ControllerCommand mcCommand;

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
  uint32 ptAddress;

  // Somewhere to store PT entries
  PTEntry entry1;

  PhysicalRAM ram = PhysicalRAM(clk, phRamAddress, phWriteEnable, phRamWrite, out phRamRead);

	drive
	{
		300: __finish;
	}

  // Initialization
  state initial
  {
    // No funny business with kernel mode or virtual memory yet
    mcExecMode = 0b0;
    mcAddrVirtual = false;

    // Page table will be at zero memory
    ptAddress = 0x0;

    // Set up stuff we want to write out
    entry1 = PTEntry(true, false, 0u22, 0xabcu20, 7u20);

    transition BeginPTWrite1;
  }

  // Begin write of the first uint32 of the PT
  state BeginPTWrite1
  {
    mcRequest = MemoryRequest(
      0x55e0,         // Address - 0xabc * 8 == 0x55e0
      entry1[63:32],  // What to write, MSB of PT entry
      true);          // This is a write

    mcCommand = ControllerCommand.Request;

    transition EndPTWrite1;    
  }

  // When that write is complete, begin write of second uint32
  state EndPTWrite1
  {
    if (mcStatus == ControllerStatus.Ready)
    {
      // Write LSB of PT entry
      mcRequest.Address = 0x55e4;
      mcRequest.WriteData = entry1[31:0];

      mcCommand = ControllerCommand.Request;

      transition EndPTWrite2;
    }
    else
    {
      mcCommand = ControllerCommand.None;
    }
  }

  // After writing both entries, now enable virtual memory
  // and write a value to the beginning of the virtual page
  state EndPTWrite2
  {
    if (mcStatus == ControllerStatus.Ready)
    {
      // Enable virtual memory
      mcAddrVirtual = true;
      
      // Write to 0xabc000, which should write to 0x7000
      mcRequest.Address = 0xabc000;
      mcRequest.WriteData = 0xbeeff00d;

      mcCommand = ControllerCommand.Request;

      transition BeginVirtualRead;
    }
    else
    {
      mcCommand = ControllerCommand.None;
    }
  }

  // Test that reading back that value you just wrote
  // works just fine.
  state BeginVirtualRead
  {
    if (mcStatus == ControllerStatus.Ready)
    {
      // Read from 0xabc000, which should read from 0x7000
      mcRequest.WriteEnable = false;

      mcCommand = ControllerCommand.Request;

      transition EndPTRead1;
    }
    else
    {
      mcCommand = ControllerCommand.None;
    }
  }

  state EndPTRead1
  {
    //__display("WaitRead1 Status = %h", mcStatus);

    mcCommand = ControllerCommand.None;

    if (mcStatus == ControllerStatus.Ready)
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
    mcRequest,                // [Input] Controller request
    mcCommand,                // [Input] Controller command
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
