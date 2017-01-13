

// DE2_70_flash_word_tester //
module DE2_70_flash_word_tester (
input           TIME_OUT,
input  		    iCLK_28,
input  		    iSTART,
output reg      oEND,
output reg      oERASE_STATUS,
output 		    oSTATUS,
	
	
inout	[14:0]	FLASH_DQ,				//	FLASH Data bus 15 Bits (0 to 14)
inout			FLASH_DQ15_AM1,			//  FLASH Data bus Bit 15 or Address A-1
output	[25:0]	oFLASH_A,				//	FLASH Address bus 26 Bits
output			oFLASH_WE_N,			//	FLASH Write Enable
output			oFLASH_RST_N,			//	FLASH Reset
output			oFLASH_WP_N,			//	FLASH Write Protect /Programming Acceleration 
input			iFLASH_RY_N,			//	FLASH Ready/Busy output 
output			oFLASH_BYTE_N,			//	FLASH Byte/Word Mode Configuration
output			oFLASH_OE_N,			//	FLASH Output Enable
output			oFLASH_CE_N	,		//	FLASH Chip Enable

//TEST//
output reg   ERASE,
output reg   PROG,
output reg   READ,
output reg   RESET,

output reg   OK  ,
output reg   FAIL,

output       VERIFY_TIME,
output [21:0]flash_addr,
output [3:0] flash_cmd



);



wire WR_END;

reg [5:0]ST;

reg [1:0]SW;

reg [31:0]disp_cnt ;
always @(posedge iCLK_28) disp_cnt <= disp_cnt + 1;


always @( posedge disp_cnt[24]) begin
if (!iSTART) begin
	ST = 30;
	ERASE=0;
	oERASE_STATUS = 0;
	PROG =0;
	READ =0;
	OK   =0;	
	FAIL =0;	
	RESET=1;//reset trigger on//
	oEND =0;
end
else begin
if ( ( TIME_OUT )  && ( !oEND ) ) begin oEND = 1; FAIL = 1; ST = 5; end
case (ST)
	30:begin 
		ST    = 27;//ST-1;
		RESET = 0; //reset trigger off//
	end

	29:begin 
		ST    = ST-1;
	end

	28:begin 
		ST    = ST-1;
	end

	27:begin 
		ST    = 24;//ST-1;
		ERASE = 1;//erase trigger on//
	end

	26:begin 
		ST    = ST-1;
	end
	25:begin 
		ST    = ST-1;
	end

	24:begin 
		ST    = 21;//ST-1;
		ERASE = 0;//erase trigger off//		
	end
	23:begin 
		ST    = ST-1;
	end
	22:begin 
		ST    = ST-1;
	end
	

	21:begin 
		if ( flash_ready ) ST = 18;//ST-1;
	end

	20:begin 
		ST    = ST-1;
	end
	19:begin 
		ST    = ST-1;
	end

	18:begin 
		if ( iFLASH_RY_N )  begin
			oERASE_STATUS = 1;
			ST    = ST-1;
		end
	end

	17:begin 
		ST    = ST-1;
		READ  = 1;//READ trigger on//
		SW    = 3;
	end
	16:begin 
		ST    = ST-1;
		READ  = 0;//READ trigger on//
	end
    
	15:begin 
		if (WR_END)  ST=ST-1;
	end

	14:begin 
		ST    = 12;//ST-1;
		PROG  = 1;//PROGRAM trigger on//
		SW    = 2; //<<
	end
	
	13:begin 
		ST    = ST-1;
	end

	12:begin 
		ST    = 10;//ST-1;
		PROG  = 0;//PROGRAM trigger on//
	end
	11:begin 
		ST    = ST-1;
	end

	10:begin 
		if (WR_END)  ST=ST-1;
	end

	9:begin 
		ST    = ST-1;
		READ  = 1;//READ trigger on//
		SW    = 2; //<<
	end
	8:begin 
		ST    = ST-1;
		READ  = 0;//READ trigger on//
	end
    
	7:begin 
		if (WR_END)  ST=ST-1;
	end	
	6:begin 
		oEND = 1;
		ST=4;//ST-1;
		if ( oSTATUS )  OK = 1; else  FAIL = 1;
	end                                
	                                
	5:begin 
		ST=ST-1;
	end
	
	4:begin 
	 OK = 0;
	 FAIL = 0;
	end		
	
endcase
end
end






//FLASH CONTROLLER//

wire [15:0]flash_data;

wire flash_tr;
wire flash_ready;

assign flash_data = (//program data
	( SW[1:0] ==0)? flash_addr[15:0]:  (
	( SW[1:0] ==1)? 16'haaaa: 		    (
	( SW[1:0] ==2)? 16'h0000:  16'hffff
	)));


reg  error ; //<< oSTATUS

always @(posedge RESET or posedge oFLASH_OE_N) begin
if ( RESET ) error = 1;
else if ((VERIFY_TIME ) && (error))
	error = ~( { FLASH_DQ15_AM1 , FLASH_DQ } != flash_data ) ;
end

wire WE_CLK;
wire p_ready;
flash_writer f1(
    .WE_CLK(WE_CLK),
    .p_ready(p_ready),
	.iFLASH_RY_N ( iFLASH_RY_N ), // for program
	.iOSC_28     ( iCLK_28  ),  
	.iERASE      ( ERASE    ), 
	.iPROGRAM    ( PROG ), 
	.iVERIFY     ( READ     ), 
	.iOK(OK),
	.iFAIL(FAIL),
	

	.iRESET_N    ( RESET ),
	.oREAD_PRO_END (WR_END),
	.oVERIFY_TIME(VERIFY_TIME),//1 active

	.oFLASH_ADDR ( flash_addr),
	.oFLASH_CMD  ( flash_cmd ), 
	.oFLASH_TR   ( flash_tr  )   

);

// FLASH Controller //
wire FL_CE_o;



Flash_Controller u5(
    .p_ready(p_ready),
	.iFLASH_RY_N (iFLASH_RY_N ),	
	.iCLK  	( iCLK_28  ),
	.iRST_n	( 1'b1     ),
	.iStart	( flash_tr ),  //<< iSTART 
	.iDATA	( flash_data ),
	.iADDR	( flash_addr ), 
	.iCMD 	( flash_cmd ),     
	.oReady	( flash_ready ),
	.WE_CLK(WE_CLK),


	.FL_DQ   ( { FLASH_DQ15_AM1 , FLASH_DQ }    ) , //<< FLASH side
	.FL_ADDR (  oFLASH_A[21:0]  ),					//<< FLASH side
	.FL_WE_n (  oFLASH_WE_N ),    					//<< FLASH side
	.FL_CE_n ( oFLASH_CE_N ),     					//<< FLASH side
	.FL_OE_n ( oFLASH_OE_N )      					//<< FLASH side

);

assign   oFLASH_RST_N  = ~RESET;
assign	 oFLASH_WP_N   = 1;			    //	FLASH Write Protect /Programming Acceleration 
assign	 oFLASH_BYTE_N = 1;			//	FLASH Byte/Word Mode Configuration


assign   oSTATUS = error;


endmodule