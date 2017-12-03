import "PhysicalRAM.vs";
import "../CPU.vs";

module CPUTestBench()
{
	drive
	{
		3000: __finish;
	}

  clock clk;

  wire uint32 phRamAddress;
  wire bool  phWriteEnable;
  wire bool phRequest;
  wire uint32 phRamWrite;
  
  // The value that we want to write to physical RAM
  wire uint32 phRamRead;

  PhysicalRAM ram = PhysicalRAM(
    clk, 
    phRamAddress, 
    phWriteEnable, 
    phRamWrite, 
    out phRamRead);

  wire bool  uartReadReq;
  wire uint32 debug;
  wire uint32 debug2;
  wire uint<9> debug3;

  // UART stuff
  wire bool uartReadAck;
  wire uint8 uartReadData;
  wire bool uartWriteReq;
  wire uint8 uartWriteData;
  wire bool uartWriteReady;

  CPU cpu1 = CPU(
    clk,                // [Input]  Clock driving the ALU
    phRamRead,          // [Input]  RAM at requested address
    out phRamAddress,   // [Output] RAM address requested
    out phRamWrite,     // [Output] RAM to write
    out phWriteEnable,  // [Output] RAM read request
    out phRequest,      // [Output] RAM write request  
    out uartReadReq,    // [Output] uart read requested
    uartReadAck,        // [Input]  Flag to indicate read success
    uartReadData,       // [Input]  Actual data read 
    out uartWriteReq,   // [Output] uart write requested
    out uartWriteData,  // [Output] uart data to write
    uartWriteReady,     // [Input]  uart ready to send
    out debug,          // [Output] Debug port
    out debug2,         // [Output] Another debug port
    out debug3          // [Output] And yet another debug port
    );

}
