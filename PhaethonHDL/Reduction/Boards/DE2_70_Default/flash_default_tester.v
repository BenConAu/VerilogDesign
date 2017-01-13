module flash_default_tester (
//CONTROL//
input iBUSSW ,
input iTRIKEY ,
input iDEFAULT,
input iCLK_28,

//FL
inout	[14:0]	FLASH_DQ,			
inout			FLASH_DQ15_AM1,			
output	[25:0]	oFLASH_A,		
output			oFLASH_WE_N,			
output			oFLASH_RST_N,			
output			oFLASH_WP_N,			
input			iFLASH_RY_N,			
output			oFLASH_BYTE_N,			
output			oFLASH_OE_N,			
output			oFLASH_CE_N,			

output oLCD_ON  ,
output oLCD_BLON,
output [7:0] LCD_D,
output oLCD_RW,
output oLCD_EN,
output oLCD_RS,


input iLCD_ON_1  ,
input iLCD_BLON_1,
input [7:0] LCD_D_1,
input iLCD_RW_1,
input iLCD_EN_1,
input iLCD_RS_1,



//TEST PIN//
output TIME_OUT,
output oSTATUS,
output oEND,
output oERASE_STATUS,

output PROG,	
output READ,
output ERASE,
output RESET,

output VERIFY_TIME

);

// LCD BUS //

assign oLCD_ON  = (LCD_BUS)? oLCD_ON_2  :iLCD_ON_1;  
assign oLCD_BLON= (LCD_BUS)? oLCD_BLON_2:iLCD_BLON_1;
assign LCD_D    = (LCD_BUS)? LCD_D_2    :LCD_D_1;    
assign oLCD_RW  = (LCD_BUS)? oLCD_RW_2  :iLCD_RW_1;  
assign oLCD_EN  = (LCD_BUS)? oLCD_EN_2  :iLCD_EN_1;  
assign oLCD_RS  = (LCD_BUS)? oLCD_RS_2  :iLCD_RS_1;  
                                      


	
// LED DISP //	

assign  TIME_OUT    = timer_1[33] ;

// TimeOUT //

reg [33:0] timer_1;

// Power Up Trigger //

reg  [25:0]power_delay ;
reg  FLASH_TEST_tr     ;
reg  LCD_BUS           ;

always @( negedge iDEFAULT or posedge iCLK_28 )begin
if (!iDEFAULT ) begin 
    power_delay   = 0;
    FLASH_TEST_tr = 1;
	LCD_BUS = 0;
	timer_1 =34'h3ffffffff;
end
else
begin 
if ( !power_delay[25] )  begin 
      power_delay    = power_delay + 1;
      FLASH_TEST_tr  = iTRIKEY ;      
	  if    ( !FLASH_TEST_tr ) begin LCD_BUS   = 1; timer_1 =0; end
end
else  begin
    FLASH_TEST_tr = 1;
    if ( !TIME_OUT ) timer_1 = timer_1 + 1;
	if ( !iBUSSW  ) LCD_BUS  = 0; 
	
end
end
end




wire OK   ;
wire FAIL ;
wire [21:0]flash_addr ;
wire [3:0]flash_cmd  ;

DE2_70_flash_word_tester tester(
.TIME_OUT(TIME_OUT),
.iCLK_28    ( iCLK_28  ),
.iSTART     ( FLASH_TEST_tr  ),
.oEND       ( oEND),
.oERASE_STATUS(oERASE_STATUS),
.oSTATUS      (oSTATUS),
	
	
.FLASH_DQ      (FLASH_DQ      ),			
.FLASH_DQ15_AM1(FLASH_DQ15_AM1),			
.oFLASH_A      (oFLASH_A      ),				
.oFLASH_WE_N   (oFLASH_WE_N   ),			
.oFLASH_RST_N  (oFLASH_RST_N  ),			
.oFLASH_WP_N   (oFLASH_WP_N   ),			 
.iFLASH_RY_N   (iFLASH_RY_N   ),			
.oFLASH_BYTE_N (oFLASH_BYTE_N ),			
.oFLASH_OE_N   (oFLASH_OE_N   ),			
.oFLASH_CE_N   (oFLASH_CE_N   ),		

//TEST//
.ERASE      (ERASE      ),
.PROG       (PROG       ),	
.READ       (READ       ),
.RESET      (RESET      ),
.OK  (OK  ),
.FAIL(FAIL),
      
.VERIFY_TIME(VERIFY_TIME),
.flash_addr (flash_addr ),
.flash_cmd  (flash_cmd  )


);
	




// FLASH ROM DATA //
reg [15:0]rn;
always @(posedge oFLASH_OE_N) rn={ FLASH_DQ15_AM1 , FLASH_DQ };

	
//////text to LCD/////////
wire [7:0] txt1;
wire [7:0] txt2;
wire [7:0] txt3;
wire [7:0] txt4;
wire [7:0] txt5;
wire [7:0] txt6;
wire [7:0] txt7;
assign {txt1[7:0],txt2[7:0],txt3[7:0],txt4[7:0],txt5[7:0],txt6[7:0],txt7[7:0]}=(
(flash_cmd==4)?{8'h20,8'h65,8'h72,8'h61,8'h73,8'h65,8'h2E}:(	//"erase."//
(flash_cmd==1)?{8'h20,8'h77,8'h72,8'h69,8'h74,8'h65,8'h2E}:(	//"write."//
(flash_cmd==0)?{8'h20,8'h72,8'h65,8'h61,8'h64,8'h2E,8'h2E}:(	//"read.."//
(flash_cmd==7)?{8'h20,8'h20,8'h20,8'h20,8'h20,8'h20,8'h20}:(	//"reset."//
(flash_cmd==8)?{8'h2D,8'h4F,8'h4B,8'h21,8'h2D,8'h2E,8'h20}:(	//"-OK!-."//
(flash_cmd==9)?{8'h2D,8'h46,8'h41,8'h49,8'h4C,8'h2D,8'h20}:0	//"-Fail-"//
)))))
);

wire lcd_res= ~ERASE & ~PROG & ~READ & ~RESET & ~OK & ~FAIL;

wire      oLCD_ON_2  =1;
wire      oLCD_BLON_2=1;
wire [7:0]LCD_D_2    ;
wire      oLCD_RW_2  ;
wire      oLCD_EN_2  ;
wire      oLCD_RS_2  ;



LCD L(	
	.txt1(txt1),
	.txt2(txt2),
	.txt3(txt3),
	.txt4(txt4),
	.txt5(txt5),
	.txt6(txt6),
	.txt7(txt7),

	.iCLK(iCLK_28),
	.iRST_N(lcd_res),
	.keded(0),

	.LCD_DATA(LCD_D_2  ),
	.LCD_RW  (oLCD_RW_2),
	.LCD_EN  (oLCD_EN_2),
	.LCD_RS  (oLCD_RS_2),
);



endmodule
