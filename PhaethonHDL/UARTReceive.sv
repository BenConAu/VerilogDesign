module UARTReceive(
  clk, 
  reset,
  rxd,
  dataComplete,
  dataOutput,
  endCount
  );

  input wire clk;              // The CPU clock signal
  input wire reset;            // Reset wire for module
  input wire rxd;              // UART RxD
  output reg dataComplete;     // Signal that data is complete
  output reg[7:0] dataOutput;  // Data returned when data is complete
  reg[31:0] startCount;        // Count of start bits seen
  output reg[31:0] endCount;   // Count of start bits seen

  reg [15:0] state = 0;
  reg [15:0] counter = 0;
  reg [7:0] data = 0;

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      state <= 0;
      dataComplete <= 0;
      data <= 0;
      counter <= 0;
      startCount <= 0;
      endCount <= 0;
    end
    else
    begin
      if (state == 0)
      begin
        // Data is no longer complete
        dataComplete <= 0;
  
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
            dataComplete <= 1;
            endCount <= endCount + 1;
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
          // Keep counting until in middle of next bit
          counter <= counter + 1;
        end
      end
    end
  end
  
endmodule