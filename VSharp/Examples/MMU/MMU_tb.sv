module MMU_TestBench(
  );
  // State definitions
  `define __initial 0
  `define __BeginPTWrite1 1
  `define __EndPTWrite1 2
  `define __EndPTWrite2 3
  `define __BeginVirtualRead 4
  `define __EndPTRead1 5
  `define __End 6
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  wire[31:0] RamOutput;
  wire[1:0] mcStatus;
  reg[64:0] mcRequest;
  reg[0:0] mcCommand;
  reg[0:0] mcAddrVirtual;
  reg[0:0] mcExecMode;
  wire[31:0] phRamRead;
  wire[31:0] phRamWrite;
  wire[31:0] phRamAddress;
  wire[0:0] phRequest;
  wire[0:0] phWriteEnable;
  wire[31:0] debug;
  reg[31:0] ptAddress;
  reg[63:0] entry1;
  PhysicalRAM ram(clk, phRamAddress, phWriteEnable, phRamWrite, phRamRead);
  MemoryController MMU1(clk, RamOutput, mcStatus, mcRequest, mcCommand, mcAddrVirtual, mcExecMode, phRamRead, phRamAddress, phRamWrite, phRequest, phWriteEnable, ptAddress, debug);
  initial
  begin
    # 300 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        mcExecMode <= 1'b0;
        mcAddrVirtual <= 1'b0;
        ptAddress <= 32'd0;
        entry1 <= { 1'b1, 1'b0, 22'd0, 20'd2748, 20'd7 };
        fsmState <= `__BeginPTWrite1;
      end
      `__BeginPTWrite1: begin
        mcRequest <= { 32'd21984, entry1[63:32], 1'b1 };
        mcCommand <= 1;
        fsmState <= `__EndPTWrite1;
      end
      `__EndPTWrite1: begin
        if (mcStatus == 2)
        begin
          mcRequest[64:33] <= 32'd21988;
          mcRequest[32:1] <= entry1[31:0];
          mcCommand <= 1;
          fsmState <= `__EndPTWrite2;
        end
        else
        begin
          mcCommand <= 0;
        end
      end
      `__EndPTWrite2: begin
        if (mcStatus == 2)
        begin
          mcAddrVirtual <= 1'b1;
          mcRequest[64:33] <= 32'd11255808;
          mcRequest[32:1] <= 32'd3203395597;
          mcCommand <= 1;
          fsmState <= `__BeginVirtualRead;
        end
        else
        begin
          mcCommand <= 0;
        end
      end
      `__BeginVirtualRead: begin
        if (mcStatus == 2)
        begin
          mcRequest[0:0] <= 1'b0;
          mcCommand <= 1;
          fsmState <= `__EndPTRead1;
        end
        else
        begin
          mcCommand <= 0;
        end
      end
      `__EndPTRead1: begin
        mcCommand <= 0;
        if (mcStatus == 2)
        begin
          fsmState <= `__End;
        end
      end
      `__End: begin
      end
    endcase
  end
endmodule
