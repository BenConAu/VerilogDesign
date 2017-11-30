module PhysicalRAM(
  clk,
  address,
  WriteEnable,
  WriteValue,
  ReadValue
  );
  // State definitions
  `define __initial 0
  `define __MemReadDone 1
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[31:0] address;
  input wire[0:0] WriteEnable;
  input wire[31:0] WriteValue;
  output reg[31:0] ReadValue;
  reg[7:0] fileRam[0:65535];
  reg[127:0] testName;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        if ($value$plusargs("ROMFILE=%s", testName))
        begin
          $readmemh(testName, fileRam, 32'd0);
        end
        fsmState <= `__MemReadDone;
      end
      `__MemReadDone: begin
      end
    endcase
    if (WriteEnable)
    begin
      fileRam[address] <= WriteValue[7:0];
      fileRam[address + 32'd1] <= WriteValue[15:8];
      fileRam[address + 32'd2] <= WriteValue[23:16];
      fileRam[address + 32'd3] <= WriteValue[31:24];
    end
    else
    begin
      $display("Retrieving address %h", address);
      ReadValue[7:0] <= fileRam[address];
      ReadValue[15:8] <= fileRam[address + 32'd1];
      ReadValue[23:16] <= fileRam[address + 32'd2];
      ReadValue[31:24] <= fileRam[address + 32'd3];
    end
  end
endmodule
