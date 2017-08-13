module MemoryController(
  out uint32 mcRamOut,         // [Output] RAM at requested address
  out uint<2> mcStatus,        // [Output] Status of controller (0 means not ready, 1 means ready, 2 means error)
  uint32 mcRamAddress,         // [Input] RAM address requested
  uint32 mcRamIn,              // [Input] RAM to write
  bool mcReadReq,              // [Input] RAM read request
  bool mcWriteReq,             // [Input] RAM write request
  bool mcAddrVirtual,          // [Input] Virtual flag for RAM
  bool mcExecMode,             // [Input] Execution mode for RAM
  uint32 phRamIn,              // [Input]  RAM at requested address
  out uint32 phRamAddress,     // [Output] RAM address requested
  out uint32 phRamOut,         // [Output] RAM to write
  out bool phReadReq,          // [Output] RAM read request
  out bool phWriteReq,         // [Output] RAM write request
  uint32 kptAddress,           // [Input] Page table address
  uint32 uptAddress,           // [Input] Page table address
  out uint32 debug             // [Output] Debug port
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

  fn GetPageNumber(
    uint32 rawAddress,
    out uint<20> pageNumber
    )
  {
    pageNumber = rawAddress[31:12];
  }

  fn CalcPTEntryAddress(
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
  uint64 ktlb[16];
  uint64 utlb[16];

  fn GetTLBEntry(
    uint<4> pageNumber,
    out uint64 tlbEntry)
  {
    if (!mcExecMode)
    {
      tlbEntry = ktlb[pageNumber];
    }
    else
    {
      tlbEntry = utlb[pageNumber];
    }
  }
    
  fn SetTLBEntry(
    uint<4> pageNumber,
    uint64 newEntry)
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

  fn GetTLBVirtPage(
    uint64 tlbEntry,
    out uint<20> tlbVirtPage)
  {
    tlbVirtPage = tlbEntry[51:32];
  }

  fn GetTLBPhysPage(
    uint64 tlbEntry,
    out uint<20> tlbPhysPage)
  {
    GetTLBPhysPage = tlbEntry[19:0];
  }

  fn GetTLBValid(
    uint64 tlbEntry,
    out bool tlbValid)
  {
    tlbValid = tlbEntry[63:63];
  }

  fn GetTLBProtected(
    uint64 tlbEntry,
    out bool tlbProtected)
  {
    tlbProtected = tlbEntry[62:62];
  }

  fn GetPageHash(
    uint32 virtAddr,
    out uint<4> pageHash)
  {
    pageHash = virtAddr[13:10];
  }

  fn RequestPhysicalPage(
    uint64 reqTLBEntry,
    uint32 reqVirtAddress,
    bool reqReadReq,
    bool reqWriteReq,
    uint32 reqWriteData)
  {
    if (!GetTLBValid(reqTLBEntry))
    {
      //$display("Address maps to invalid TLB entry %h", reqTLBEntry);

      mcStatus = `MCError;
      transition Error;
    }
    else
    {
      if (GetTLBProtected(reqTLBEntry) == 1 && mcExecMode)
      {
        //$display("Attempting access to protected page from user mode, execMode = %h", mcExecMode);

        mcStatus = `MCError;
        transition Error;
      }
      else
      {
        //$display("Building request from physical page %h and in-page address %h", GetTLBPhysPage(reqTLBEntry), reqVirtAddress[11:0]);

        // Translate page using TLB for upper bits
        phRamAddress[31:12] <= GetTLBPhysPage(reqTLBEntry);

        // Use lower bits from virtual address in physical address
        phRamAddress[11:0] <= reqVirtAddress[11:0];

        // Otherwise same as physical lookup
        phReadReq <= reqReadReq;
        phWriteReq <= reqWriteReq;
        phRamOut <= reqWriteData;
        isRead <= (reqReadReq == 1);
        state <= `PRamWait1;
        mcStatus <= `MCWaiting;
      }
    } 
  }

  always @(posedge clk or posedge reset)
  {
    if (reset == 1)
    {
      mcStatus <= `MCWaiting;
      state <= `Ready;
      isRead <= 0;
    }
    else
    {
      case (state)
        `Ready: {
          if (mcReadReq == 1 || mcWriteReq == 1)
          {
            if (mcAddrVirtual == 0)
            {
              //$display("Physical access, mcReadReq is %h, addr is %h, ramIn is %h", mcReadReq, mcRamAddress, mcRamIn);

              // Divert to the physical RAM
              phRamAddress <= mcRamAddress;
              phReadReq <= mcReadReq;
              phWriteReq <= mcWriteReq;
              phRamOut <= mcRamIn;
              isRead <= (mcReadReq == 1);
              state <= `PRamWait1;
              mcStatus <= `MCWaiting;
            }
            else
            {
              // Need to translate - use the lower bits of the virtual page
              if (GetTLBVirtPage(GetTLBEntry(GetPageHash(mcRamAddress))) == GetPageNumber(mcRamAddress))
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
                phRamAddress <= CalcPTEntryAddress(mcRamAddress);
                phReadReq <= 1;

                // Save the address we are looking up or storing at
                savedVirtAddr <= mcRamAddress;

                // Save the address of the first word of the PT entry
                savedPTReadAddr <= CalcPTEntryAddress(mcRamAddress);

                // Save our request parameters
                savedReadReq <= mcReadReq;
                savedWriteReq <= mcWriteReq;
                savedWriteData <= mcRamIn;

                // Wait for the first word to read out
                state <= `VPTWait1;
                mcStatus <= `MCWaiting;
              }

            }
          }
          else
          {
            mcStatus <= `MCWaiting;
          }
        }

        `PRamWait1: {
          // Need to wait for another clock for this to complete
          //$display("PR wait 1 for %h", phRamAddress);

          mcStatus <= `MCWaiting;
          state <= `PRamWait2;
        }

        `PRamWait2: {
          if (isRead == 1)
          {
            //$display("Finish physical read value of %h in mc", phRamIn);

            // Deliver to the caller now
            mcRamOut <= phRamIn;
          }
          else
          {
            //$display("Finish PRWait2 with isRead not set");
          }

          mcStatus <= `MCReady;
          state <= `Ready;
        }

        `VPTWait1: {
          //$display("Waiting for read of page table");

          // Wait for read to complete
          mcStatus <= `MCWaiting;
          state <= `VPTWait2;
        }

        `VPTWait2: {
          //$display("Waited for read %h from %h of page table 1", phRamIn, savedPTReadAddr);
          
          // Store first half of entry
          savedFirstWord <= phRamIn;

          // Now get second half
          phRamAddress <= savedPTReadAddr + 4;
          mcStatus <= `MCWaiting;
          state <= `VPTWait3;
        }

        `VPTWait3: {
          //$display("Waiting again for read of page table");

          // Wait for read to complete
          mcStatus <= `MCWaiting;
          state <= `VPTWait4;
        }

        `VPTWait4: {
          //$display("Waited for read %h of page table 2, va Addr = %h", phRamIn, savedVirtAddr);
          //$display("Inserting TLB entry %h", {1'b1, savedFirstWord[30:0], phRamIn});

          // Now we have second half of entry, store it in the TLB
          SetTLBEntry(GetPageHash(savedVirtAddr), {1'b1, savedFirstWord[30:0], phRamIn});

          RequestPhysicalPage(
            {1'b1, savedFirstWord[30:0], phRamIn}, 
            mcRamAddress, 
            savedReadReq, 
            savedWriteReq, 
            savedWriteData);
        }

        `Error: {
          // Wait a clock for the error to register
          mcStatus <= `MCWaiting;
          state <= `Ready;
        }

      endcase
    }
  }
endmodule