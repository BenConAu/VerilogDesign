module floating(a, b, out, debug, clk);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;
  integer i;

  task UnpackMantissa;
    input [31:0] num;
    output [31:0] mant;
    reg [31:0] unsignedMant;
    begin
      // Make an unsigned representation of the mantissa in 9.23 form
      unsignedMant = {9'b000000001, num[22:0]};

      // Create 2s complement of that
      if (num[31:31] == 1)
        mant[31:0] = 1 + ~unsignedMant;
      else
        mant[31:0] = unsignedMant;
    end
  endtask

  task SignedShiftRight;
    input [31:0] ssin;
    input [31:0] ssshift;
    output [31:0] ssout;
    reg [31:0] mask;
    reg [31:0] leading;
    begin
      // Figure out the value to lead with based on high bit
      if (ssin[0:0] == 1)
        leading = 'hffffffff;
      else
        leading = 0;

      // Calculate mask for leading bits
      mask = 'hffffffff << (32 - ssshift);

      // Blend together
      ssout = (mask & leading) | (!mask & ssin >> ssshift);
    end
  endtask

  reg [1:0] sign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [31 : 0] aMant;
  reg [31 : 0] bMant;
  reg [31 : 0] aPrimeMant;
  reg [31 : 0] totalMant;
  reg [31 : 0] finalMant;

  always @(posedge clk)
  begin
    // Unpack the mantissa, make b the one with larger exponent
    if (a[30 : 23] < b[30 : 23])      
    begin
      aExp = a[30 : 23];
      UnpackMantissa(a, aMant);

      bExp = b[30 : 23];
      UnpackMantissa(b, bMant);
    end
    else
    begin
      aExp = b[30 : 23];
      UnpackMantissa(b, aMant);
      
      bExp = a[30 : 23];
      UnpackMantissa(a, bMant);
    end

    // Add the mantissas together, shifting the smaller exp one
    totalMant = (aMant << (bExp - aExp)) + bMant;
    debug = totalMant;

    // Figure out sign of total
    if (totalMant[25:25] == 1)
    begin
      sign = 1;
      finalMant = ~(totalMant - 1);
    end
    else
    begin
      sign = 0;
      finalMant = totalMant;
    end

    // Compensate the exponent if need be
    if (finalMant[24 : 24] == 1)
    begin
      out[30:23] = bExp + 1;
      out[22:0] = finalMant[23:1];
    end
    else
    begin
      out[30:23] = bExp;
      out[22:0] = finalMant[22:0];
    end
  
    out[31:31] = sign;
  end
  
endmodule // floating