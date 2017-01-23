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

  reg [7:0] firstPos;
  reg [7:0] lastPos;
  reg [7:0] dataBuffer[0:255];

  initial
     $monitor("At time %t, reset = %h, dataWriteEnable = %h, dataWrite = %h, firstPos = %h, lastPos = %h, dataBuffer[0] = %h",
              $time, reset, dataWriteEnable, dataWrite, firstPos, lastPos, dataBuffer[0]);

  always @(posedge clk or posedge reset)
  begin
    if (reset == 1)
    begin
      firstPos <= 0;
      lastPos <= 0;
    end
    else
    begin
      if (dataWriteEnable == 1)
      begin
        // Write is going into buffer
        if (lastPos > firstPos && lastPos - firstPos + 1 == 255 ||
            lastPos < firstPos && firstPos - lastPos == 1)
        begin
          // Buffer is full, so the data is dropped
        end
        else
        begin
          //$display("Buffer not full");

          if (firstPos == lastPos)
          begin
            $display("Writing to first pos");

            dataBuffer[lastPos] <= dataWrite;
          end
          else
          begin
            dataBuffer[lastPos + 1] <= dataWrite;
          end

          lastPos <= lastPos + 1;
        end

        // If we have a request to read, fail it
        if (dataReadEnable == 1)
        begin
          dataReadAck <= 0;
        end
      end
      else if (dataReadEnable == 1)
      begin
        if (firstPos == lastPos)
        begin
          // No data in buffer
          dataReadAck <= 0;
        end
        else
        begin
          // Acknowledge read and return data, advance position
          dataReadAck <= 1;
          dataRead <= dataBuffer[firstPos];
          firstPos <= firstPos + 1;
        end
      end
    end
  end
  
endmodule