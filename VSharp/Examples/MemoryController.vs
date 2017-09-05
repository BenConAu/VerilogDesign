enum ControllerStatus
{
  Error,
  MCWaiting,
  MCReady,
}

struct TLBEntry
{
  bool IsValid;
  bool IsProtected;
  uint<20> VirtualPage;
  uint<20> PhysicalPage;
}

module MemoryController(
  out uint32 mcRamOut,            // [Output] RAM at requested address
  out ControllerStatus mcStatus,  // [Output] Status of controller (0 means not ready, 1 means ready, 2 means error)
  uint32 mcRamAddress,            // [Input] RAM address requested
  uint32 mcRamIn,                 // [Input] RAM to write
  bool mcReadReq,                 // [Input] RAM read request
  bool mcWriteReq,                // [Input] RAM write request
  bool mcAddrVirtual,             // [Input] Virtual flag for RAM
  bool mcExecMode,                // [Input] Execution mode for RAM
  uint32 phRamIn,                 // [Input]  RAM at requested address
  out uint32 phRamAddress,        // [Output] RAM address requested
  out uint32 phRamOut,            // [Output] RAM to write
  out bool phReadReq,             // [Output] RAM read request
  out bool phWriteReq,            // [Output] RAM write request
  uint32 kptAddress,              // [Input] Page table address
  uint32 uptAddress,              // [Input] Page table address
  out uint32 debug                // [Output] Debug port
  )
{
  bool isRead;

  // Stuff saved when TLB misses
  bool savedReadReq;
  bool savedWriteReq;
  uint32 savedVirtAddr;
  uint32 savedPTReadAddr;
  uint32 savedFirstWord;
  uint32 savedWriteData;

  uint<20> GetPageNumber(uint32 rawAddress)
  {
    return rawAddress[31:12];
  }

  void CalcPTEntryAddress(
    uint32 rawAddress,
    out uint32 entryAddress
    )
  {
    //$display("Calculating table entry address with tables at %h, %h", kptAddress, uptAddress);
    
    if (!mcExecMode)
    {
      entryAddress = kptAddress + rawAddress[17:12] * 8;
    }
    else
    {
      entryAddress = uptAddress + rawAddress[17:12] * 8;
    }
  }

  // The TLB
  TLBEntry ktlb[16];
  TLBEntry utlb[16];

  TLBEntry GetTLBEntry(uint<4> pageNumber)
  {
    if (!mcExecMode)
    {
      return ktlb[pageNumber];
    }
    else
    {
      return utlb[pageNumber];
    }
  }
    
  void SetTLBEntry(
    uint<4> pageNumber,
    TLBEntry newEntry)
  {
    if (!mcExecMode)
    {
      ktlb[pageNumber] = newEntry;
    }
    else
    {
      utlb[pageNumber] = newEntry;
    }
  }

  uint<4> GetPageHash(
    uint32 virtAddr)
  {
    return virtAddr[13:10];
  }

  void RequestPhysicalPage(
    TLBEntry reqTLBEntry,
    uint32 reqVirtAddress,
    bool reqReadReq,
    bool reqWriteReq,
    uint32 reqWriteData)
  {
    if (!reqTLBEntry.IsValid)
    {
      //$display("Address maps to invalid TLB entry %h", reqTLBEntry);

      mcStatus = ControllerStatus.Error;
      transition Error;
    }
    else
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

        // Translate page using TLB for upper bits
        phRamAddress[31:12] = reqTLBEntry.PhysicalPage;

        // Use lower bits from virtual address in physical address
        phRamAddress[11:0] = reqVirtAddress[11:0];

        // Otherwise same as physical lookup
        phReadReq = reqReadReq;
        phWriteReq = reqWriteReq;
        phRamOut = reqWriteData;
        isRead = reqReadReq;
        mcStatus = ControllerStatus.MCWaiting;
        transition PRamWait1;
      }
    } 
  }

  state initial
  {
    mcStatus = ControllerStatus.MCWaiting;
    isRead = false;
  }

  state Ready
  {
    if (mcReadReq || mcWriteReq)
    {
      if (!mcAddrVirtual)
      {
        //$display("Physical access, mcReadReq is %h, addr is %h, ramIn is %h", mcReadReq, mcRamAddress, mcRamIn);

        // Divert to the physical RAM
        phRamAddress = mcRamAddress;
        phReadReq = mcReadReq;
        phWriteReq = mcWriteReq;
        phRamOut = mcRamIn;
        isRead = mcReadReq;
        mcStatus = ControllerStatus.MCWaiting;
        transition PRamWait1;
      }
      else
      {
        // Need to translate - use the lower bits of the virtual page
        if (GetTLBEntry(GetPageHash(mcRamAddress)).VirtualPage == GetPageNumber(mcRamAddress))
        {
          //$display(
            //"Page to translate %h found in TLB entry %h, index %h", 
            //mcRamAddress, 
            //GetTLBEntry(GetPageHash(mcRamAddress)), 
            //GetPageHash(mcRamAddress));

          RequestPhysicalPage(
            GetTLBEntry(GetPageHash(mcRamAddress)), 
            mcRamAddress, 
            mcReadReq, 
            mcWriteReq, 
            mcRamIn);
        }
        else
        {
          //$display("Page for address %h not found in TLB, page = %h, pt + page = %h", mcRamAddress, mcRamAddress[17:10], CalcPTEntryAddress(mcRamAddress));

          // TLB miss - need to lookup in page table. The page table
          // currently is a single level, and only supports up to 256
          // pages to keep it easy (8 bit index).
          CalcPTEntryAddress(mcRamAddress, out phRamAddress);
          phReadReq = true;

          // Save the address we are looking up or storing at
          savedVirtAddr = mcRamAddress;

          // Save the address of the first word of the PT entry
          CalcPTEntryAddress(mcRamAddress, out savedPTReadAddr);

          // Save our request parameters
          savedReadReq = mcReadReq;
          savedWriteReq = mcWriteReq;
          savedWriteData = mcRamIn;

          // Wait for the first word to read out
          mcStatus = ControllerStatus.MCWaiting;
          transition VPTWait1;
        }

      }
    }
    else
    {
      mcStatus = ControllerStatus.MCWaiting;
    }
  }

  state PRamWait1
  {
    // Need to wait for another clock for this to complete
    //$display("PR wait 1 for %h", phRamAddress);

    mcStatus = ControllerStatus.MCWaiting;
    transition PRamWait2;
  }

  state PRamWait2
  {
    if (isRead)
    {
      //$display("Finish physical read value of %h in mc", phRamIn);

      // Deliver to the caller now
      mcRamOut = phRamIn;
    }
    else
    {
      //$display("Finish PRWait2 with isRead not set");
    }

    mcStatus = ControllerStatus.MCReady;
    transition Ready;
  }

  state VPTWait1
  {
    //$display("Waiting for read of page table");

    // Wait for read to complete
    mcStatus = ControllerStatus.MCWaiting;
    transition VPTWait2;
  }

  state VPTWait2
  {
    //$display("Waited for read %h from %h of page table 1", phRamIn, savedPTReadAddr);
    
    // Store first half of entry
    savedFirstWord = phRamIn;

    // Now get second half
    phRamAddress = savedPTReadAddr + 4;
    mcStatus = ControllerStatus.MCWaiting;
    transition VPTWait3;
  }

  state VPTWait3
  {
    //$display("Waiting again for read of page table");

    // Wait for read to complete
    mcStatus = ControllerStatus.MCWaiting;
    transition VPTWait4;
  }

  state VPTWait4
  {
    //$display("Waited for read %h of page table 2, va Addr = %h", phRamIn, savedVirtAddr);
    //$display("Inserting TLB entry %h", {1'b1, savedFirstWord[30:0], phRamIn});

    // Now we have second half of entry, store it in the TLB
    SetTLBEntry(GetPageHash(savedVirtAddr), {0b1, savedFirstWord[30:0], phRamIn});

    RequestPhysicalPage(
      {0b1, savedFirstWord[30:0], phRamIn}, 
      mcRamAddress, 
      savedReadReq, 
      savedWriteReq, 
      savedWriteData);
  }

  state Error
  {
    // Wait a clock for the error to register
    mcStatus = ControllerStatus.MCWaiting;

    transition Ready;
  }
}