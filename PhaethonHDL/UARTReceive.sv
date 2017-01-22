module UARTReceive(
  clk, 
  reset,
  rxd,
  dataComplete,
  zeroBits,
  oneBits
  );

  output reg dataComplete;
  output reg[31:0] zeroBits;
  output reg[31:0] oneBits;
  input wire clk;
  input wire reset;
  input wire rxd;

  reg [7:0] state;
  reg [7:0] counter;

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      state <= 0;
      dataComplete <= 0;
      //data <= 0;
      counter <= 0;
    end
    else
    begin
/*      if (state == 0)
      begin
        if (counter < 217)
        begin
          if (rxd == 1)
          begin
            // Did not maintain start state for long enough
            counter <= 0;
          end
          else
          begin
            // Keep counting
            counter <= counter + 1;
          end
        end
        else
        begin
          // Look for first bit
          state <= 1;
          counter <= 0;
        end
      end
      else if (state == 9)
      begin
        if (rxd == 1)
        begin
          // Valid stop bit
          dataComplete <= 1;
        end

        state <= 0;
      end
      else
      begin
        // Look for next bit
        if (counter < 434)
        begin
          counter <= counter + 1;
        end
        else
        begin
          counter <= 0;
          data[state - 1] <= rxd;
          state <= state + 1;
        end
      end
    end*/
	 
	   if (rxd == 1)
	   begin
		  if (state == 0)
		  begin
  		    state <= 1;
	       oneBits <= oneBits + 1;
		  end
	   end
		else
		begin
		  if (state == 1)
		  begin
   	    state <= 0;
	       zeroBits <= zeroBits + 1;
		  end
		end
	 end
  end
  
endmodule