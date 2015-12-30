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

  always @(posedge clk or posedge reset)
  begin
    UnpackMantissa(out);

    debug <= 'h11;
  end
  
endmodule // floating