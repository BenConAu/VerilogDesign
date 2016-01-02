module sub(clk, enable, subOut);
  output reg[31:0] subOut;
  input wire[0:0] clk;
  input wire[0:0] enable;

  always @(posedge clk)
  begin
    subOut <= 'h1122;
  end
endmodule

module delay(out, debug, clk, reset);
  output reg [31 : 0] out;
  output reg [31 : 0] debug;
  input wire clk, reset;

  task UnpackMantissa;
    output [31:0] mant;
    begin
      mant <= 'hff;
    end
  endtask

  wire[31:0] inter;
  reg[0:0] enable;
  reg[0:0] mode;

  sub s1(clk, enable, inter);

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      mode <= 0;
      enable <= 0;
    end
    else
    begin
      if (mode == 0)
      begin
        enable <= 1;
        mode <= 1;
        out <= inter;
      end
      else
      begin
        enable <= 0;
        mode <= 0;
      end
    end
    //UnpackMantissa(out);
    //out <= 'hff;
    //enable <= 1b'1;


    //debug <= 'h11;
  end
  
endmodule // floating