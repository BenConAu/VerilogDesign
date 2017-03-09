module TLB(
  clk,              // Global clock
  writeEnable,      // [Input] Whether we are doing lookup or write
  virtAddrIn,       // [Input] Virtual address
  physPageIn,       // [Input] Physical page (only used when storing)
  virtPageOut,      // [Output] Virtual page lookup from address
  physPageOut,      // [Output] Physical page lookup from address
  hit               // [Output] Whether this is a hit
  );

  input wire clk;
  input wire writeEnable;
  input wire [31:0] virtAddrIn;
  input wire [31:0] physPageIn;
  output wire [31:0] virtPageOut;
  output wire [31:0] physPageOut;
  output wire hit;

  reg [63:0] tlb[0:15];

  always @(posedge clk)
  begin
    if (writeEnable == 0)
    begin
      // Spit out the entries
      virtPageOut <= tlb[virtAddrIn[13:10]][63:32];
      physPageOut <= tlb[virtAddrIn[13:10]][31:0];

      // And also if they were valid
      if (virtAddrIn[31:10] == tlb[virtAddrIn[13:10]][63:32])
      begin
        hit <= 1;
      end
      else
      begin
        hit <= 0;
      end
    end
    else
    begin
      tlb[virtAddrIn[13:10]][63:32] <= virtAddrIn[31:10];
      tlb[virtAddrIn[13:10]][31:0] <= physPageIn;
    end
  end
endmodule
