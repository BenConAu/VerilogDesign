module UARTReceive(
  clk, 
  reset,
  rxd,
  dataComplete,
  dataOutput,
  startCount
  );

  output reg dataComplete;
  output reg[7:0] dataOutput;
  output reg[31:0] startCount;
  input wire clk;
  input wire reset;
  input wire rxd;

  reg [15:0] state;
  reg [15:0] counter;
  reg [7:0] data;

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      state <= 0;
      dataComplete <= 0;
      data <= 0;
      counter <= 0;
    end
    else
    begin
      if (state == 0)
      begin
        if (rxd == 1)
        begin
          // Did not maintain start state for long enough    
          counter <= 0;
        end
        else
        begin
          if (counter == 217)
          begin
            // We have decided this is a start bit
            startCount <= startCount + 1;
            counter <= 0;
            data <= 0;
    
            // Start grabbing data bits
            state <= 1;
          end
          else
          begin
            counter <= counter + 1;
          end
        end
      end
      else
      begin
        if (counter == 434)
        begin
          if (state == 9)
          begin
            // This was the stop bit, go back to start state
            state <= 0;
            dataOutput <= data;
          end
          else
          begin
            // Add the bit to our data register and look for the next one
            state <= state + 1;
            data[state - 1] <= rxd;   
          end
    
          // No matter what the counter resets
          counter <= 0;
        end
        else
        begin
          counter <= counter + 1;
        end
      end
    end
  end
  
endmodule