module PhysicalRAM(
  clk,
  address,
  WriteEnable,
  WriteValue,
  ReadValue
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[31:0] address;
  input wire[0:0] WriteEnable;
  input wire[31:0] WriteValue;
  output reg[31:0] ReadValue;
  reg[7:0] fileRam[65535:0];
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("%d | RAM 0x0 = %h:%h:%h:%h:%h:%h:%h:%h | RAM 0x7000 = %h:%h:%h:%h:%h:%h:%h:%h | WriteEnable = %h | RAM value read = %h", $time, fileRam[32'd0], fileRam[32'd1], fileRam[32'd2], fileRam[32'd3], fileRam[32'd4], fileRam[32'd5], fileRam[32'd6], fileRam[32'd7], fileRam[32'd28672], fileRam[32'd28673], fileRam[32'd28674], fileRam[32'd28675], fileRam[32'd28676], fileRam[32'd28677], fileRam[32'd28678], fileRam[32'd28679], WriteEnable, ReadValue);
        if (WriteEnable)
        begin
          fileRam[address] <= WriteValue[7:0];
          fileRam[address + 32'd1] <= WriteValue[15:8];
          fileRam[address + 32'd2] <= WriteValue[23:16];
          fileRam[address + 32'd3] <= WriteValue[31:24];
        end
        else
        begin
          ReadValue[7:0] <= fileRam[address];
          ReadValue[15:8] <= fileRam[address + 32'd1];
          ReadValue[23:16] <= fileRam[address + 32'd2];
          ReadValue[31:24] <= fileRam[address + 32'd3];
        end
      end
    endcase
  end
endmodule
