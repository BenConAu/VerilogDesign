task UnpackFloat;
  input [31:0] num;
  input [0:0] neg;
  output [31:0] mant;
  output [7:0] exp;
  reg [31:0] unsignedMant;
  begin
    // Make an unsigned representation of the mantissa in 9.23 form
    unsignedMant = {9'b000000001, num[22:0]};

    // Create 2s complement of that based on negation bit and sign
    // bit of the input
    if ((num[31:31] ^ neg) == 1)
      mant[31:0] = 1 + ~unsignedMant;
    else
      mant[31:0] = unsignedMant;
    
    // Just copy exponent across
    exp = num[30:23];
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

task NormalizeMantissa;
  input [31:0] nmMant;
  input [31:0] nmClz;
  output [31:0] nmNorm;
  // Leading zeros should be 8, so shift to that
  if (nmClz > 8)
    nmNorm = nmMant << (nmClz - 8);
  else
    nmNorm = nmMant >> (8 - nmClz);  
endtask