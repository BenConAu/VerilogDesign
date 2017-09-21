module UARTReceive(
  clk,
  rxd,
  dataComplete,
  dataOutput,
  endCount
  );
  // State definitions
  `define __initial 0
  `define __Waiting 1
  `define __Collecting 2
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[0:0] rxd;
  output reg[0:0] dataComplete;
  output reg[7:0] dataOutput;
  output reg[31:0] endCount;
  reg[31:0] startCount;
  reg[15:0] BitCount = 32'd0;
  reg[15:0] counter = 32'd0;
  reg[7:0] data = 32'd0;
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        BitCount <= 16'd0;
        dataComplete <= 1'b0;
        data <= 8'd0;
        counter <= 16'd0;
        startCount <= 32'd0;
        endCount <= 32'd0;
      end
      `__Waiting: begin
        dataComplete <= 1'b0;
        if (rxd == 32'd1)
        begin
          counter <= 16'd0;
        end
        else
        begin
          if (counter == 16'd217)
          begin
            startCount <= startCount + 32'd1;
            counter <= 16'd0;
            data <= 8'd0;
            BitCount <= 16'd0;
            fsmState <= `__Collecting;
          end
          else
          begin
            counter <= counter + 16'd1;
          end
        end
      end
      `__Collecting: begin
        if (counter == 32'd434)
        begin
          if (BitCount == 32'd8)
          begin
            dataOutput <= data;
            dataComplete <= 1'b1;
            endCount <= endCount + 16'd1;
            fsmState <= `__Waiting;
          end
          else
          begin
            BitCount <= BitCount + 16'd1;
            data[BitCount] <= rxd;
          end
          counter <= 16'd0;
        end
        else
        begin
          counter <= counter + 16'd1;
        end
      end
    endcase
  end
endmodule
