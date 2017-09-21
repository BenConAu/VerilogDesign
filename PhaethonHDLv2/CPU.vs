#import "ControlUnit.vs";
#import "MemoryController.vs";

module CPU(
  clock clk,                // [Input]  Clock driving the ALU
  bool reset,               // [Input]  Reset pin
  uint32 phRamRead,         // [Input]  RAM at requested address
  out uint32 phRamAddress,  // [Output] RAM address requested
  out uint32 phRamWrite,     // [Output] RAM to write
  out bool phReadReq,       // [Output] RAM read request
  out bool phWriteReq,      // [Output] RAM write request  
  out bool uartReadReq,     // [Output] uart read requested
  bool uartReadAck,         // [Input]  Flag to indicate read success
  uint8 uartReadData,       // [Input]  Actual data read 
  out bool uartWriteReq,    // [Output] uart write requested
  out uint8 uartWriteData,  // [Output] uart data to write
  bool uartWriteReady,      // [Input]  uart ready to send
  out uint32 debug,         // [Output] Debug port 1
  out uint32 debug2,        // [Output] Debug port 2
  out uint<9> debug3        // [Output] Debug port 3
  )
{
  // Our main job in this module is wiring everything together
  wire uint32  mcRamRead;
  wire ControllerStatus   mcStatus;
  wire uint32  mcRamAddress;
  wire uint32  mcRamWrite;
  wire bool   mcReadReq;
  wire bool   mcWriteReq;
  wire bool   mcAddrVirtual;
  wire bool   mcExecMode;
  wire uint32  ptAddress;
  
  wire uint32  iPointer;
  wire OpCode   opCode;
  wire uint32  r0;
  wire uint32  r1;
  wire uint32  r2;
  wire uint32  r3;
  wire uint32  r4;
  wire uint32  r5;
  wire uint8   rPos;

  ControlUnit control = ControlUnit(
    clk,
    reset,
    mcRamRead,
    mcStatus,
    out mcRamAddress,
    out mcRamWrite,
    out mcReadReq,
    out mcWriteReq,
    out mcAddrVirtual,
    out mcExecMode,
    out ptAddress,
    out uartReadReq,    // [Output] uart read requested
    uartReadAck,    // [Input]  Flag to indicate read success
    uartReadData,   // [Input] Actual data read 
    out uartWriteReq,   // [Output] uart write requested
    out uartWriteData,  // [Output] uart data to write
    uartWriteReady, // [Input]  uart ready to send
    out iPointer,
    out opCode,
    out r0,
    out r1,
    out r2,
    out r3,
    out r4,
    out r5,
    out rPos,
    out debug,
    out debug2,
    out debug3
    );

  wire uint32 mcDebug;

  MemoryController mc1 = MemoryController(
    clk,              // Global clock
    out mcRamRead,        // [Output] RAM at requested address
    out mcStatus,         // [Output] RAM is ready to be picked up
    MemoryRequest(
      mcRamAddress,     // [Input] RAM address requested
      mcRamWrite,       // [Input] RAM to write
      mcReadReq),        // [Input] RAM read request)
    mcWriteReq,       // [Input] RAM write request
    mcAddrVirtual,    // [Input] Virtual flag for RAM
    mcExecMode,       // [Input] Exec mode
    phRamRead,        // [Input]  RAM at requested address
    phRamAddress,     // [Output] RAM address requested
    phRamWrite,       // [Output] RAM to write
    phReadReq,        // [Output] RAM read request
    phWriteReq,       // [Output] RAM write request
    ptAddress,        // [Input] Page table address
    mcDebug           // [Output] Debug port
  );

//initial
  //$monitor("At time %t, ip = %h, opCode = %h, mcReadReq = %h, mcRamAddress = %h, mcStatus = %h, ramValue = %h, kptAddress = %h, uptAddress = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
    //$time, iPointer[15:0], opCode, mcReadReq, mcRamAddress, mcStatus, mcRamRead, kptAddress, uptAddress, r0, r1, r2, r3, r4, r5, rPos, debug);

}