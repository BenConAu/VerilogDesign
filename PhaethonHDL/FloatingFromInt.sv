module FloatingFromInt(aSigned, out, debug, clk, enable);
  output reg [31:0] out;
  output reg [31:0] debug;
  input wire clk;
  input wire [31:0] aSigned;
  input wire [0:0] enable;

  `include "FloatingHelper.sv"

  reg [63:0] aBeforeMant;
  reg [31:0] clz;
  reg [31:0] a;

  always @(posedge clk or posedge enable)
  begin
    if (enable == 1)
    begin
      // Make this unsigned
      if (aSigned[31:31] == 1)
        a = (~aSigned) + 1;
      else
        a = aSigned;

      debug = a;

      // Make a 64 bit integer with the integer shifted 23
      aBeforeMant[63:32] = 0;
      aBeforeMant[31:0] = a;
      aBeforeMant = aBeforeMant << 23;

      // Figure out leading zero count of input
      CLZ(a, clz);

      // Compensate for the shifting we did and the expansion to 64 bit
      clz = clz + 9;

      // Leading zeros should be 40, so shift to that. The shift
      // will always be to the right
      aBeforeMant = aBeforeMant >> (40 - clz);

      // Treat it like a regular 32 bit mantissa now  
      out[31:31] = aSigned[31:31];
      out[30:23] = 127 + (40 - clz);
      out[22:0] = aBeforeMant[22:0];
    end
    else
      out = 'habc;
  end
  
endmodule // floating