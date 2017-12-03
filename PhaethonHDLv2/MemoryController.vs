// Status of memory controller - it will only serve requests
// if you make a request while it is ready.
enum ControllerStatus
{
  Error,
  Waiting,
  Ready,
}

enum ControllerCommand
{
  None,
  Request,
}

struct PTEntry
{
  bool IsValid;           // If this entry is valid or not
  bool IsProtected;       // If this page is ptotected 
  uint<22> Unused;        // To make it 64 bits
  uint<20> VirtualPage;   // Page number in process space
  uint<20> PhysicalPage;  // Page number in physical RAM
}

struct MemoryRequest
{
  uint32 Address;         // The address being requested
  uint32 WriteData;       // The data to write if this is a write
  bool WriteEnable;       // Is the request a read or write
}

module MemoryController(
  clock clk,                      // [Input] The clock driving the controller
  out uint32 mcRamOut,            // [Output] RAM at requested address
  out ControllerStatus mcStatus,  // [Output] Status of controller
  MemoryRequest RequestIn,        // [Input] Request made of controller
  ControllerCommand mcCommand,    // [Input] Request enable
  bool mcAddrVirtual,             // [Input] Virtual flag for RAM
  bool mcExecMode,                // [Input] Execution mode for RAM
  uint32 phRamIn,                 // [Input]  RAM at requested address
  out uint32 phRamAddress,        // [Output] RAM address requested
  out uint32 phRamOut,            // [Output] RAM to write
  out bool phRequest,             // [Output] RAM request line
  out bool phWriteEnable,         // [Output] RAM write enable
  uint32 ptAddress,               // [Input] Page table address
  out uint32 debug                // [Output] Debug port
  )
{
  // Details of the last request
  MemoryRequest savedRequest;

  // Stuff saved when TLB misses
  uint32 savedPTReadAddr;
  uint32 savedFirstWord;

  // Construct a TLB entry from two memory words that have been read
  PTEntry TLBEntryFromWords(uint32 upperWord, uint32 lowerWord)
  {
    return PTEntry(
      upperWord[31:31],
      upperWord[30:30],
      upperWord[29:8],
      { upperWord[7:0], lowerWord[31:20] },
      lowerWord[19:0]
      );
  }

  // Get the page number for an address - since we have 4k
  // pages this just lops off the appropriate number of bits
  uint<20> GetPageNumber(uint32 rawAddress)
  {
    return rawAddress[31:12];
  }

  // This function converts a virtual address to the table
  // entry index. Currently using XOR to glom the address
  // together. 
  uint<6> GetPageHash(uint32 virtAddr)
  {
    return 
      { 0b1010, virtAddr[31:30]} ^ 
      virtAddr[29:24] ^ 
      virtAddr[23:18] ^ 
      virtAddr[17:12] ^ 
      virtAddr[11:6] ^ 
      virtAddr[5:0];
  }

  // The TLBs - we have one for kernel mode and one for user mode
  PTEntry tlbEntries[64];

  // Query for a TLB entry from an address
  PTEntry GetTLBEntryFromAddress(uint32 address)
  {
    return tlbEntries[GetPageHash(address)];
  }
  
  void SetTLBEntry(
    uint<6> pageNumber,
    PTEntry newEntry)
  {
      tlbEntries[pageNumber] = newEntry;
  }

  // Query for the validity of the TLB at an address. The valid bit needs
  // to be set, and the virtual page number has to match.
  bool IsTLBValidForAddress(uint32 virtualAddress)
  {
    if (GetTLBEntryFromAddress(virtualAddress).VirtualPage == GetPageNumber(virtualAddress) && 
        GetTLBEntryFromAddress(virtualAddress).IsValid)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // The page tables are stored in ram, and their addresses are stored
  // in registers. So given an address, we can determine the physical
  // address of the page table entry.
  //
  // Since we only have a single level of page table, virtual addresses
  // have to be 20 bits or they will not map properly here. Currently
  // we have nothing to alert about this, but this is needed. TODO.
  uint32 CalcPTEntryAddress(uint32 rawAddress)
  {
    //$display("Calculating table entry address with tables at %h, %h", kptAddress, uptAddress);
    
    return ptAddress + GetPageNumber(rawAddress) * 8;
  }

  void RequestPhysicalAddress(MemoryRequest request)
  {
    // Send the parameters to the physical ram   
    phRamAddress = request.Address;
    phRequest = true;
    phWriteEnable = request.WriteEnable;
    phRamOut = request.WriteData;

    // Save the request details
    savedRequest = request;

    mcStatus = ControllerStatus.Waiting;
    transition PRamWait1;    
  }

  // Given an address and a TLB entry that is known to map to it, attempt
  // to create the appropriate physical RAM request.
  void TranslateVirtualRequest(
    PTEntry reqTLBEntry,
    MemoryRequest request)
  {
    if (reqTLBEntry.IsProtected && mcExecMode)
    {
      //$display("Attempting access to protected page from user mode, execMode = %h", mcExecMode);

      mcStatus = ControllerStatus.Error;
      transition Error;
    }
    else
    {
      //$display("Building request from physical page %h and in-page address %h", GetTLBPhysPage(reqTLBEntry), reqVirtAddress[11:0]);

      // Translate page using TLB for upper bits and virtual address for lower bits
      RequestPhysicalAddress(
        MemoryRequest(
          { reqTLBEntry.PhysicalPage, request.Address[11:0] },
          request.WriteData,
          request.WriteEnable));
    }
  }

  state initial
  {
    mcStatus = ControllerStatus.Waiting;

    transition Ready;
  }

  state Ready
  {
    //__display("Memory controller ready, command is %h", mcCommand);
    
    // Only initiate requests when ready and request line is high
    if (mcCommand == ControllerCommand.Request)
    {
      //__display("Controller ready, request made");

      if (!mcAddrVirtual)
      {
        //__display(
        //  "Physical access, RequestIn.WriteEnable is %h, addr is %h, ramIn is %h", 
        //  RequestIn.WriteEnable, 
        //  RequestIn.Address, 
        //  RequestIn.WriteData);

        // This is a request for a physical address, so pass the request directly
        RequestPhysicalAddress(RequestIn);
      }
      else
      {
        //__display("Virtual address request");

        // This is a request for a virtual address - see if the TLB entry for this address
        // is a valid one and if so, request the page pointed to by the TLB. If the TLB
        // misses, populate it first and then try again.
        if (IsTLBValidForAddress(RequestIn.Address))
        {
          //__display(
            //"Page to translate %h found in TLB entry %h, index %h", 
            //mcRamAddress, 
            //GetTLBEntryFromAddress(mcRamAddress),
            //GetPageHash(mcRamAddress));

          TranslateVirtualRequest(
            GetTLBEntryFromAddress(RequestIn.Address),
            RequestIn);
        }
        else
        {
          //__display(
            //"Page for virtual address %h not found in TLB | page = %h | PT Entry address = %h", 
            //mcRamAddress, 
            //GetPageNumber(mcRamAddress), 
            //CalcPTEntryAddress(mcRamAddress));

          // TLB miss - need to lookup in page table. The page table
          // currently is a single level, and only supports up to 256
          // pages to keep it easy (8 bit index).
          phRamAddress = CalcPTEntryAddress(RequestIn.Address);
          phRequest = true;
          phWriteEnable = false;

          // Save the address of the first word of the PT entry
          savedPTReadAddr = CalcPTEntryAddress(RequestIn.Address);

          // Save our request parameters
          savedRequest = RequestIn;

          // Wait for the first word to read out
          mcStatus = ControllerStatus.Waiting;
          transition VPTWait1;
        }
      }
    }
    else
    {
      mcStatus = ControllerStatus.Waiting;
    }
  }

  state PRamWait1
  {
    // Need to wait for another clock for this to complete
    //__display("%d | Physical Ram Wait 1 for %h", __time, phRamAddress);

    phRequest = false;
    mcStatus = ControllerStatus.Waiting;
    transition PRamWait2;
  }

  state PRamWait2
  {
    if (!savedRequest.WriteEnable)
    {
      //__display("Finish physical read value of %h in mc", phRamIn);

      // Deliver to the caller now
      mcRamOut = phRamIn;
    }
    else
    {
      //__display("Finish PRWait2 with isRead not set");
    }

    mcStatus = ControllerStatus.Ready;
    transition Ready;
  }

  state VPTWait1
  {
    //__display("Waiting for read of page table");

    // Wait for read to complete
    phRequest = false;
    mcStatus = ControllerStatus.Waiting;
    transition VPTWait2;
  }

  state VPTWait2
  {
    //$display("Waited for read %h from %h of page table 1", phRamIn, savedPTReadAddr);
    
    // Store first half of entry
    savedFirstWord = phRamIn;

    // Now get second half
    phRequest = true;
    phRamAddress = savedPTReadAddr + 4;
    mcStatus = ControllerStatus.Waiting;
    transition VPTWait3;
  }

  state VPTWait3
  {
    //$display("Waiting again for read of page table");

    // Wait for read to complete
    phRequest = false;
    mcStatus = ControllerStatus.Waiting;
    transition VPTWait4;
  }

  state VPTWait4
  {
    //$display("Waited for read %h of page table 2, va Addr = %h", phRamIn, savedVirtAddr);
    //$display("Inserting TLB entry %h", {1'b1, savedFirstWord[30:0], phRamIn});

    // Now we have second half of entry, store it in the TLB
    SetTLBEntry(
      GetPageHash(savedRequest.Address), 
      TLBEntryFromWords(savedFirstWord, phRamIn));

    TranslateVirtualRequest(
      TLBEntryFromWords(savedFirstWord, phRamIn),
      savedRequest);
  }

  state Error
  {
    // Wait a clock for the error to register
    mcStatus = ControllerStatus.Waiting;

    transition Ready;
  }
}