module MemoryController(
  reset,
  in1
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[31:0] in1;
  reg[31:0] p1;
  reg clk = 0; always #5 clk = !clk;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        if (p1[31:0] == 32'd0)
        begin
          $monitor("Member = %h", p1[31:0]);
        end
      end
    endcase
  end
endmodule
