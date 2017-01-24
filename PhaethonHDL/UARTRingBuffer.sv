module UARTRingBuffer(
  clk,              // Global clock
  reset,            // Reset
  dataWriteEnable,  // Flag to indicate request to write
  dataWrite,        // Data to write
  dataReadEnable,   // Flag to indicate request to read
  dataReadAck,      // Flag to indicate read success
  dataRead          // Actual data read
  );

  input wire clk;
  input wire reset;
  input wire dataWriteEnable;
  input wire[7:0] dataWrite;
  input wire dataReadEnable;
  output reg dataReadAck;
  output reg[7:0] dataRead;

  reg [1:0] firstPos;
  reg [1:0] lastPos;
  reg hasData;
  reg [7:0] dataBuffer[0:3];

  initial
     $monitor("At time %t, reset = %h, dWE = %h, dataWrite = %h, dRE = %h, dRAck = %h, dataRead = %h, firstPos = %h, lastPos = %h, hasData = %h, db[0] = %h:%h:%h:%h",
              $time, reset, dataWriteEnable, dataWrite, dataReadEnable, dataReadAck, dataRead, firstPos, lastPos, hasData,
              dataBuffer[0], dataBuffer[1], dataBuffer[2], dataBuffer[3]);

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      hasData <= 0;
    end
    else
    begin
      if (dataWriteEnable == 1)
      begin
        
        // Write is going into buffer
        if (hasData == 1 && 
            (lastPos > firstPos && lastPos - firstPos == 3 ||
            lastPos < firstPos && firstPos - lastPos == 1))
        begin
          // Buffer is full, so the data is dropped
          $display("Buffer full, cannot write");
        end
        else
        begin
          if (hasData == 0)
          begin
            dataBuffer[0] <= dataWrite;
            firstPos <= 0;
            lastPos <= 0;
            hasData <= 1;
          end
          else
          begin
            dataBuffer[(lastPos + 1) & 2'b11] <= dataWrite;
            lastPos <= lastPos + 1;
          end
        end

        // If we have a request to read, or if the flag was set, clear it out
        dataReadAck <= 0;
      end
      else if (dataReadEnable == 1)
      begin
        if (hasData == 0)
        begin
          $display("Buffer empty, cannot read");

          // No data in buffer
          dataReadAck <= 0;
        end
        else
        begin
          // Acknowledge read and return data, advance position
          dataReadAck <= 1;
          dataRead <= dataBuffer[firstPos];
          firstPos <= firstPos + 1;
          dataBuffer[firstPos] <= 'hFF;

          // Set empty if this was the last thing
          if (firstPos == lastPos)
          begin
            $display("Setting to empty");
            hasData <= 0;
          end
        end
      end
    end
  end
  
endmodule