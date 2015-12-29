module floating(out, debug, clk, reset);

  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk, reset;

  reg [31 : 0] a;
  reg [31 : 0] b;

  reg aSign, bSign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [23 : 0] aMant;
  reg [23 : 0] bMant;

  reg [23 : 0] aPrimeMant;

  always @(posedge clk or posedge reset)
  begin
    if (reset)
    begin
      a = 'h42000000;
      b = 'h40a00000;

      if (a[30 : 23] < b[30 : 23])      
      begin
        aSign = a[31 : 31];
        aExp = a[30 : 23];
        aMant[22:0] = a[22: 0];

        bSign = b[31 : 31];
        bExp = b[30 : 23];
        bMant[22:0] = b[22: 0];
      end
      else
      begin
        aSign = b[31 : 31];
        aExp = b[30 : 23];
        aMant[22:0] = b[22: 0];

        bSign = a[31 : 31];
        bExp = a[30 : 23];
        bMant[22:0] = a[22: 0];
      end

      aMant[23:23] = 1;
      bMant[23:23] = 1;

      debug = bExp - aExp;

      // Calculate the shifted mantissa of the bigger number
      aPrimeMant = aMant >> (bExp - aExp);

      // Ignore sign
      out[31:31] <= bSign;
      out[30:23] <= bExp;
      out[22:0] <= aPrimeMant + bMant;
    end
    else
    begin
      out <= out + 1;
    end
  end
  
endmodule // floating