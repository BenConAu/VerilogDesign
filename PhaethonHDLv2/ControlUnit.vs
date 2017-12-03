import "../PhaethonISA/Generated/PhaethonOpCode.vs";
import "MemoryController.vs";
import "StagedFloatingAdder.vs";

enum ErrorCode
{
  BadInstr1,
  BadInstr2,
  BadMem,
}

module ControlUnit(
  clock clk,                  // [Input]  Clock driving the ALU
  uint32 ramIn,               // [Input]  RAM at requested address
  ControllerStatus mcStatus,  // [Input]  RAM ready signal
  out ControllerCommand mcCommand, // [Output] RAM controller command
  out MemoryRequest request,  // [Output] Memory request
  out bool addrVirtual,       // [Output] Virtual flag for RAM
  out bool execMode,          // [Output] Whether we are in user or kernel
  out uint32 ptAddress,       // [Output] Page Table Address
  out bool uartReadReq,       // [Output] uart read requested
  bool uartReadAck,           // [Input]  Flag to indicate read success
  uint8 uartReadData,         // [Input]  Actual data read 
  out bool uartWriteReq,      // [Output] uart write requested
  out uint8 uartWriteData,    // [Output] uart data to write
  bool uartWriteReady,        // [Input]  uart ready to send
  out uint32 ipointer,        // [Debug]  Instruction pointer value
  out OpCode opCode,          // [Debug]  current opCode value
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

//  `include "Common.sv"

  // Local registers that need initialization
  uint32 counter = 0;
  bool initComplete = false;
  
  const uint8 StackPointerReg = 0;
  const uint8 FlagsReg        = 1;
  const uint8 SysCallReg      = 2;
  const uint8 CodeReturnReg   = 3;
  const uint8 PageTableReg    = 4;
  const uint8 FixedRegCount   = 5;

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
  ErrorCode   errorHaltCode;
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

  FloatingAdd         fAdd0 = FloatingAdd(clk, regValue2[0], regValue3[0], false, out fAddResult[0]);
  FloatingAdd         fAdd1 = FloatingAdd(clk, regValue2[1], regValue3[1], false, out fAddResult[1]);
  FloatingAdd         fAdd2 = FloatingAdd(clk, regValue2[2], regValue3[2], false, out fAddResult[2]);
  FloatingAdd         fAdd3 = FloatingAdd(clk, regValue2[3], regValue3[3], false, out fAddResult[3]);
  FloatingAdd         fSub =  FloatingAdd(clk, regValue[0], regValue2[0], true, out fSubResult);
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

  state initial
  {
    //__display("Doing ControlUnit initial state");

    // We initialize most stuff here because it can be done once
    // here and work both with the reset input and with an initializer
    // for the registers.
    debug = 0;
    debug2 = 0;
    debug3 = 1u9;
    
    mcCommand = ControllerCommand.None;
    uartReadReq = false;
    opDataWord = 0xffffffff;
    opCode = OpCode.Unknown;
    fOpEnable = 0b0000000;
    ipointer = 0;
    condJump = false;
    dbgBufferWriteReq = false;
    dbgBufferReadReq = false;
    execMode = false;
    addrVirtual = false;

    // First real register position
    rPos = FixedRegCount;

    // Some stuff is hard to do with initializers, so we do it here
    regarray[StackPointerReg] = 0;
    regarray[FlagsReg] = 0;
    regarray[SysCallReg] = 0;
    regarray[CodeReturnReg] = 0;
    regarray[PageTableReg] = 0;

    // Mark initialization as complete
    initComplete = true;

    transition InitialMode;
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
    ptAddress = regarray[`PageTableReg];

    //debug3[8:0] = mode;
    //debug2[7:0] = mode;
    //debug2[15:8] = opCode;
    debug2[11:0] = ipointer[11:0];
    debug2[31:12] = { 0u14, opCode };
  }

  // Mode InitialMode: Schedule read of code at instruction pointer and clear
  //         out enable bits for auxillary modules.
  state InitialMode
  {
    // Begin RAM read for instruction data
    mcCommand = ControllerCommand.Request;
    request.Address = ipointer;
    request.WriteEnable = false;

    opDataWord = 0x0badf00d;

    // Clear out stuff for the pipeline
    fOpEnable = 0b0000000;
    condJump = false;

    //__display("Doing ControlUnit initial mode");
 
    transition InstrReadComplete;
  }

  // Mode InstrReadComplete: Handle completion of instruction pointer read request and
  //         decode the instruction data, including the opCode
  //         of the instruction and the affected registers.
  state InstrReadComplete
  {
    // Stop request
    mcCommand = ControllerCommand.None;

    if (mcStatus == ControllerStatus.Ready)
    {
      // If ramReady is high then we have received something
      //__display("Doing ControlUnit InstrReadComplete mode, read complete, address is %h, instr RAM is %h", request.Address, ramIn);

      opCode = OpCode(ramIn[5:0]);
      regAddress =  (ramIn[15:8] >= 64)  ? (ramIn[15:8] - 64)  : (ramIn[15:8] + rPos);
      regAddress2 = (ramIn[23:16] >= 64) ? (ramIn[23:16] - 64) : (ramIn[23:16] + rPos);
      regAddress3 = (ramIn[31:24] >= 64) ? (ramIn[31:24] - 64) : (ramIn[31:24] + rPos);

      // Move to next mode now
      transition RegValueSet;
    }
    else 
    {
      if (mcStatus == ControllerStatus.Error)
      {
        __display("Memory controller error when reading instruction, halting");

        // Set error condition
        errorHaltCode = ErrorCode.BadInstr1;
        errorHaltData = request.Address;
        transition ErrorHalt;
      }
    }
  }

  // Mode RegValueSet: Schedule read of additional code for opCodes that
  //         store word data. Read in register values for
  //         registers referenced by the instruction.
  state RegValueSet
  {
    //__display("Doing ControlUnit RegValueSet mode");

    // Read values from registers
    regValue[0] = regarray[regAddress[7:0]];
    if (opCode == OpCode.VfaddRRR)
    {
      regValue[1] = regarray[regAddress[7:0] + 1];
      regValue[2] = regarray[regAddress[7:0] + 2];
      regValue[3] = regarray[regAddress[7:0] + 3];
    }

    regValue2[0] = regarray[regAddress2[7:0]];
    if (opCode == OpCode.VfaddRRR)
    {
      regValue2[1] = regarray[regAddress2[7:0] + 1];
      regValue2[2] = regarray[regAddress2[7:0] + 2];
      regValue2[3] = regarray[regAddress2[7:0] + 3];
    }

    regValue3[0] = regarray[regAddress3[7:0]];
    if (opCode == OpCode.VfaddRRR)
    {
      regValue3[1] = regarray[regAddress3[7:0] + 1];
      regValue3[2] = regarray[regAddress3[7:0] + 2];
      regValue3[3] = regarray[regAddress3[7:0] + 3];
    }

    // Enable operation for module
    if (opCode == OpCode.FaddRRR || opCode == OpCode.VfaddRRR) { fOpEnable[0:0] = true; }
    if (opCode == OpCode.FsubRR) { fOpEnable[1:1] = true; }
    if (opCode == OpCode.FconvR) { fOpEnable[2:2] = true; }
    if (opCode == OpCode.FmulRRR) { fOpEnable[3:3] = true; }
    if (opCode == OpCode.FmuladdRRR) { fOpEnable[4:4] = true; }
    if (opCode == OpCode.FminRR) { fOpEnable[5:5] = true; }
    if (opCode == OpCode.FmaxRR) { fOpEnable[5:5] = true; }
    if (opCode == OpCode.FdivRR) { fOpEnable[6:6] = true; }

    // Determine if a conditional jump needs to happen
    if (opCode == OpCode.JneC && regarray[FlagsReg][0:0] == false) { condJump = true; }
    if (opCode == OpCode.JeC && regarray[FlagsReg][0:0] == true) { condJump = true; }
    if (opCode == OpCode.JzRC && regarray[regAddress[7:0]] == 0) { condJump = true; }
    if (opCode == OpCode.JnzRC && regarray[regAddress[7:0]] != 0) { condJump = true; }

    if (Is8ByteOpcode(opCode))
    {
      //__display("Transition to DataWordComplete");

      // Read values from ram requested by instruction
      mcCommand = ControllerCommand.Request;
      request.Address = ipointer + 4;
      request.WriteEnable = false;

      // We need to move into further modes
      transition DataWordComplete;
    }
    else 
    {
      if (IsRAMOpcode(opCode) || IsIOOpcode(opCode))
      {
        //__display("Transition to RWRequest");

        // We are not reading a constant, but we might still be
        // doing a RAM operation, move into the mode where we do that
        transition RWRequest;
      }
      else
      {
        //__display("Transition to ProcessOpCode");

        // Since there is no word data, there is no need
        // to wait for that word data to come back, and there
        // can be no further reads or writes since the word
        // data is where the address would go
        transition ProcessOpCode;
      }
    }
  }

  // Mode DataWordComplete: Complete read of additional code for opCodes that
  //         store word data. We only } up in this mode if
  //         the appropriate opCode is set, so no need to check
  //         the opCode.
  state DataWordComplete
  {
    //__display("Entering DataWordComplete");

    // Stop request
    mcCommand = ControllerCommand.None;

    if (mcStatus == ControllerStatus.Ready)
    {
      //__display("DataWordComplete with word %h", ramIn);

      // Store ram values requested
      opDataWord = ramIn;

      // Move to next mode - only progress to data read / write
      // for opCodes that actually need it.
      if (IsRAMOpcode(opCode) || IsIOOpcode(opCode))
      {
        //$display("DataWordComplete getting another RW %h", opCode);
        transition RWRequest;
      }
      else
      {
        //$display("DataWordComplete processing an OpCode %h", opCode);
        transition ProcessOpCode;
      }
    }
    else 
    {
      //__display("DataWordComplete, MMU not ready");

      if (mcStatus == ControllerStatus.Error)
      {
        __display("DataWordComplete, MMU returned error");

        // Set error condition
        errorHaltCode = ErrorCode.BadInstr2;
        errorHaltData = request.Address;
        transition ErrorHalt;
      }
    }        
  }

  state RWRequest
  {
    if (IsRAMOpcode(opCode))
    {
      //__display("RWRequest for RAM opcode");

      switch (opCode)
      {
        case OpCode.MovRdC: 
        {
          // Read values from address encoded in code
          mcCommand = ControllerCommand.Request;
          request.Address = opDataWord;
          request.WriteEnable = false;

          //$display("Requesting RdC read from %h", opDataWord);
        }

        case OpCode.MovRdRo: 
        {
          // First register is destination, second register is base address, 
          // constant stores offset in bytes.
          mcCommand = ControllerCommand.Request;
          request.Address = opDataWord + regValue2[0];
          request.WriteEnable = false;

          //$display("Requesting read from %h", opDataWord + regValue2);
        }

        case OpCode.MovRdRoR: 
        {
          // First register is destination, second register is base address, 
          // constant stores size of item, and third register stores index of item.
          mcCommand = ControllerCommand.Request;
          request.Address = regValue2[0] + opDataWord * regValue3[0];
          request.WriteEnable = false;

          //$display("Requesting read from %h", regValue2[0] + opDataWord * regValue3[0]);
        }

        case OpCode.MovRdR: 
        {
          // Read values from address encoded in code
          mcCommand = ControllerCommand.Request;
          request.Address = regValue2[0];
          request.WriteEnable = false;

          //$display("Requesting read from %h", opDataWord + regValue2);
        }

        case OpCode.PopR: 
        {
          // Read value from stack
          mcCommand = ControllerCommand.Request;
          request.Address = regarray[`StackPointerReg] - 4;
          request.WriteEnable = false;

          //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
        }

        case OpCode.Ret: 
        {
          // Read value from stack
          mcCommand = ControllerCommand.Request;
          request.Address = regarray[`StackPointerReg] - 4;
          request.WriteEnable = false;
        
          //$display("Requesting read from %h - 4", regarray[`StackPointerReg]);
        }
      
        case OpCode.MovdCR: 
        {
          // Write values to ram requested by instruction
          mcCommand = ControllerCommand.Request;
          request.Address = opDataWord;
          request.WriteEnable = true;
          request.WriteData = regValue2[0];
        
          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord);
        }

        case OpCode.MovdRoR: 
        {
          // Write values to ram requested by instruction
          mcCommand = ControllerCommand.Request;
          request.Address = opDataWord + regValue[0];
          request.WriteEnable = true;
          request.WriteData = regValue2[0];
        
          //$display("Reqesting write %h to address value %h", regValue2[0], opDataWord + regValue[0]);
        }
      
        case OpCode.MovdRoRR: 
        {
          // first register is base address, constant stores size of items, 
          // second register stores index of item, third register is destination, 
          mcCommand = ControllerCommand.Request;
          request.Address = regValue[0] + opDataWord * regValue2[0];
          request.WriteEnable = true;
          request.WriteData = regValue3[0];
        
          //__display("Reqesting MovdRoRR write %h to address value %h", regValue3[0], regValue[0] + opDataWord * regValue2[0]);
        }

        case OpCode.PushR: 
        {
          // Write register value to stack
          mcCommand = ControllerCommand.Request;
          request.Address = regarray[`StackPointerReg];
          request.WriteEnable = true;
          request.WriteData = regValue[0];
        
          //$display("Reqesting push %h", regValue);
        }
      
        case OpCode.CallR: 
        {
          // Write ip to stack
          mcCommand = ControllerCommand.Request;
          request.Address = regarray[`StackPointerReg];
          request.WriteEnable = true;
          request.WriteData = ipointer;
        
          //$display("Reqesting push %h", regValue);
        }

        case OpCode.SysCallRRR: 
        {
          // Read function address from register
          mcCommand = ControllerCommand.Request;
          request.Address = regValue[0];
          request.WriteEnable = false;
        }
      }

      transition MemRWComplete;
    }
    else 
    {
      if (IsIOOpcode(opCode))
      {
        //$display("IO opcode");

        // Stop request
        mcCommand = ControllerCommand.None;

        switch (opCode)
        {
          case OpCode.ReadPortRR: 
          {
            switch (regValue2[0])
            {
              case 1: 
              {
                // Port 1 is read from UART
                uartReadReq = true;
              }
          
              //case 2: 
              //{
                // Port 2 is UART write ready status
              //}
          
              default: 
              {
                __display("Unknown port %h being read", regValue[0]);
              }
            }
          }

          case OpCode.WritePortRR: 
          {
            uartWriteReq = true;
            uartWriteData = regValue2[0][7:0];
          }

          case OpCode.DoutR: 
          {
            //$display("DoutR write req");

            dbgBufferWriteReq = true;
            dbgBufferWriteData = regValue[0];
          }

          case OpCode.DinR: 
          {
            dbgBufferReadReq = true;
          }
        }

        transition IORWWait;
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
    mcCommand = ControllerCommand.None;

    if (mcStatus == ControllerStatus.Ready)
    {
      if (opCode == OpCode.MovRdC || opCode == OpCode.MovRdRo || opCode == OpCode.MovRdRoR || opCode == OpCode.MovRdR || opCode == OpCode.PopR || opCode == OpCode.Ret)
      {
        //$display("Receiving read address value %h", ramIn);

        // Store ram values requested
        ramValue = ramIn;
      }

      transition ProcessOpCode;
    }
    else 
    {
      if (mcStatus == ControllerStatus.Error)
      {
        if (!execMode)
        {
          __display("Memory controller says access to protected page from kernel mode, execMode = %h", execMode);

          // Set error condition if supervisor hits this
          transition ErrorHalt;
          errorHaltCode = ErrorCode.BadMem;
          errorHaltData = request.Address;
        }
        else
        {
          __display("Memory controller says access to protected page from user mode, execMode = %h", execMode);

          // Exit back to supervisor if user hits this
          opCode = OpCode.Exit;
          transition ProcessOpCode;
        }
      }
    }
  }

  state IORWComplete 
  {
    if (opCode == OpCode.ReadPortRR)
    {
      switch (regValue2[0])
      {
        case 1: 
        {
          // Read from UART is now complete, return
          if (uartReadAck == true)
          {
            ramValue[7:0] = uartReadData;
            ramValue[31:8] = 1u24;
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
          ramValue[31:1] = 0u31;
        }

        default: 
        {
          __display("Unknown port %h being read", regValue[0]);
        }
      }
    }
    else 
    {
      if (opCode == OpCode.DinR)
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
      case OpCode.MovRC:  { regarray[regAddress[7:0]] = opDataWord;   }            // mov reg, const
      case OpCode.MovRdC: { regarray[regAddress[7:0]] = ramValue;     }            // mov reg, [addr]
      case OpCode.MovRR:  { regarray[regAddress[7:0]] = regValue2[0]; }            // mov reg, reg

      case OpCode.PackRRR: 
      {
        switch (regValue3[0][1:0])
        {
          case 0: { regarray[regAddress[7:0]][7:0] = regValue2[0][7:0]; }
          case 1: { regarray[regAddress[7:0]][15:8] = regValue2[0][7:0]; }
          case 2: { regarray[regAddress[7:0]][23:16] = regValue2[0][7:0]; }
          case 3: { regarray[regAddress[7:0]][31:24] = regValue2[0][7:0]; }
          default: { __display("Out of range byte position"); }
        }
      }

      case OpCode.MovRdRo:  { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg + const]
      case OpCode.MovRdRoR: { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg + const * reg]
      case OpCode.MovRdR:   { regarray[regAddress[7:0]] = ramValue; }              // mov reg, [reg]
      case OpCode.MovdCR:   { } // Done above
      case OpCode.MovdRoR:  { } // Done above
      case OpCode.MovdRoRR: { } // Done above

      case OpCode.LeaRRoR: 
      {
        //$display("Doing lea with opDataWord %h", opDataWord);
        regarray[regAddress[7:0]] = regValue2[0] + opDataWord * regValue3[0];
      }

      case OpCode.ReadPortRR: { regarray[regAddress[7:0]] = ramValue; }            // ReadPort reg, reg
      //case WritePortRR: { } // Done above

      case OpCode.PushR: 
      {
        regarray[`StackPointerReg] = regarray[`StackPointerReg] + 4;                             // push reg
      }

      case OpCode.PopR: 
      {
        regarray[regAddress[7:0]] = ramValue;                        // pop reg
        regarray[`StackPointerReg] = regarray[`StackPointerReg] - 4;
      }

      case OpCode.CallR: 
      {
        // Stack pointer increases like a push
        regarray[`StackPointerReg] = regarray[`StackPointerReg] + 4;                             // call reg

        // Jump to the function
        ipointer = regValue[0];
        debug3 = 3u9;

        //$display("Doing a call");
      }

      case OpCode.Ret: 
      {
        // Stack pointer decreases like a pop
        regarray[`StackPointerReg] = regarray[`StackPointerReg] - 4;                             // ret

        // Return to the saved position, after the call
        ipointer = ramValue + 4;
        debug3 = 4u9;

        //$display("Doing a ret");
      }

      case OpCode.RCallRC: 
      {
        // Store return address
        regarray[rPos + opDataWord] = ipointer;

        // Store arg value
        regarray[rPos + opDataWord + 1] = opDataWord;

        // Shift register window
        rPos = rPos + opDataWord + 2;

        // Jump to the function
        ipointer = regValue[0];
        debug3 = 5u9;

        //$display("Doing a register shift call to %h", regValue[0]);
      }

      case OpCode.RRet: 
      {
        // Get the return address
        ipointer = regarray[rPos - 2] + 8;
        debug3 = 6u9;

        // Get the window value
        rPos = rPos - (regarray[rPos - 1] + 2);

        //$display("Doing an rret");
      }

      case OpCode.CmpRR: // cmp reg, reg
      {                                                   
        regarray[FlagsReg][0:0] = (regValue[0] == regValue2[0] ? true : false);
        regarray[FlagsReg][1:1] = (regValue[0] .< regValue2[0] ? true : false);
        regarray[FlagsReg][2:2] = (regValue[0] >. regValue2[0] ? true : false);
      }

      case OpCode.CmpRC: 
      {
        regarray[FlagsReg][0:0] = (regValue[0] == opDataWord ? true : false);
        regarray[FlagsReg][1:1] = (regValue[0] .< opDataWord ? true : false);
        regarray[FlagsReg][2:2] = (regValue[0] >. opDataWord ? true : false);
      }

      case OpCode.CmpERRR: 
      {                                                 // cmpe reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] == regValue3[0] ? 1 : 0);
      }

      case OpCode.CmpNeRRR: 
      {                                                 // cmpne reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] != regValue3[0] ? 1 : 0);
      }

      case OpCode.CmpLtRRR: 
      {                                                 // cmplt reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] .< regValue3[0] ? 1 : 0);
      }

      case OpCode.CmpGtRRR: 
      {                                                 // cmpgt reg, reg, reg
        regarray[regAddress[7:0]] = (regValue2[0] >. regValue3[0] ? 1 : 0);
      }

      case OpCode.JmpC: 
      {  
        ipointer = opDataWord;                              // jmp address
        debug3 = 7u9;
      }

      case OpCode.JneC:       { } // Done above
      case OpCode.JeC:        { } // Done above
      case OpCode.JzRC:       { } // Done above
      case OpCode.JnzRC:      { } // Done above

      case OpCode.FaddRRR:    { regarray[regAddress[7:0]] = fAddResult[0]; }        // fadd reg, reg, reg
      case OpCode.FsubRR:     { regarray[regAddress[7:0]] = fSubResult;     }        // fsub reg, reg
      case OpCode.FconvR:     { regarray[regAddress[7:0]] = fConvResult;    }        // fconv reg
      case OpCode.FmulRRR:    { regarray[regAddress[7:0]] = fMulResult;     }        // fmul reg, reg, reg
      case OpCode.FdivRR:     { regarray[regAddress[7:0]] = fDivResult;     }
      case OpCode.FmuladdRRR: { regarray[regAddress[7:0]] = fMulAddResult;   }       // fmul reg, reg
      case OpCode.FminRR:     { regarray[regAddress[7:0]] = (fCompareResult == 0b01 ? regValue2[0] : regValue[0]); }
      case OpCode.FmaxRR:     { regarray[regAddress[7:0]] = (fCompareResult == 0b11 ? regValue2[0] : regValue[0]); }

      case OpCode.VfaddRRR: 
      {
        regarray[regAddress[7:0]] = fAddResult[0];
        regarray[regAddress[7:0] + 1] = fAddResult[1];
        regarray[regAddress[7:0] + 2] = fAddResult[2];
        regarray[regAddress[7:0] + 3] = fAddResult[3];
      }

      case OpCode.AddRRC:    { regarray[regAddress[7:0]] = regValue2[0] + opDataWord;    } // add reg, reg, const
      case OpCode.AddRRR:    { regarray[regAddress[7:0]] = regValue2[0] + regValue3[0];  } // add reg, reg, reg
      case OpCode.SubRRC:    { regarray[regAddress[7:0]] = regValue2[0] - opDataWord;    } // add reg, reg, const
      case OpCode.SubRRR:    { regarray[regAddress[7:0]] = regValue2[0] - regValue3[0];  } // add reg, reg, reg
      case OpCode.IncR:      { regarray[regAddress[7:0]] = regValue[0] + 1;              } // dec reg
      case OpCode.DecR:      { regarray[regAddress[7:0]] = regValue[0] - 1;              } // dec reg
      case OpCode.ShlRRR:    { regarray[regAddress[7:0]] = regValue2[0] << regValue3[0]; } // shl reg, reg, reg
      case OpCode.ShrRRR:    { regarray[regAddress[7:0]] = regValue2[0] >> regValue3[0]; } // shl reg, reg, reg
      case OpCode.NegRR:     { regarray[regAddress[7:0]] = -regValue2[0];                } // neg reg, reg

      case OpCode.MulAddRRC: { regarray[regAddress[7:0]] = regValue[0] + regValue2[0] * opDataWord; }

      case OpCode.ExecR: 
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

      case OpCode.Exit: 
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

      case OpCode.DoutR: 
      {
        // In simulation we use $display for this
        __display("DebugOut %h", regValue[0]);
  
        // FPGA we hit the 7seg display with the value
        debug = regValue[0];
      }

      case OpCode.DinR: 
      {
        regarray[regAddress[7:0]] = ramValue;
      }

      case OpCode.DlenR: 
      {
        regarray[regAddress[7:0]] = dbgBufferLength;
      }

      case OpCode.VpEnable: 
      {
        addrVirtual = true;
      }

      default: 
      {
        // In simulation we want this to be obvious
        __display("Unknown instruction %h", opCode);
      }
    }

    //$display("opDataWord == %h", opDataWord);


    // Move the instruction pointer along
    if (condJump == true)
    {
      ipointer = opDataWord;
      debug3 = 8u9;
    }
    else 
    {
      if (opCode != OpCode.JmpC &&
          opCode != OpCode.CallR &&
          opCode != OpCode.Ret &&
          opCode != OpCode.RCallRC &&
          opCode != OpCode.RRet &&
          opCode != OpCode.ExecR &&
          opCode != OpCode.Exit
          )
      {
        //$display("Incrementing ip");

        if (Is8ByteOpcode(opCode))
        {
          ipointer = ipointer + 8;
          debug3 = 9u9;
        }
        else
        {
          ipointer = ipointer + 4;
          debug3 = 10u9;
        }
      }
    }

    //$display("Finished instruction %h", opCode);

    if (opCode != OpCode.Unknown && opCode <= OpCode.MaxOpCode)
    {
      // Mode change back if opCode was valid
      transition InitialMode;
    }
    else
    {
      // Bad opCode, halt and report
      //errorHaltData = opCode;
      transition ErrorHalt;
    }
  }

  state ErrorHalt
  {
    __display("Halt with error code %h and data %h", errorHaltCode, errorHaltData);
    debug = errorHaltData;
  }
}
