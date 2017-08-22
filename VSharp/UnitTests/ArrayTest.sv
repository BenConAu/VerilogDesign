module ArrayTest(
  clk,
  reset,
  in1,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire clk;
  input wire reset;
  input wire[31:0] in1;
  output reg[31:0] out1;
  reg[31:0] arr[7:0];
  reg[31:0] index;
  initial
  begin
    # 10 index = 1;
    # 10 index = 2;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%h", out1);
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= arr[index];
        index <= index + 1;
      end
    endcase
  end
endmodule
