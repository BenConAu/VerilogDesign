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

  // Local variables
  integer i;

  always @(posedge clk)
  begin
    case (mode)
    3: begin
      // RAM init mode

      case (opAddress)
        // Move memory from 16 in ram to r0
        0:  ram[0] = 2;
        1:  ram[1] = 0;
        2:  ram[2] = 16;
        3:  ram[3] = 0;
        //  Move memory from 17 in ram to r1
        4:  ram[4] = 2;
        5:  ram[5] = 1;
        6:  ram[6] = 17;
        7:  ram[7] = 0;        
        //  Add r1 to r0
        8:  ram[8] = 4;
        9:  ram[9] = 0;
        10: ram[10] = 1;
        11: ram[11] = 0;
        //  Store in 18 ram
        12: ram[12] = 3;
        13: ram[13] = 0;
        14: ram[14] = 18;
        15: ram[15] = 0;
        default: ram[opAddress] = opAddress;
      endcase

      opAddress <= opAddress + 1;

      if (opAddress == RAMSIZE)
      begin
        // Start doing real processing
        mode = 0;
      end
    end

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
        3: ram[opAddress] = regValue;                        // mov [addr], reg
        4: regarray[regAddress[3:0]] <= regValue + regValue2; // add reg, reg
      endcase

      debug = ram[18];

      // Move the instruction pointer along
      ipointer <= ipointer + 4;

      // Mode change
      mode <= 0;      
    end
    endcase

    r0 <= regarray[0];
    r1 <= regarray[1];

  end

  always @(posedge reset)
  begin
    // Clear our outputs
    assign ipointer = 0;
    assign opCode = 0;
    assign opAddress = 0;
    assign mode = 3;
  end

  always @(negedge reset)
  begin
    // Clear our outputs
    deassign ipointer;
    deassign opCode;
    deassign opAddress;
    deassign mode;
  end

endmodule