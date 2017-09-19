enum ErrorCode
{
  BadInstr1,
  BadInstr2,
  BadMem,
}

module ALU(
  clock clk,                  // [Input]  Clock driving the ALU
  bool reset,                 // [Input]  Reset pin
  uint32 ramIn,               // [Input]  RAM at requested address
  ControllerStatus mcStatus,  // [Input]  RAM ready signal
  out uint32 ramAddress,      // [Output] RAM address requested
  out uint32 ramOut,          // [Output] RAM to write
  out bool readReq,           // [Output] RAM read request
  out bool writeReq,          // [Output] RAM write request
  out bool addrVirtual,       // [Output] Virtual flag for RAM
  out bool execMode,          // [Output] Whether we are in user or kernel
  out uint32 ptAddress,       // [Output] Page Table Address
  out uint32 uartReadReq,     // [Output] uart read requested
  bool uartReadAck,           // [Input]  Flag to indicate read success
  uint8 uartReadData,         // [Input]  Actual data read 
  out bool uartWriteReq,      // [Output] uart write requested
  out uint8 uartWriteData,    // [Output] uart data to write
  bool uartWriteReady,        // [Input]  uart ready to send
  out uint32 ipointer,        // [Debug]  Instruction pointer value
  out uint8 opCode,           // [Debug]  current opCode value
  out uint32 r0,              // [Debug]  current r0 value
  out uint32 r1,              // [Debug]  current r1 value
  out uint32 r2,              // [Debug]  current r2 value
  out uint32 r3,              // [Debug]  current r3 value
  out uint32 r4,              // [Debug]  current r4 value
  out uint32 r5,              // [Debug]  current r5 value
  out uint8 rPos,             // [Debug]  current rPos (register window) value
  out uint32 debug,           // [Output] Debug port
  out uint32 debug2,          // [Output] Another debug port
  out uint<9> debug3          // [Output] And yet another debug port
  )
{

//  `include "../PhaethonISA/Generated/PhaethonOpCode.v"
//  `include "Common.sv"

  // Local registers that need initialization
  uint32 counter = 0;
  bool initComplete = false;
  
  const uint32 StackPointerReg = 0;
  const uint32 FlagsReg        = 1;
  const uint32 SysCallReg      = 2;
  const uint32 CodeReturnReg   = 3;
  const uint32 KPageTableReg   = 4;
  const uint32 UPageTableReg   = 5;
  const uint32 FixedRegCount   = 6;

  // Other local registers that are initialized elsewhere
  uint32  regarray[64 + FixedRegCount];
  uint32  ramValue;
  uint32  regValue[4];
  uint32  regValue2[4];
  uint32  regValue3[4];
  uint32  opDataWord;
  uint8   regAddress;
  uint8   regAddress2;
  uint8   regAddress3;
  uint<7> fOpEnable;
  bool    condJump;
  uint32  sentinel;
  uint8   errorHaltCode;
  uint32  errorHaltData;

  // Wire up the results from the floating units
  wire uint32 fAddResult[4];
  wire uint32 fSubResult;
  wire uint32 fConvResult;
  wire uint32 fMulResult;
  wire uint32 fMulAddResult;
  wire uint32 fDivResult;
  wire uint32 floatDebug;
  wire uint<2> fCompareResult;

  //FloatingAdd         fAdd0(regValue2[0], regValue3[0], false, fAddResult[0], floatDebug, clk, fOpEnable[0:0]);
  //FloatingAdd         fAdd1(regValue2[1], regValue3[1], false, fAddResult[1], floatDebug, clk, fOpEnable[0:0]);
  //FloatingAdd         fAdd2(regValue2[2], regValue3[2], false, fAddResult[2], floatDebug, clk, fOpEnable[0:0]);
  //FloatingAdd         fAdd3(regValue2[3], regValue3[3], false, fAddResult[3], floatDebug, clk, fOpEnable[0:0]);
  //FloatingAdd         fSub(regValue[0], regValue2[0], true, fSubResult, floatDebug, clk, fOpEnable[1:1]);
  //FloatingFromInt     fConv(regValue[0], fConvResult, floatDebug, clk, fOpEnable[2:2]);
  //FloatingMultiply    fMul(regValue2[0], regValue3[0], fMulResult, floatDebug, clk, fOpEnable[3:3]);
  //FloatingMultiplyAdd fMulAdd(regValue[0], regValue2[0], regValue3[0], fMulAddResult, floatDebug, clk, fOpEnable[4:4]);
  //FloatingCompare     fComp(regValue[0], regValue2[0], fCompareResult, floatDebug, clk, fOpEnable[5:5]);
  //FloatingDivide      fDiv(regValue[0], regValue2[0], fDivResult, floatDebug, clk, fOpEnable[6:6]);

  wire uint32 dbgBufDbg1;
  wire uint32 dbgBufDbg2;
  bool dbgBufferWriteReq;
  uint32 dbgBufferWriteData;
  wire uint32 dbgBufferReadData;
  wire bool dbgBufferReadComplete;
  bool dbgBufferReadReq;
  wire uint32 dbgBufferLength;

  //RingBuffer #(32, 5) debugBuffer(
  //  clk,                    // Global clock
  //  reset,                  // Reset
  //  dbgBufferWriteReq,      // Flag to indicate request to write
  //  dbgBufferWriteData,     // Data to write
  //  dbgBufferReadReq,       // Flag to indicate request to read
  //  dbgBufferReadComplete,  // Flag to indicate read success
  //  dbgBufferReadData,      // Actual data read
  //  dbgBufferLength,        // Buffer length
  //  dbgBufDbg1,             // Debug1
  //  dbgBufDbg2              // Debug2
  //);

  //initial
     //$monitor("%t, ram = %h, %h, %h, %h : %h, %h, %h, %h",
       //$time, ramIn[7:0], ramIn[15:8], ramIn[23:16], ramIn[31:24], ramAddress, ramIn, opAddress, ramValue);

  // Mode InitialMode: Schedule read of code at instruction pointer and clear
  //         out enable bits for auxillary modules.
  state initial
  {
    if (!initComplete)
    {
      // We initialize most stuff here because it can be done once
      // here and work both with the reset input and with an initializer
      // for the registers.
      debug = 0;
      debug2 = 0;
      debug3 = 1;
      
      writeReq = 0;
      uartReadReq = 0;
      readReq = 0;
      opDataWord = 0xffffffff;
      opCode = 0;
      fOpEnable = 0b0000000;
      ipointer = 0;
      condJump = false;
      dbgBufferWriteReq = false;
      dbgBufferReadReq = false;
      execMode = false;
      addrVirtual = false;

      // First real register position
      rPos = `FixedRegCount;

      // Some stuff is hard to do with initializers, so we do it here
      regarray[StackPointerReg] = 0;
      regarray[FlagsReg] = 0;
      regarray[SysCallReg] = 0;
      regarray[CodeReturnReg] = 0;
      regarray[KPageTableReg] = 0;
      regarray[UPageTableReg] = 0;

      // Mark initialization as complete
      initComplete = true;

      // Mode won't change, so next clock we will be back but skip init
    }
    else
    {
      // { RAM read for instruction data
      readReq = 1;
      ramAddress = ipointer;
      opDataWord = 'h0badf00d;

      // Clear out stuff for the pipeline
      fOpEnable = 0b0000000;
      condJump = false;
      
      transiton InstrReadComplete;
    }
  }

  state always
  {
    // Stuff we always do
    r0 = regarray[rPos];
    r1 = regarray[rPos + 1];
    r2 = regarray[rPos + 2];
    r3 = regarray[rPos + 3];
    r4 = regarray[rPos + 4];
    r5 = regarray[`StackPointerReg];

    // Keep the output register in sync with what we have been setting
    kptAddress = regarray[`KPageTableReg];
    uptAddress = regarray[`UPageTableReg];

    //debug3[8:0] = mode;
    //debug2[7:0] = mode;
    //debug2[15:8] = opCode;
    debug2[11:0] = ipointer;
    debug2[31:12] = opCode;
  }

  // Mode InstrReadComplete: Handle completion of instruction pointer read request and
  //         decode the instruction data, including the opCode
  //         of the instruction and the affected registers.
  state InstrReadComplete
  {
    // Stop request
    readReq = 0;

    if (mcStatus == `MCReady)
    {
      // If ramReady is high then we have received something
      //$display("Receiving instr1 value %h from MemoryController", ramIn);

      opCode = ramIn[7:0];
      regAddress =  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
      regAddress2 = (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
      regAddress3 = (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);

      // Move to next mode now
      mode = `RegValueSet;
    }
    else 
    {
      if (mcStatus == `MCError)
      {
        __display("Memory controller error when reading instruction, halting");

        // Set error condition
        mode = `ErrorHalt;
        errorHaltCode = `ErrorCodeBadInstr1;
        errorHaltData = ramAddress;
      }
    }
  }

  // Mode RegValueSet: Schedule read of additional code for opCodes that
  //         store word data. Read in register values for
  //         registers referenced by the instruction.
  state RegValueSet
  {
    // Read values from registers
    regValue[0] = regarray[regAddress[7:0]];
    if (opCode == `VfaddRRR)
    {
      regValue[1] = regarray[regAddress[7:0] + 1];
      regValue[2] = regarray[regAddress[7:0] + 2];
      regValue[3] = regarray[regAddress[7:0] + 3];
    }

    regValue2[0] = regarray[regAddress2[7:0]];
    if (opCode == `VfaddRRR)
    {
      regValue2[1] = regarray[regAddress2[7:0] + 1];
      regValue2[2] = regarray[regAddress2[7:0] + 2];
      regValue2[3] = regarray[regAddress2[7:0] + 3];
    }

    regValue3[0] = regarray[regAddress3[7:0]];
    if (opCode == `VfaddRRR)
    {
      regValue3[1] = regarray[regAddress3[7:0] + 1];
      regValue3[2] = regarray[regAddress3[7:0] + 2];
      regValue3[3] = regarray[regAddress3[7:0] + 3];
    }

    // Enable operation for module
    if (opCode == `FaddRRR || opCode == `VfaddRRR) { fOpEnable[0:0] = 1; }
    if (opCode == `FsubRR) { fOpEnable[1:1] = 1; }
    if (opCode == `FconvR) { fOpEnable[2:2] = 1; }
    if (opCode == `FmulRRR) { fOpEnable[3:3] = 1; }
    if (opCode == `FmuladdRRR) { fOpEnable[4:4] = 1; }
    if (opCode == `FminRR) { fOpEnable[5:5] = 1; }
    if (opCode == `FmaxRR) { fOpEnable[5:5] = 1; }
    if (opCode == `FdivRR) { fOpEnable[6:6] = 1; }

    // Determine if a conditional jump needs to happen
    if (opCode == `JneC && regarray[`FlagsReg][0:0] == false) { condJump = true; }
    if (opCode == `JeC && regarray[`FlagsReg][0:0] == true) { condJump = true; }
    if (opCode == `JzRC && regarray[regAddress[7:0]] == 0) { condJump = true; }
    if (opCode == `JnzRC && regarray[regAddress[7:0]] != 0) { condJump = true; }

    if (Is8ByteOpcode(opCode) == 1)
    {
      // Read values from ram requested by instruction
      readReq = 1;
      ramAddress = ipointer + 4;

      // We need to move into further modes
      mode = `DataWordComplete;
    }
    else 
    {
      if (IsRAMOpcode(opCode) == 1|| IsIOOpcode(opCode) == 1)
      {
        // We are not reading a constant, but we might still be
        // doing a RAM operation, move into the mode where we do that
        mode = `RWRequest;
      }
      else
      {
        // Since there is no word data, there is no need
        // to wait for that word data to come back, and there
        // can be no further reads or writes since the word
        // data is where the address would go
        mode = `ProcessOpCode;
      }
    }
  }

  // Mode DataWordComplete: Complete read of additional code for opCodes that
  //         store word data. We only } up in this mode if
  //         the appropriate opCode is set, so no need to check
  //         the opCode.
  state DataWordComplete
  {
    // Stop request
    readReq = 0;

    if (mcStatus == `MCReady)
    {
      //$display("DataWordComplete with word %h", ramIn);

      // Store ram values requested
      opDataWord = ramIn;

      // Move to next mode - only progress to data read / write
      // for opCodes that actually need it.
      if (IsRAMOpcode(opCode) == 1 || IsIOOpcode(opCode) == 1)
      {
        //$display("DataWordComplete getting another RW %h", opCode);
        mode = `RWRequest;
      }
      else
      {
        //$display("DataWordComplete processing an OpCode %h", opCode);
        mode = `ProcessOpCode;
      }
    }
    else 
    {
      if (mcStatus == `MCError)
      {
        // Set error condition
        mode = `ErrorHalt;
        errorHaltCode = `ErrorCodeBadInstr2;
        errorHaltData = ramAddress;
      }
    }        
  }

  state RWRequest
  {
    if (IsRAMOpcode(opCode) == 1)
    {
      //$display("RWRequest for RAM opcode");

      switch (opCode)
      {
        case MovRdC: 
        {
          // Read values from address encoded in code
          readReq = 1;
          ramAddress = opDataWord;

          //$display("Requesting RdC read from %h", opDataWord);
        }

        case MovRdRo: 
        {
          // First register is destination, second register is base address, 
          // constant stores offset in bytes.
          readReq = 1;
          ramAddress = opDataWord + regValue2[0];

          //$display("Requesting read from %h", opDataWord + regValue2);
        }

        case MovRdRoR: 
        {
          // First register is destination, second register is base address, 
          // constant stores size of item, and third register stores index of item.
          readReq = 1;
          ramAddress = regValue2[0] + opDataWord * regValue3[0];

          //$display("Requesting read from %h", regValue2[0] + opDataWord * regValue3[0]);
        }

        case MovRdR: 
        {
          // Read values from address encoded in code
          readReq = 1;
          ramAddress = regValue2[0];

          //$display("Requesting read from %h", opDataWord + regValue2);
        }

        case PopR: 
        {
          // Read value from stack
          readReq = 1;
          ramAddress = regarray[`StackPointerReg] - 4;

          //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
        }

        case Ret: 
        {
          // Read value from stack
          readReq = 1;
          ramAddress = regarray[`StackPointerReg] - 4;
        
          //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
        }
      
        case MovdCR: 
        {
          // Write values to ram requested by instruction
          writeReq = 1;
          ramAddress = opDataWord;
          ramOut = regValue2[0];
        
          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord);
        }

        case MovdRoR: 
        {
          // Write values to ram requested by instruction
          writeReq = 1;
          ramAddress = opDataWord + regValue[0];
          ramOut = regValue2[0];
        
          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord + regValue[0]);
        }
      
        case MovdRoRR: 
        {
          // first register is base address, constant stores size of items, 
          // second register stores index of item, third register is destination, 
          writeReq = 1;
          ramAddress = regValue[0] + opDataWord * regValue2[0];
          ramOut = regValue3[0];
        
          //$display("Reqesting write %h to address value %h", regValue2[0], regValue[0] + opDataWord * regValue2[0]);
        }

        case PushR: 
        {
          // Write register value to stack
          writeReq = 1;
          ramAddress = regarray[`StackPointerReg];
          ramOut = regValue[0];
        
          //$display("Reqesting push %h", regValue);
        }
      
        case CallR: 
        {
          // Write ip to stack
          writeReq = 1;
          ramAddress = regarray[`StackPointerReg];
          ramOut = ipointer;
        
          //$display("Reqesting push %h", regValue);
        }

        case SysCallRRR: 
        {
          // Read function address from register
          readReq = 1;
          ramAddress = regValue[0];
        }
      }

      transition MemRWComplete;
    }
    else 
    {
      if (IsIOOpcode(opCode) == 1)
      {
        //$display("IO opcode");

        // Stop request
        readReq = 0;

        switch (opCode)
        {
          case ReadPortRR: 
          {
            switch (regValue2[0])
            {
              case 1: 
              {
                // Port 1 is read from UART
                uartReadReq = 1;
              }
          
              //case 2: 
              //{
                // Port 2 is UART write ready status
              //}
          
              default: 
              {
                $display("Unknown port %h being read", regValue[0]);
              }
            }
          }

          case WritePortRR: 
          {
            uartWriteReq = 1;
            uartWriteData = regValue2[0][7:0];
          }

          case DoutR: 
          {
            //$display("DoutR write req");

            dbgBufferWriteReq = 1;
            dbgBufferWriteData = regValue[0];
          }

          case DinR: 
          {
            dbgBufferReadReq = 1;
          }
        }

        mode = `IORWWait;
      }
    }
  }

  state IORWWait
  {
    uartReadReq = false;
    uartWriteReq = false;
    dbgBufferWriteReq = false;
    dbgBufferReadReq = false;

    transition IORWComplete;
  }

  // Mode MemRWComplete: Complete data read or write if the instruction
  //         requires it.
  state MemRWComplete
  {
    // Stop request
    readReq = false;
    writeReq = false;

    if (mcStatus == `MCReady)
    {
      if (opCode == `MovRdC || opCode == `MovRdRo || opCode == `MovRdRoR || opCode == `MovRdR || opCode == `PopR || opCode == `Ret)
      {
        //$display("Receiving read address value %h", ramIn);

        // Store ram values requested
        ramValue = ramIn;
      }

      mode = `ProcessOpCode;
    }
    else 
    {
      if (mcStatus == `MCError)
      {
        if (execMode == 0)
        {
          $display("Memory controller says access to protected page from kernel mode, execMode = %h", execMode);

          // Set error condition if supervisor hits this
          mode = `ErrorHalt;
          errorHaltCode = `ErrorCodeBadMem;
          errorHaltData = ramAddress;
        }
        else
        {
          $display("Memory controller says access to protected page from user mode, execMode = %h", execMode);

          // Exit back to supervisor if user hits this
          opCode = `Exit;
          mode = `ProcessOpCode;
        }
      }
    }
  }

  state IORWComplete 
  {
    if (opCode == `ReadPortRR)
    {
      switch (regValue2[0])
      {
        case 1: 
        {
          // Read from UART is now complete, return
          if (uartReadAck == true)
          {
            ramValue[7:0] = uartReadData;
            ramValue[31:8] = 1;
          }
          else
          {
            // Sorry, no value for you
            ramValue = 0;
          }
        }

        case 2: 
        {
          // Port 2 is UART write ready status
          ramValue[0:0] = uartWriteReady;
          ramValue[31:1] = 0;
        }

        default: 
        {
          $display("Unknown port %h being read", regValue[0]);
        }
      }
    }
    else 
    {
      if (opCode == `DinR)
      {
        ramValue = dbgBufferReadData;
      }
    }

    transition ProcessOpCode;
  }

  // Mode ProcessOpCode: Finalize the instruction operation, by performing
  //         the writes that are needed and moving the
  //         instruction pointer along.
  state ProcessOpCode
  {
    // Now we can do writes to non-ram things
    switch (opCode)
    {
      case MovRC:  { regarray[regAddress[7:0]] = opDataWord;   }            // mov reg, const
      case MovRdC: { regarray[regAddress[7:0]] = ramValue;     }            // mov reg, [addr]
      case MovRR:  { regarray[regAddress[7:0]] = regValue2[0]; }            // mov reg, reg

      case PackRRR: 
      {
        switch (regValue3[0][1:0])
        {
          case 0: { regarray[regAddress[7:0]][7:0] = regValue2[0][7:0]; }
          case 1: { regarray[regAddress[7:0]][15:8] = regValue2[0][7:0]; }
          case 2: { regarray[regAddress[7:0]][23:16] = regValue2[0][7:0]; }
          case 3: { regarray[regAddress[7:0]][31:24] = regValue2[0][7:0]; }
          default: { $display("Out of range byte position"); }
        }
      }

      case MovRdRo:  { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg + const]
      case MovRdRoR: { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg + const * reg]
      case MovRdR:   { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg]
      //case MovdCR:   { } // Done above
      //case MovdRoR:  { } // Done above
      //case MovdRoRR: { } // Done above

      case LeaRRoR: 
      {
        //$display("Doing lea with opDataWord %h", opDataWord);
        regarray[regAddress[7:0]] = regValue2[0] + opDataWord * regValue3[0];
      }

      case ReadPortRR: { regarray[regAddress[7:0]] = ramValue; }            // ReadPort reg, reg
      //case WritePortRR: { } // Done above

      case PushR: 
      {
        regarray[`StackPointerReg] = regarray[`StackPointerReg] + 4;                             // push reg
      }

      case PopR: 
      {
        regarray[regAddress[7:0]] = ramValue;                        // pop reg
        regarray[`StackPointerReg] = regarray[`StackPointerReg] - 4;
      }

      case CallR: 
      {
        // Stack pointer increases like a push
        regarray[`StackPointerReg] = regarray[`StackPointerReg] + 4;                             // call reg

        // Jump to the function
        ipointer = regValue[0];
        debug3 = 3;

        //$display("Doing a call");
      }

      case Ret: 
      {
        // Stack pointer decreases like a pop
        regarray[`StackPointerReg] = regarray[`StackPointerReg] - 4;                             // ret

        // Return to the saved position, after the call
        ipointer = ramValue + 4;
        debug3 = 4;

        //$display("Doing a ret");
      }

      case RCallRC: 
      {
        // Store return address
        regarray[rPos + opDataWord] = ipointer;

        // Store arg value
        regarray[rPos + opDataWord + 1] = opDataWord;

        // Shift register window
        rPos = rPos + opDataWord + 2;

        // Jump to the function
        ipointer = regValue[0];
        debug3 = 5;

        //$display("Doing a register shift call to %h", regValue[0]);
      }

      case RRet: 
      {
        // Get the return address
        ipointer = regarray[rPos - 2] + 8;
        debug3 = 6;

        // Get the window value
        rPos = rPos - (regarray[rPos - 1] + 2);

        //$display("Doing an rret");
      }

      case CmpRR: // cmp reg, reg
      {                                                   
        regarray[`FlagsReg][0:0] = (regValue[0] == regValue2[0] ? 1 : 0);
        regarray[`FlagsReg][1:1] = (regValue[0] .< regValue2[0] ? 1 : 0);
        regarray[`FlagsReg][2:2] = (regValue[0] >. regValue2[0] ? 1 : 0);
      }

      case CmpRC: 
      {
        regarray[`FlagsReg][0:0] = (regValue[0] == opDataWord ? 1 : 0);
        regarray[`FlagsReg][1:1] = (regValue[0] .< opDataWord ? 1 : 0);
        regarray[`FlagsReg][2:2] = (regValue[0] >. opDataWord ? 1 : 0);
      }

      case CmpERRR: 
      {                                                 // cmpe reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] == regValue3[0] ? 1 : 0);
      }

      case CmpNeRRR: 
      {                                                 // cmpne reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] != regValue3[0] ? 1 : 0);
      }

      case CmpLtRRR: 
      {                                                 // cmplt reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] .< regValue3[0] ? 1 : 0);
      }

      case CmpGtRRR: 
      {                                                 // cmpgt reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] >. regValue3[0] ? 1 : 0);
      }

      case JmpC: 
      {  
        ipointer = opDataWord;                              // jmp address
        debug3 = 7;
      }

      //`JneC: { } // Done above
      //`JeC: { }   // Done above
      //`JzRC: { } // Done above
      //`JnzRC: { }   // Done above

      case FaddRRR:    { regarray[regAddress[7:0]] = fAddResult[0]; }        // fadd reg, reg, reg
      case FsubRR:     { regarray[regAddress[7:0]] = fSubResult;     }        // fsub reg, reg
      case FconvR:     { regarray[regAddress[7:0]] = fConvResult;    }        // fconv reg
      case FmulRRR:    { regarray[regAddress[7:0]] = fMulResult;     }        // fmul reg, reg, reg
      case FdivRR:     { regarray[regAddress[7:0]] = fDivResult;     }
      case FmuladdRRR: { regarray[regAddress[7:0]] = fMulAddResult;   }       // fmul reg, reg
      case FminRR:     { regarray[regAddress[7:0]] = (fCompareResult == 'b01 ? regValue2[0] : regValue[0]); }
      case FmaxRR:     { regarray[regAddress[7:0]] = (fCompareResult == 'b11 ? regValue2[0] : regValue[0]); }

      case VfaddRRR: 
      {
        regarray[regAddress[7:0]] = fAddResult[0];
        regarray[regAddress[7:0] + 1] = fAddResult[1];
        regarray[regAddress[7:0] + 2] = fAddResult[2];
        regarray[regAddress[7:0] + 3] = fAddResult[3];
      }

      case AddRRC:    { regarray[regAddress[7:0]] = regValue2[0] + opDataWord;    } // add reg, reg, const
      case AddRRR:    { regarray[regAddress[7:0]] = regValue2[0] + regValue3[0];  } // add reg, reg, reg
      case SubRRC:    { regarray[regAddress[7:0]] = regValue2[0] - opDataWord;    } // add reg, reg, const
      case SubRRR:    { regarray[regAddress[7:0]] = regValue2[0] - regValue3[0];  } // add reg, reg, reg
      case IncR:      { regarray[regAddress[7:0]] = regValue[0] + 1;              } // dec reg
      case DecR:      { regarray[regAddress[7:0]] = regValue[0] - 1;              } // dec reg
      case ShlRRR:    { regarray[regAddress[7:0]] = regValue2[0] << regValue3[0]; } // shl reg, reg, reg
      case ShrRRR:    { regarray[regAddress[7:0]] = regValue2[0] >> regValue3[0]; } // shl reg, reg, reg
      case NegRR:     { regarray[regAddress[7:0]] = -regValue2[0];                } // neg reg, reg

      case MulAddRRC: { regarray[regAddress[7:0]] = regValue[0] + regValue2[0] * opDataWord; }

      case ExecR: 
      {
        if (execMode == false)
        {
          // Also set where to go when it returns (the next instruction)
          regarray[`CodeReturnReg] = ipointer + 4;

          // IP is reset to zero
          ipointer = 0;

          // We are in an exec now
          execMode = true;
        }
      }

      case Exit: 
      {
        //$display("Processing exit");

        // If we are not in an exec this will stall because the IP
        // will not change at all.
        if (execMode == true)
        {
          // Set IP back to where we need it to be
          ipointer = regarray[`CodeReturnReg];

          // We are out of an exec now
          execMode = false;
        }
      }

      case DoutR: 
      {
        // In simulation we use $display for this
        $display("DebugOut %h", regValue[0]);
  
        // FPGA we hit the 7seg display with the value
        debug = regValue[0];
      }

      case DinR: 
      {
        regarray[regAddress[7:0]] = ramValue;
      }

      case DlenR: 
      {
        regarray[regAddress[7:0]] = dbgBufferLength;
      }

      case VpEnable: 
      {
        addrVirtual = 1;
      }

      default: 
      {
        // In simulation we want this to be obvious
        $display("Unknown instruction %h", opCode);
      }
    }

    //$display("opDataWord == %h", opDataWord);


    // Move the instruction pointer along
    if (condJump == true)
    {
      ipointer = opDataWord;
      debug3 = 8;
    }
    else 
    {
      if (opCode != `JmpC &&
          opCode != `CallR &&
          opCode != `Ret &&
          opCode != `RCallRC &&
          opCode != `RRet &&
          opCode != `ExecR &&
          opCode != `Exit
          )
      {
        //$display("Incrementing ip");

        if (Is8ByteOpcode(opCode) == 1)
        {
          ipointer = ipointer + 8;
          debug3 = 9;
        }
        else
        {
          ipointer = ipointer + 4;
          debug3 = 10;
        }
      }
    }

    //$display("Finished instruction %h", opCode);

    if (opCode != 0 && opCode <= `MaxOpCode)
    {
      // Mode change back if opCode was valid
      mode = `InitialMode;
    }
    else
    {
      // Bad opCode, halt and report
      mode = `ErrorHalt;
      errorHaltData = opCode;
    }
  }

  state ErrorHalt
  {
    $display("Halt with error code %h and data %h", errorHaltCode, errorHaltData);
    debug = errorHaltData;
  }
}
