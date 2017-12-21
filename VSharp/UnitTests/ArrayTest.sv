module ArrayTest(
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
  reg[31:0] arr[0:3];
  reg[31:0] index;
  initial
  begin
    # 10 index = 32'd1;
    # 10 index = 32'd2;
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%h", out1);
        out1 <= 32'd0;
        arr[32'd0] <= 32'd1;
        arr[32'd1] <= 32'd3;
        arr[32'd2] <= 32'd5;
        arr[32'd3] <= 32'd7;
        fsmState <= `__StartState;
      end
      `__StartState: begin
        out1 <= arr[index];
        if (index < 32'd3)
        begin
          index <= index + 32'd1;
        end
      end
    endcase
  end
endmodule
