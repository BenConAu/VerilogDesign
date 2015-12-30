module floating(out, debug, clk, reset);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk, reset;

  task UnpackMantissa;
    input [31:0] num;
    output [25:0] mant;
    begin
      // Pull sign bit to the front
      mant[25:25] <= num[31:31];
      mant[24:24] <= num[31:31];
    
      // Create 2s complement of the 23 bits
      if (num[31:31] == 1)
        mant[23:0] <= 1 + !{1'b1, num[22:0]};
      else
        mant[23:0] <= {1'b1, num[22:0]};

    end
  endtask

  reg [31 : 0] a;
  reg [31 : 0] b;

  reg [1:0] sign;
  reg [7 : 0] aExp;
  reg [7 : 0] bExp;
  reg [25 : 0] aMant;
  reg [25 : 0] bMant;
  reg [25 : 0] aPrimeMant;
  reg [31 : 0] totalMant;
  reg [31 : 0] finalMant;
  reg [31:0] mode;

  always @(posedge clk or posedge reset)
  begin
    if (reset)
    begin
      a <= 'h42000000; // 32
      //b = 'h40a00000; // 5
      //b <= 'h42000000; // 32
      b <= 'hc1200000;
      mode <= 0;
    end
    else
    begin
      case (mode)
      // Load subpart mode
      0: begin
        if (a[30 : 23] < b[30 : 23])      
        begin
          aExp <= a[30 : 23];
          UnpackMantissa(a, aMant);

          bExp <= b[30 : 23];
          UnpackMantissa(b, bMant);
        end
        else
        begin
          aExp <= b[30 : 23];
          UnpackMantissa(b, aMant);
          
          bExp <= a[30 : 23];
          UnpackMantissa(a, bMant);

        end

        debug <= 'h11;
        out <= aMant;
        mode <= 1;
      end

      1: begin
        // Calculate the total from the shifted mantissa of the bigger number
        totalMant <= (aMant >> (bExp - aExp)) + bMant;
        debug <= 'h22;

        out <= totalMant;
        mode <= 2;
      end

      2: begin
        // Figure out sign of total
        if (totalMant[25:25] == 1)
        begin
          sign <= 1;
          finalMant <= !(totalMant - 1);
        end
        else
        begin
          sign <= 0;
          finalMant <= totalMant;
        end

        // Compensate the exponent if need be
        if (finalMant[24 : 24] == 1)
        begin
          out[30:23] <= bExp + 1;
          out[22:0] <= finalMant[23:1];
        end
        else
        begin
          out[30:23] <= bExp;
          out[22:0] <= finalMant[22:0];
        end
  
        out[31:31] <= sign;

        debug <= 'h33;
        mode <= 0;
      end

      endcase
    end
  end
  
endmodule // floating