#import "ControlUnit.vs";

module CPU(
  clock clk,                // [Input]  Clock driving the ALU
  uint32 phRamRead,         // [Input]  RAM at requested address
  out wire uint32 phRamAddress,  // [Output] RAM address requested
  out wire uint32 phRamWrite,     // [Output] RAM to write
  out wire bool phReadReq,       // [Output] RAM read request
  out wire bool phWriteReq,      // [Output] RAM write request  
  out wire bool uartReadReq,     // [Output] uart read requested
  bool uartReadAck,         // [Input]  Flag to indicate read success
  uint8 uartReadData,       // [Input]  Actual data read 
  out wire bool uartWriteReq,    // [Output] uart write requested
  out wire uint8 uartWriteData,  // [Output] uart data to write
  bool uartWriteReady,      // [Input]  uart ready to send
  out wire uint32 debug,         // [Output] Debug port 1
  out wire uint32 debug2,        // [Output] Debug port 2
  out wire uint<9> debug3        // [Output] Debug port 3
  )
{
  // Our main job in this module is wiring everything together
  wire uint32  mcRamRead;
  wire ControllerStatus mcStatus;
  wire ControllerCommand mcCommand;
  wire MemoryRequest mcRequest;
  wire bool    mcAddrVirtual;
  wire bool    mcExecMode;
  wire uint32  ptAddress;
  
  wire uint32  iPointer;
  wire OpCode  opCode;
  wire uint32  r0;
  wire uint32  r1;
  wire uint32  r2;
  wire uint32  r3;
  wire uint32  r4;
  wire uint32  r5;
  wire uint8   rPos;
  wire uint32  mcDebug;

  ControlUnit control = ControlUnit(
    clk,
    mcRamRead,
    mcStatus,
    out mcCommand,
    out mcRequest,
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

  MemoryController mc1 = MemoryController(
    clk,              // Global clock
    out mcRamRead,    // [Output] RAM at requested address
    out mcStatus,     // [Output] RAM is ready to be picked up
    mcRequest,        // [Input] Memory request
    mcCommand,        // [Input] Controller command
    mcAddrVirtual,    // [Input] Virtual flag for RAM
    mcExecMode,       // [Input] Exec mode
    phRamRead,        // [Input]  RAM at requested address
    out phRamAddress, // [Output] RAM address requested
    out phRamWrite,   // [Output] RAM to write
    out phReadReq,    // [Output] RAM read request
    out phWriteReq,   // [Output] RAM write request
    ptAddress,        // [Input] Page table address
    out mcDebug       // [Output] Debug port
  );


  state initial
  {
    //__display("CPU Initial state");
  }
//initial
  //$monitor("At time %t, ip = %h, opCode = %h, mcReadReq = %h, mcRamAddress = %h, mcStatus = %h, ramValue = %h, kptAddress = %h, uptAddress = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
    //$time, iPointer[15:0], opCode, mcReadReq, mcRamAddress, mcStatus, mcRamRead, kptAddress, uptAddress, r0, r1, r2, r3, r4, r5, rPos, debug);

}