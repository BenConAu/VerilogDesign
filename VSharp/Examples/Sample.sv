module DemoModule
begin
  input wire[31:0] in1;
  output reg[31:0] out1;
  reg[31:0] _ExampleRegister;
  reg[15:0] _ExampleWord;
  reg[7:0] _ExampleByte;
  always @(posedge clk)
  begin
    case initial
    begin
    end
    case StartState
    begin
    end
    case EndState
    begin
    end
  end
end
