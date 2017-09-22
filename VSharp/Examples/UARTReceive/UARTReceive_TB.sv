module UARTReceive_TB(
  );
  // State definitions
  `define __initial 0
  `define __Transmit 1
  `define __Done 2
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  reg[0:0] TxD;
  wire[0:0] DataComplete;
  wire[7:0] UartData;
  wire[31:0] EndCount;
  reg[31:0] ByteStream;
  reg[31:0] Counter;
  reg[31:0] StreamPosition;
  reg[31:0] BytePosition;
  reg[31:0] BytesReceived;
  UARTReceive receiver(clk, TxD, DataComplete, UartData, EndCount);
  initial
  begin
    # 300000 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        ByteStream <= 32'd2712847316;
        Counter <= 32'd0;
        StreamPosition <= 32'd0;
        BytePosition <= 32'd0;
        BytesReceived <= 32'd0;
        fsmState <= `__Transmit;
      end
      `__Transmit: begin
        if (BytePosition == 32'd0)
        begin
          TxD <= 1'b0;
        end
        else
        begin
          if (BytePosition == 32'd9)
          begin
            TxD <= 1'b1;
          end
          else
          begin
            TxD <= ByteStream[StreamPosition];
          end
        end
        if (Counter == 32'd434)
        begin
          Counter <= 32'd0;
          if (BytePosition == 32'd9)
          begin
            BytePosition <= 32'd0;
          end
          else
          begin
            if (BytePosition != 32'd0)
            begin
              StreamPosition <= StreamPosition + 32'd1;
            end
            BytePosition <= BytePosition + 32'd1;
          end
        end
        else
        begin
          Counter <= Counter + 32'd1;
        end
        if (DataComplete)
        begin
          $display("DataComplete | Data = %h", UartData);
          if (BytesReceived == 32'd3)
          begin
            $display("All bits sent");
            fsmState <= `__Done;
          end
          else
          begin
            BytesReceived <= BytesReceived + 32'd1;
          end
        end
      end
      `__Done: begin
      end
    endcase
  end
endmodule
