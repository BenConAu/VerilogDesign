module DemoModule(
  clk,
  reset,
  in1,
  out1
  )
begin
  // State definitions
  `define __initial 0
  `define __StartState 1
  `define __EndState 2
  // inputs / outputs
  input wire clk;
  input wire reset;
  input wire[31:0] in1;
  output reg[31:0] out1;
  // locals
  reg[31:0] _ExampleRegister;
  reg[15:0] _ExampleWord;
  reg[7:0] _ExampleByte;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
    begin
      `__initial: begin
        _ExampleRegister <= 0
        fsmState <= `__StartState;
      end
      `__StartState: begin
        fsmState <= `__EndState;
      end
      `__EndState: begin
        _ExampleRegister <= _ExampleRegister - 1
        fsmState <= `__StartState;
      end
    end
  end
end
