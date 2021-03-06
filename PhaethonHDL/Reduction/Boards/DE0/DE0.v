
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module DE0(

	//////////// CLOCK //////////
	CLOCK_50,

	//////////// LED //////////
	LED,

	//////////// KEY //////////
	KEY,

	//////////// SW //////////
	SW,

	//////////// SDRAM //////////
	DRAM_ADDR,
	DRAM_BA,
	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CLK,
	DRAM_CS_N,
	DRAM_DQ,
	DRAM_DQM,
	DRAM_RAS_N,
	DRAM_WE_N,

	//////////// EPCS //////////
	EPCS_ASDO,
	EPCS_DATA0,
	EPCS_DCLK,
	EPCS_NCSO,

	//////////// Accelerometer and EEPROM //////////
	G_SENSOR_CS_N,
	G_SENSOR_INT,
	I2C_SCLK,
	I2C_SDAT,

	//////////// ADC //////////
	ADC_CS_N,
	ADC_SADDR,
	ADC_SCLK,
	ADC_SDAT,

	//////////// 2x13 GPIO Header //////////
	GPIO_2,
	GPIO_2_IN,

	//////////// GPIO_0, GPIO_0 connect to GPIO Default //////////
	gpio0,
	gpio0_IN,

	//////////// GPIO_1, GPIO_1 connect to GPIO Default //////////
	gpio1,
	gpio1_IN 
);

//=======================================================
//  PARAMETER declarations
//=======================================================


//=======================================================
//  PORT declarations
//=======================================================

//////////// CLOCK //////////
input 		          		CLOCK_50;

//////////// LED //////////
output		     [7:0]		LED;

//////////// KEY //////////
input 		     [1:0]		KEY;

//////////// SW //////////
input 		     [3:0]		SW;

//////////// SDRAM //////////
output		    [12:0]		DRAM_ADDR;
output		     [1:0]		DRAM_BA;
output		          		DRAM_CAS_N;
output		          		DRAM_CKE;
output		          		DRAM_CLK;
output		          		DRAM_CS_N;
inout 		    [15:0]		DRAM_DQ;
output		     [1:0]		DRAM_DQM;
output		          		DRAM_RAS_N;
output		          		DRAM_WE_N;

//////////// EPCS //////////
output		          		EPCS_ASDO;
input 		          		EPCS_DATA0;
output		          		EPCS_DCLK;
output		          		EPCS_NCSO;

//////////// Accelerometer and EEPROM //////////
output		          		G_SENSOR_CS_N;
input 		          		G_SENSOR_INT;
output		          		I2C_SCLK;
inout 		          		I2C_SDAT;

//////////// ADC //////////
output		          		ADC_CS_N;
output		          		ADC_SADDR;
output		          		ADC_SCLK;
input 		          		ADC_SDAT;

//////////// 2x13 GPIO Header //////////
inout 		    [12:0]		GPIO_2;
input 		     [2:0]		GPIO_2_IN;

//////////// GPIO_0, GPIO_0 connect to GPIO Default //////////
inout 		    [33:0]		gpio0;
input 		     [1:0]		gpio0_IN;

//////////// GPIO_1, GPIO_1 connect to GPIO Default //////////
inout 		    [33:0]		gpio1;
input 		     [1:0]		gpio1_IN;


//=======================================================
//  REG/WIRE declarations
//=======================================================
wire [10:0] ramAddress;
wire [31:0] ramIn;
wire [31:0] ramOut;
wire writeReq;
wire [7:0] debug;

ram u0(
	.clock(CLOCK_50),
	.address(ramAddress),
	.data(ramOut),
	.wren(writeReq),
	.q(ramIn)
	);


//=======================================================
//  Structural coding
//=======================================================

ALU u1(
  .clk(CLOCK_50),         // [Input]  Clock driving the ALU
  .reset(0),       // [Input]  Reset pin
  .ramIn(ramIn),       // [Input]  RAM at requested address
  .readAck(1),     // [Input]  RAM read acknowledge
  .writeAck(1),    // [Input]  RAM write acknowledge
  .ramAddress(ramAddress),  // [Output] RAM address requested
  .ramOut(ramOut),      // [Output] RAM to write
//  .readReq,     // [Output] RAM read request
  .writeReq(writeReq),    // [Output] RAM write request
  /*
  .ipointer,    // [Debug]  Instruction pointer value
  .opCode,      // [Debug]  current opCode value
  .r0,          // [Debug]  current r0 value
  .r1,          // [Debug]  current r1 value
  .r2,          // [Debug]  current r2 value
  .r3,          // [Debug]  current r3 value
  .r4,          // [Debug]  current r4 value
  .r5,          // [Debug]  current r5 value
  .rPos,        // [Debug]  current rPos (register window) value
*/
  .debug(debug)        // [Output] Debug port
  );
  
 assign LED[7:0] = ramAddress;


endmodule
