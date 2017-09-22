#import "UARTReceive.vs";

module UARTReceive_TB()
{
    clock clk;
    bool TxD;
    wire bool DataComplete;
    wire uint8 UartData;
    wire uint32 EndCount;
    uint32 ByteStream;

    uint32 Counter;         // Clock counter
    uint32 StreamPosition;  // The position inside the stream
    uint32 BytePosition;    // The position inside the 10 bit UART byte
    uint32 BytesReceived;   // How many bytes we have received

    UARTReceive receiver = UARTReceive(
        clk,                // The CPU clock signal
        TxD,                // UART RxD
        out DataComplete,   // Signal that data is complete
        out UartData,       // Data returned when data is complete
        out EndCount        // Count of start bits seen
    );

	drive
	{
		300000: __finish;
	}    

    state initial
    {
        //__monitor(
            //"%t | BytePos = %h | StreamPos = %h | TxD = %h | UART data = %h", 
            //__time,
            //BytePosition,
            //StreamPosition,
            //TxD,
            //UartData);

        ByteStream = 0xa1b2c3d4;

        Counter = 0;
        StreamPosition = 0;
        BytePosition = 0;
        BytesReceived = 0;

        transition Transmit;
    }

    state Transmit
    {
        if (BytePosition == 0)
        {
            // Start bit
            TxD = false;
        }
        else
        {
            if (BytePosition == 9)
            {
                // Stop bit
                TxD = true;
            }
            else
            {
                // Data bit
                TxD = ByteStream[StreamPosition];
            }
        }

        if (Counter == 434)
        {
            // Reset the counter
            Counter = 0;

            if (BytePosition == 9)
            {
                // Reset the byte position
                BytePosition = 0;
            }
            else
            {
                if (BytePosition != 0)
                {
                    // Move along the stream unless it is a start / stop bit
                    StreamPosition = StreamPosition + 1;
                }

                BytePosition = BytePosition + 1;
            }
        }
        else
        {
            Counter = Counter + 1;
        }

        if (DataComplete)
        {
            __display("DataComplete | Data = %h", UartData);

            if (BytesReceived == 3)
            {
                __display("All bits sent");

                // Stop listening and sending stuff
                transition Done;
            }
            else
            {
                BytesReceived = BytesReceived + 1;
            }
        }
    }

    state Done
    {
    }
}