module UARTReceive(
  clock clk,              // The CPU clock signal
  bool rxd,               // UART RxD
  out bool dataComplete,  // Signal that data is complete
  out uint8 dataOutput,   // Data returned when data is complete
  out uint32 endCount     // Count of start bits seen
  )
{
  uint32 startCount;      // Count of start bits seen
  uint16 BitCount = 0;
  uint16 counter = 0;
  uint8  data = 0;

  state initial
  {
    BitCount = 0u16;
    dataComplete = false;
    data = 0u8;
    counter = 0u16;
    startCount = 0;
    endCount = 0;

    transition Waiting;
  }

  state Waiting
  {
    // Data is no longer complete
    dataComplete = false;

    if (rxd == 1)
    {
      //__display("Start state reset");

      // Did not maintain start state for long enough    
      counter = 0u16;
    }
    else
    {
      if (counter == 217u16)
      {
        //__display("Start bit identified");

        // We have decided this is a start bit
        startCount = startCount + 1;
        counter = 0u16;
        data = 0u8;

        // Start grabbing data bits
        BitCount = 0u16;
        transition Collecting;
      }
      else
      {
        counter = counter + 1u16;
      }
    }
  }

  state Collecting
  {
    if (counter == 434)
    {
      if (BitCount == 8)
      {
        dataOutput = data;
        dataComplete = true;
        endCount = endCount + 1u16;

        // This was the stop bit, go back to start state
        transition Waiting;
      }
      else
      {
        // Add the bit to our data register and look for the next one
        BitCount = BitCount + 1u16;
        data[BitCount] = rxd;   
      }

      // No matter what the counter resets
      counter = 0u16;
    }
    else
    {
      // Keep counting until in middle of next bit
      counter = counter + 1u16;
    }
  }
}