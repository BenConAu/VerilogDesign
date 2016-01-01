module floating(a, b, out, debug, clk);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk;
  input wire [31:0] a;
  input wire [31:0] b;

  task UnpackMantissa;
    input [31:0] num;
    output [25:0] mant;
    begin
      // Pull sign bit to the front
      mant[25:25] = num[31:31];
      mant[24:24] = num[31:31];
    
      // Create 2s complement of the 23 bits
      if (num[31:31] == 1)
        mant[23:0] = 1 + !{1'b1, num[22:0]};
      else
        mant[23:0] = {1'b1, num[22:0]};
    end
  endtask

  reg [1:0] sign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [25 : 0] aMant;
  reg [25 : 0] bMant;
  reg [25 : 0] aPrimeMant;
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

    debug = aMant;

    // Add the mantissas together, shifting the smaller exp one
    totalMant = (aMant >> (bExp - aExp)) + bMant;

    // Figure out sign of total
    if (totalMant[25:25] == 1)
    begin
      sign = 1;
      finalMant = !(totalMant - 1);
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