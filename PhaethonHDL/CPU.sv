module CPU(
  clk,            // [Input]  Clock driving the ALU
  reset,          // [Input]  Reset pin
  phRamRead,      // [Input]  RAM at requested address
  phRamAddress,   // [Output] RAM address requested
  phRamWrite,     // [Output] RAM to write
  phReadReq,      // [Output] RAM read request
  phWriteReq,     // [Output] RAM write request  
  uartReadReq,    // [Output] uart read requested
  uartReadAck,    // [Input]  Flag to indicate read success
  uartReadData,   // [Input]  Actual data read 
  uartWriteReq,   // [Output] uart write requested
  uartWriteData,  // [Output] uart data to write
  uartWriteReady, // [Input]  uart ready to send
  debug,          // [Output] Debug port 1
  debug2,         // [Output] Debug port 2
  debug3          // [Output] Debug port 3
  );

  input wire [0:0]   clk;
  input wire [0:0]   reset;
  input wire [31:0]  phRamRead;
  output wire [31:0] phRamAddress;
  output wire [31:0] phRamWrite;
  output wire [0:0]  phReadReq;  
  output wire [0:0]  phWriteReq;
  output wire [0:0]  uartReadReq;
  input wire [0:0]   uartReadAck;
  input wire [7:0]   uartReadData;
  output wire        uartWriteReq;
  output wire [7:0]  uartWriteData;
  input wire         uartWriteReady;
  output wire [31:0] debug;
  output wire [31:0] debug2;
  output wire [8:0] debug3;

  wire [31:0]  mcRamRead;
  wire [0:0]   mcRamReady;
  wire [31:0]  mcRamAddress;
  wire [31:0]  mcRamWrite;
  wire [0:0]   mcReadReq;
  wire [0:0]   mcWriteReq;
  wire [0:0]   mcAddrVirtual;
  wire [31:0]  ptAddress;
  
  wire [31:0]  iPointer;
  wire [7:0]   opCode;
  wire [31:0]  r0;
  wire [31:0]  r1;
  wire [31:0]  r2;
  wire [31:0]  r3;
  wire [31:0]  r4;
  wire [31:0]  r5;
  wire [7:0]   rPos;

  ALU alu(
    clk,
    reset,
    mcRamRead,
    mcRamReady,
    mcRamAddress,
    mcRamWrite,
    mcReadReq,
    mcWriteReq,
    mcAddrVirtual,
    ptAddress,
    uartReadReq,    // [Output] uart read requested
    uartReadAck,    // [Input]  Flag to indicate read success
    uartReadData,   // [Input] Actual data read 
    uartWriteReq,   // [Output] uart write requested
    uartWriteData,  // [Output] uart data to write
    uartWriteReady, // [Input]  uart ready to send
    iPointer,
    opCode,
    r0,
    r1,
    r2,
    r3,
    r4,
    r5,
    rPos,
    debug,
    debug2,
    debug3
    );

  wire [31:0] mcDebug;

  MemoryController mc1(
    clk,              // Global clock
    reset,            // Reset
    mcRamRead,        // [Output] RAM at requested address
    mcRamReady,       // [Output] RAM is ready to be picked up
    mcRamAddress,     // [Input] RAM address requested
    mcRamWrite,       // [Input] RAM to write
    mcReadReq,        // [Input] RAM read request
    mcWriteReq,       // [Input] RAM write request
    mcAddrVirtual,    // [Input] Virtual flag for RAM
    phRamRead,        // [Input]  RAM at requested address
    phRamAddress,     // [Output] RAM address requested
    phRamWrite,       // [Output] RAM to write
    phReadReq,        // [Output] RAM read request
    phWriteReq,       // [Output] RAM write request
    ptAddress,        // [Input] Page table address
    mcDebug           // [Output] Debug port
  );

  //initial
     //$monitor("At time %t, ip = %h, opCode = %h, mcReadReq = %h, mcRamAddress = %h, mcRamReady = %h, ramValue = %h, r[0:1:2:3:4:5] = %h:%h:%h:%h:%h:%h, rPos = %h, debug = %h",
        //$time, iPointer[15:0], opCode, mcReadReq, mcRamAddress, mcRamReady, mcRamRead, r0, r1, r2, r3, r4, r5, rPos, debug);

endmodule