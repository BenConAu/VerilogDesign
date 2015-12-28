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
  output reg [7 : 0]  ipointer;
  output reg [7 : 0]  opCode;
  output reg [15 : 0] r0;
  output reg [15 : 0] r1;
  output reg [15 : 0] debug;
  input  wire	        clk, reset;

  // Local registers
  reg        [7 : 0]  ram[0 : RAMSIZE - 1];
  reg        [15 : 0] regarray[0 : 15];
  reg        [1 : 0]  mode;
  reg        [7 : 0]  ramValue;
  reg        [15 : 0] regValue;
  reg        [15 : 0] regValue2;
  reg        [15 : 0] opAddress;
  reg        [7 : 0]  regAddress;

  always @(posedge clk or posedge reset)
  begin
    if (reset)
    begin
      ipointer <= 0;
      opCode <= 0;
      opAddress <= 0;
      mode <= 3;
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
  
        mode <= 1;
      end
        
      1: begin
        // Read values from ram or register as needed
        ramValue <= ram[opAddress];
        regValue <= regarray[regAddress[3:0]];
        regValue2 <= regarray[opAddress[3:0]];
  
        // Mode change
        mode <= 2;      
      end
  
      2: begin
        // Now we can do writes
        case (opCode)
          1: regarray[regAddress[3:0]] <= opAddress;            // mov reg, const
          2: regarray[regAddress[3:0]] <= ramValue;             // mov reg, [addr]
          3: ram[opAddress] <= regValue;                        // mov [addr], reg
          4: regarray[regAddress[3:0]] <= regValue + regValue2; // add reg, reg
          5: debug <= regValue;                                 // setdebug reg
        endcase
  
        // Move the instruction pointer along
        ipointer <= ipointer + 4;
  
        // Mode change
        mode <= 0;      
      end

      3: begin
        // RAM init mode
  
        case (opAddress)
          // Move memory from 16 in ram to r0
          0:  ram[0] <= 2;
          1:  ram[1] <= 0;
          2:  ram[2] <= 16;
          3:  ram[3] <= 0;
          //  Move memory from 17 in ram to r1
          4:  ram[4] <= 2;
          5:  ram[5] <= 1;
          6:  ram[6] <= 17;
          7:  ram[7] <= 0;        
          //  Add r1 to r0
          8:  ram[8] <= 4;
          9:  ram[9] <= 0;
          10: ram[10] <= 1;
          11: ram[11] <= 0;
          //  Set debug to r0
          12: ram[12] <= 5;
          13: ram[13] <= 0;
          14: ram[14] <= 0;
          15: ram[15] <= 0;
          16: ram[16] <= 16;
          17: ram[17] <= 17;
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