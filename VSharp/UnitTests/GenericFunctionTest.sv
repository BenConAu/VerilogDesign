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
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd2 + (32'd2)))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd2 + (32'd1)))));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd3))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd2))));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd2))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4 + (32'd1))));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd5)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd4)));
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd2 + (32'd2))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd2 + (32'd1))));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd3)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd2)));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd9));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd8));
                  end
                end
              end
            end
          end
          else
          begin
            if (HandyNum[7:4] == 32'd0)
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd2 + (32'd2))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd2 + (32'd1))));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd3)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd2)));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd5));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd4));
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd2 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd2 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd3));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd2));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd16 + (32'd2));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16 + (32'd1));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd17);
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd16);
                  end
                end
              end
            end
          end
        end
        else
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
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd2 + (32'd2))));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd2 + (32'd1))));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd3)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd2)));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd5));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd4));
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd2 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd2 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd3));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd2));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd8 + (32'd2));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8 + (32'd1));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd9);
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd8);
                  end
                end
              end
            end
          end
          else
          begin
            if (HandyNum[7:4] == 32'd0)
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd4 + (32'd2 + (32'd2)));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd4 + (32'd2 + (32'd1)));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd4 + (32'd3));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd4 + (32'd2));
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd4 + (32'd2));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd4 + (32'd1));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd5);
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd4);
                  end
                end
              end
            end
            else
            begin
              if (HandyNum[3:2] == 32'd0)
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd2 + (32'd2));
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd2 + (32'd1));
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd3);
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd2);
                  end
                end
              end
              else
              begin
                if (HandyNum[1:1] == 32'd0)
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= (32'd2);
                  end
                  else
                  begin
                    CLZ_Handy <= (32'd1);
                  end
                end
                else
                begin
                  if (HandyNum[0:0])
                  begin
                    CLZ_Handy <= 32'd1;
                  end
                  else
                  begin
                    CLZ_Handy <= 32'd0;
                  end
                end
              end
            end
          end
        end
      end
    endcase
  end
endmodule
