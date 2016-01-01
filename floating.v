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
      if (ssin[31:31] == 1)
        leading = 'hffffffff;
      else
        leading = 0;

      // Calculate mask for leading bits
      mask = 'hffffffff << (32 - ssshift);

      // Blend together
      ssout = (mask & leading) | (~mask & ssin >> ssshift);
    end
  endtask

  task CLZ;
    input [31:0] num;
    output [31:0] res;
    reg [31:0] inter;
    begin
      inter = num;
      res = 0;
      if (inter[31:16] == 'h0000)
      begin
        res = res + 16;
        inter[31:16] = inter[15:0];
      end
      if (inter[31:24] == 'h00)
      begin
        res = res + 8;
        inter[31:24] = inter[25:16];
      end
      if (inter[31:28] == 'h0)
      begin
        res = res + 4;
        inter[31:28] = inter[27:24];
      end
      if (inter[31:30] == 2'b00)
      begin
        res = res + 2;
        inter[31:30] = inter[29:28];
      end
      if (inter[31] == 0)
      begin
        res = res + 1;
        inter[31] = inter[30];
      end
      if (inter[31] == 0)
      begin
        res = res + 1;
      end
    end
  endtask

  reg [1:0] sign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [31 : 0] aMant;
  reg [31 : 0] bMant;
  reg [31 : 0] aPrimeMant;
  reg [31 : 0] totalMant;
  reg [31:0] clz;

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
    SignedShiftRight(aMant, bExp - aExp, totalMant);
    totalMant = totalMant + bMant;

    // Figure out sign of total
    if (totalMant[31:31] == 1)
    begin
      sign = 1;
      totalMant = ~(totalMant - 1);
    end
    else
    begin
      sign = 0;
    end

    // Figure out leading zero count
    CLZ(totalMant, clz);

    // Leading zeros should be 8, so shift to that
    if (clz > 8)
      totalMant = totalMant << (clz - 8);
    else
      totalMant = totalMant >> (8 - clz);

    out[31:31] = sign;
    out[30:23] = bExp + (8 - clz);
    out[22:0] = totalMant[22:0];
  end
  
endmodule // floating