module reader(
  ipointer, 
  opCode, 
  clk, 
  reset,
  r0,
  r1,
  debug
  );

  // Constants
  parameter WIDTH = 8;
  parameter RAMSIZE = 64;

  // Input / output
  output reg [7:0]  ipointer;
  output reg [7:0]  opCode;
  output reg [31:0] r0;
  output reg [31:0] r1;
  output reg [31:0] debug;
  input  wire	      clk, reset;

  // Local registers
  reg        [7:0]  ram[0:RAMSIZE - 1];
  reg        [31:0] regarray[0:15];
  reg        [1:0]  mode;
  reg        [31:0] ramValue;
  reg        [31:0] regValue;
  reg        [31:0] regValue2;
  reg        [15:0] opAddress;
  reg        [7:0]  regAddress;
  reg        [2:0]  fOpEnable;
  
  wire       [31:0] fAddResult;
  wire       [31:0] fSubResult;
  wire       [31:0] floatDebug;
  wire       [31:0] fConvResult;

  FloatingAdd     fAdd(regValue, regValue2, 1'b0, fAddResult, floatDebug, clk, fOpEnable[0:0]);
  FloatingAdd     fSub(regValue, regValue2, 1'b1, fSubResult, floatDebug, clk, fOpEnable[1:1]);
  FloatingFromInt fConv(regValue, fConvResult, floatDebug, clk, fOpEnable[2:2]);

  always @(posedge clk or posedge reset)
  begin
    if (reset)
    begin
      ipointer <= 0;
      opCode <= 0;
      opAddress <= 0;
      mode <= 3;
      fOpEnable <= 3'b000;
    end
    else
    begin
      case (mode)
      0: begin
        // Start a new instruction, pull away the instruction data from RAM
        opCode <= ram[ipointer];
        regAddress <= ram[ipointer + 1];
        opAddress[7 : 0] <= ram[ipointer + 2];
        opAddress[15 : 8] <= ram[ipointer + 3];
  
        fOpEnable <= 3'b000;
        mode <= 1;
      end
        
      1: begin
        // Read values from ram
        ramValue[7:0] <= ram[opAddress];
        ramValue[15:8] <= ram[opAddress + 1];
        ramValue[23:16] <= ram[opAddress + 2];
        ramValue[31:24] <= ram[opAddress + 3];

        // Read values from registers
        regValue <= regarray[regAddress[3:0]];
        regValue2 <= regarray[opAddress[3:0]];
  
        // Mode change
        mode <= 2;

        // Enable operation for module
        if (opCode == 6) fOpEnable[0:0] <= 1;
        if (opCode == 7) fOpEnable[1:1] <= 1;
        if (opCode == 8) fOpEnable[2:2] <= 1;
      end
  
      2: begin
        // Now we can do writes
        case (opCode)
          1:  regarray[regAddress[3:0]] <= opAddress;            // mov reg, const
          2:  regarray[regAddress[3:0]] <= ramValue;             // mov reg, [addr]
          3:  regarray[regAddress[3:0]] <= regValue2;            // mov reg, reg
          4:  ram[opAddress] <= regValue;                        // mov [addr], reg

          10: regarray[regAddress[3:0]] <= regValue + regValue2; // add reg, reg

          20: regarray[regAddress[3:0]] <= fAddResult;           // fadd reg, reg
          21: regarray[regAddress[3:0]] <= fSubResult;           // fsub reg, reg
          22: regarray[regAddress[3:0]] <= fConvResult;          // fconv reg
          
          30: debug <= regValue;                                 // setdebug reg
        endcase
  
        // Move the instruction pointer along
        ipointer <= ipointer + 4;
  
        // Mode change
        mode <= 0;      
      end

      3: begin
        // RAM init mode
  
        case (opAddress)
          // Load 21 to r0
          0:  ram[0] <= 1;
          1:  ram[1] <= 0;
          2:  ram[2] <= 21;
          3:  ram[3] <= 0;
          // Load 35 to r1
          4:  ram[4] <= 1;
          5:  ram[5] <= 1;
          6:  ram[6] <= 35;
          7:  ram[7] <= 0;        
          // Convert r0 to float
          8:  ram[8] <= 8;
          9:  ram[9] <= 0;
          10: ram[10] <= 0;
          11: ram[11] <= 0;
          // Convert r1 to float
          12: ram[12] <= 8;
          13: ram[13] <= 1;
          14: ram[14] <= 0;
          15: ram[15] <= 0;
          // fadd r0, r1
          16: ram[16] <= 6;
          17: ram[17] <= 0;
          18: ram[18] <= 1;
          19: ram[19] <= 0;
          // Other RAM needed 447a0000 and c1200000
          20: ram[20] <= 'h00;
          21: ram[21] <= 'h00;
          22: ram[22] <= 'h7a;
          23: ram[23] <= 'h44;
          24: ram[24] <= 'h00;
          25: ram[25] <= 'h00;
          26: ram[26] <= 'h20;
          27: ram[27] <= 'hc1;
        endcase
  
        opAddress <= opAddress + 1;
  
        if (opAddress == RAMSIZE)
        begin
          // Start doing real processing
          mode <= 0;
        end
      end
  
      endcase
  
      r0 <= regarray[0];
      r1 <= regarray[1];
    end
  end

endmodule