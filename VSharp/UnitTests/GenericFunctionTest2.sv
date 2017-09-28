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
              case (HandyNum[3:0])
                4'd0: begin
                  CLZ_Handy <= 32'd32;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd31;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd30;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd30;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd29;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd29;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd29;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd29;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd28;
                end
              endcase
            end
            else
            begin
              case (HandyNum[7:4])
                4'd0: begin
                  CLZ_Handy <= 32'd28;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd27;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd26;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd26;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd25;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd25;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd25;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd25;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd24;
                end
              endcase
            end
          end
          else
          begin
            if (HandyNum[15:12] == 32'd0)
            begin
              case (HandyNum[11:8])
                4'd0: begin
                  CLZ_Handy <= 32'd24;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd23;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd22;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd22;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd21;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd21;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd21;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd21;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd20;
                end
              endcase
            end
            else
            begin
              case (HandyNum[15:12])
                4'd0: begin
                  CLZ_Handy <= 32'd20;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd19;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd18;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd18;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd17;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd17;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd17;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd17;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd16;
                end
              endcase
            end
          end
        end
        else
        begin
          if (HandyNum[31:24] == 32'd0)
          begin
            if (HandyNum[23:20] == 32'd0)
            begin
              case (HandyNum[19:16])
                4'd0: begin
                  CLZ_Handy <= 32'd16;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd15;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd14;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd14;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd13;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd13;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd13;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd13;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd12;
                end
              endcase
            end
            else
            begin
              case (HandyNum[23:20])
                4'd0: begin
                  CLZ_Handy <= 32'd12;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd11;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd10;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd10;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd9;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd9;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd9;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd9;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd8;
                end
              endcase
            end
          end
          else
          begin
            if (HandyNum[31:28] == 32'd0)
            begin
              case (HandyNum[27:24])
                4'd0: begin
                  CLZ_Handy <= 32'd8;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd7;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd6;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd6;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd5;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd5;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd5;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd5;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd4;
                end
              endcase
            end
            else
            begin
              case (HandyNum[31:28])
                4'd0: begin
                  CLZ_Handy <= 32'd4;
                end
                4'd1: begin
                  CLZ_Handy <= 32'd3;
                end
                4'd2: begin
                  CLZ_Handy <= 32'd2;
                end
                4'd3: begin
                  CLZ_Handy <= 32'd2;
                end
                4'd4: begin
                  CLZ_Handy <= 32'd1;
                end
                4'd5: begin
                  CLZ_Handy <= 32'd1;
                end
                4'd6: begin
                  CLZ_Handy <= 32'd1;
                end
                4'd7: begin
                  CLZ_Handy <= 32'd1;
                end
                4'd8: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd9: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd10: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd11: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd12: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd13: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd14: begin
                  CLZ_Handy <= 32'd0;
                end
                4'd15: begin
                  CLZ_Handy <= 32'd0;
                end
              endcase
            end
          end
        end
        HandyNum <= HandyNum << 32'd3;
      end
    endcase
  end
endmodule
