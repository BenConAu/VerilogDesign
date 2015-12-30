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

  reg [31 : 0] aMant;

  always @(posedge clk or posedge reset)
  begin
    UnpackMantissa(aMant);

    debug <= 'h11;
    out <= aMant;
  end
  
endmodule // floating