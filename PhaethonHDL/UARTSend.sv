module UARTSend(
  clk, 
  reset,
  sendReq,
  dataInput,
  txd,
  ready,
  debug
  );

  input wire clk;              // The CPU clock signal
  input wire reset;            // Reset wire
  input wire sendReq;          // Send request
  input wire[7:0] dataInput;   // Data to send
  output reg txd = 1;          // UART TxD 
  output reg ready = 1;        // Signaled when ready to send
  output reg[31:0] debug = 0;  // Debug output

  reg [15:0] state = 0;
  reg [15:0] counter = 0;
  reg [7:0] data = 0;

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      txd <= 1;
      state <= 0;
      counter <= 0;
      data <= 0;
      ready <= 1;
    end
    else
    begin
      if (state == 0)
      begin
        // Is there a request to send something?
        if (sendReq == 1'b1)
        begin
          debug <= debug | 1;

          // Go into send state
          state <= 1;

          // Indicate that we are not ready to send anymore
          ready <= 0;

          // Save the data away
          data <= dataInput;

          // Reset our counter
          counter <= 0;
        
          // We will start with the txd low
          txd <= 0;
        end
        else
        begin
          debug <= 0;
        
          // Indicate we are ready to send
          ready <= 1;
          
          // Hold line at high
          txd <= 1;
        end
      end
      else
      begin
        // Figure out what the bit is that we will send
        if (state == 1)
        begin
          debug <= debug | 8;
          
          // Start bit is 0
          txd <= 0;
        end
        else if (state == 10)
        begin
          debug <= debug | 16;

          // Stop bit is 1
          txd <= 1;
        end
        else
        begin
          debug <= debug | 32;
        
          // Pull the bit from the data
          txd <= data[state - 2];
        end

        if (counter == 434)
        begin
          // Move to next state if we have one
          if (state == 10)
          begin
            debug <= debug | 64;

            state <= 0;
            ready <= 1'b1;
          end
          else
          begin
            debug <= debug | 128;

            state <= state + 1;
          end
          
          // Reset the counter
          counter <= 0;
        end
        else
        begin
          // Keep waiting
          counter <= counter + 1;
        end
      end
    end
  end
  
endmodule