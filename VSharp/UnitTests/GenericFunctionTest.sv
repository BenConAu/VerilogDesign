module GenericFunctionTest(
  );
  // State definitions
  `define __initial 0
  // inputs / outputs
  input wire reset;
  reg clk = 0; always #5 clk = !clk;
  reg[31:0] HandyNum = 32'd2748;
  reg[31:0] CLZ_Handy;
  initial
  begin
    # 100 $finish;
  end
  reg [7:0] fsmState = 0;
  always @(posedge clk)
  begin
    case(fsmState)
      `__initial: begin
        $monitor("TestVal = %h", CLZ_Handy);
        if (HandyNum[31:16] == 32'd0)
        begin
          if (HandyNum[15:8] == 32'd0)
          begin
            if (HandyNum[7:4] == 32'd0)
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= 32'd31;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd32;
                  end
                end
                else
                begin
                  if (HandyNum[1:1])
                  begin
                    CLZ_Handy <= 32'd30;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd31;
                  end
                end
              end
              else
              begin
                if (HandyNum[3:3] == 32'd0)
                begin
                  if (HandyNum[2:2])
                  begin
                    CLZ_Handy <= 32'd29;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd30;
                  end
                end
                else
                begin
                  if (HandyNum[3:3])
                  begin
                    CLZ_Handy <= 32'd28;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd29;
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[7:6] == 32'd0)
              begin
                if (HandyNum[5:5] == 32'd0)
                begin
                  if (HandyNum[4:4])
                  begin
                    CLZ_Handy <= 32'd27;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd28;
                  end
                end
                else
                begin
                  if (HandyNum[5:5])
                  begin
                    CLZ_Handy <= 32'd26;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd27;
                  end
                end
              end
              else
              begin
                if (HandyNum[7:7] == 32'd0)
                begin
                  if (HandyNum[6:6])
                  begin
                    CLZ_Handy <= 32'd25;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd26;
                  end
                end
                else
                begin
                  if (HandyNum[7:7])
                  begin
                    CLZ_Handy <= 32'd24;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd25;
                  end
                end
              end
            end
          end
          else
          begin
            if (HandyNum[15:12] == 32'd0)
            begin
              if (HandyNum[11:10] == 32'd0)
              begin
                if (HandyNum[9:9] == 32'd0)
                begin
                  if (HandyNum[8:8])
                  begin
                    CLZ_Handy <= 32'd23;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd24;
                  end
                end
                else
                begin
                  if (HandyNum[9:9])
                  begin
                    CLZ_Handy <= 32'd22;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd23;
                  end
                end
              end
              else
              begin
                if (HandyNum[11:11] == 32'd0)
                begin
                  if (HandyNum[10:10])
                  begin
                    CLZ_Handy <= 32'd21;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd22;
                  end
                end
                else
                begin
                  if (HandyNum[11:11])
                  begin
                    CLZ_Handy <= 32'd20;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd21;
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[15:14] == 32'd0)
              begin
                if (HandyNum[13:13] == 32'd0)
                begin
                  if (HandyNum[12:12])
                  begin
                    CLZ_Handy <= 32'd19;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd20;
                  end
                end
                else
                begin
                  if (HandyNum[13:13])
                  begin
                    CLZ_Handy <= 32'd18;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd19;
                  end
                end
              end
              else
              begin
                if (HandyNum[15:15] == 32'd0)
                begin
                  if (HandyNum[14:14])
                  begin
                    CLZ_Handy <= 32'd17;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd18;
                  end
                end
                else
                begin
                  if (HandyNum[15:15])
                  begin
                    CLZ_Handy <= 32'd16;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd17;
                  end
                end
              end
            end
          end
        end
        else
        begin
          if (HandyNum[31:24] == 32'd0)
          begin
            if (HandyNum[23:20] == 32'd0)
            begin
              if (HandyNum[19:18] == 32'd0)
              begin
                if (HandyNum[17:17] == 32'd0)
                begin
                  if (HandyNum[16:16])
                  begin
                    CLZ_Handy <= 32'd15;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd16;
                  end
                end
                else
                begin
                  if (HandyNum[17:17])
                  begin
                    CLZ_Handy <= 32'd14;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd15;
                  end
                end
              end
              else
              begin
                if (HandyNum[19:19] == 32'd0)
                begin
                  if (HandyNum[18:18])
                  begin
                    CLZ_Handy <= 32'd13;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd14;
                  end
                end
                else
                begin
                  if (HandyNum[19:19])
                  begin
                    CLZ_Handy <= 32'd12;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd13;
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[23:22] == 32'd0)
              begin
                if (HandyNum[21:21] == 32'd0)
                begin
                  if (HandyNum[20:20])
                  begin
                    CLZ_Handy <= 32'd11;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd12;
                  end
                end
                else
                begin
                  if (HandyNum[21:21])
                  begin
                    CLZ_Handy <= 32'd10;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd11;
                  end
                end
              end
              else
              begin
                if (HandyNum[23:23] == 32'd0)
                begin
                  if (HandyNum[22:22])
                  begin
                    CLZ_Handy <= 32'd9;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd10;
                  end
                end
                else
                begin
                  if (HandyNum[23:23])
                  begin
                    CLZ_Handy <= 32'd8;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd9;
                  end
                end
              end
            end
          end
          else
          begin
            if (HandyNum[31:28] == 32'd0)
            begin
              if (HandyNum[27:26] == 32'd0)
              begin
                if (HandyNum[25:25] == 32'd0)
                begin
                  if (HandyNum[24:24])
                  begin
                    CLZ_Handy <= 32'd7;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd8;
                  end
                end
                else
                begin
                  if (HandyNum[25:25])
                  begin
                    CLZ_Handy <= 32'd6;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd7;
                  end
                end
              end
              else
              begin
                if (HandyNum[27:27] == 32'd0)
                begin
                  if (HandyNum[26:26])
                  begin
                    CLZ_Handy <= 32'd5;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd6;
                  end
                end
                else
                begin
                  if (HandyNum[27:27])
                  begin
                    CLZ_Handy <= 32'd4;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd5;
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[31:30] == 32'd0)
              begin
                if (HandyNum[29:29] == 32'd0)
                begin
                  if (HandyNum[28:28])
                  begin
                    CLZ_Handy <= 32'd3;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd4;
                  end
                end
                else
                begin
                  if (HandyNum[29:29])
                  begin
                    CLZ_Handy <= 32'd2;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd3;
                  end
                end
              end
              else
              begin
                if (HandyNum[31:31] == 32'd0)
                begin
                  if (HandyNum[30:30])
                  begin
                    CLZ_Handy <= 32'd1;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd2;
                  end
                end
                else
                begin
                  if (HandyNum[31:31])
                  begin
                    CLZ_Handy <= 32'd0;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd1;
                  end
                end
              end
            end
          end
        end
        HandyNum <= HandyNum << 32'd3;
      end
    endcase
  end
endmodule
