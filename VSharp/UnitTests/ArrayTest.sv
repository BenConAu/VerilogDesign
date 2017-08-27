module ArrayTest(
  reset,
  in1,
  out1
  );
  // State definitions
  `define __initial 0
  `define __StartState 1
  // inputs / outputs
  input wire reset;
  input wire[31:0] in1;
  output reg[31:0] out1;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] arr[3:0];
  reg[31:0] index;
  initial
  begin
    # 10 index = 1;
    # 10 index = 2;
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%h", out1);
        out1 <= 0;
        arr[0] <= 1;
        arr[1] <= 3;
        arr[2] <= 5;
        arr[3] <= 7;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= arr[index];
        if (index < 3)
        begin
          index <= index + 1;
        end
      end
    endcase
  end
endmodule
