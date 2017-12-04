module FloatingDivide(
  clk,
  inputA,
  inputB,
  OutValue
  );
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  input wire[31:0] inputA;
  input wire[31:0] inputB;
  output reg[31:0] OutValue;
  reg[31:0] a;
  reg[31:0] b;
  reg[39:0] UnpackedA;
  reg[39:0] UnpackedB;
  reg[0:0] TotalSign;
  reg[63:0] LongMantissa;
  reg[63:0] TotalMantissa;
  reg[31:0] LeadingZeroCount;
  reg[31:0] PackedResult;
  always @(posedge clk)
  begin
    a = { inputA[31:31], inputA[30:23], inputA[22:0] };
    b = { inputB[31:31], inputB[30:23], inputB[22:0] };
    TotalSign = a[31:31] ^ b[31:31];
    if ((a[31:31] ^ a[31:31]))
    begin
      UnpackedA = { 32'd1 + { 9'd1, a[22:0] }, a[30:23] };
    end
    else
    begin
      UnpackedA = { { 9'd1, a[22:0] }, a[30:23] };
    end
    if ((b[31:31] ^ b[31:31]))
    begin
      UnpackedB = { 32'd1 + { 9'd1, b[22:0] }, b[30:23] };
    end
    else
    begin
      UnpackedB = { { 9'd1, b[22:0] }, b[30:23] };
    end
    LongMantissa = { 32'd0, UnpackedA[39:8] };
    TotalMantissa = LongMantissa << 32'd23 / UnpackedB[39:8];
    if (TotalMantissa[31:16] == 32'd0)
    begin
      if (TotalMantissa[15:8] == 32'd0)
      begin
        if (TotalMantissa[7:4] == 32'd0)
        begin
          case (TotalMantissa[3:0])
            4'd0: begin
              LeadingZeroCount = 32'd32;
            end
            4'd1: begin
              LeadingZeroCount = 32'd31;
            end
            4'd2: begin
              LeadingZeroCount = 32'd30;
            end
            4'd3: begin
              LeadingZeroCount = 32'd30;
            end
            4'd4: begin
              LeadingZeroCount = 32'd29;
            end
            4'd5: begin
              LeadingZeroCount = 32'd29;
            end
            4'd6: begin
              LeadingZeroCount = 32'd29;
            end
            4'd7: begin
              LeadingZeroCount = 32'd29;
            end
            4'd8: begin
              LeadingZeroCount = 32'd28;
            end
            4'd9: begin
              LeadingZeroCount = 32'd28;
            end
            4'd10: begin
              LeadingZeroCount = 32'd28;
            end
            4'd11: begin
              LeadingZeroCount = 32'd28;
            end
            4'd12: begin
              LeadingZeroCount = 32'd28;
            end
            4'd13: begin
              LeadingZeroCount = 32'd28;
            end
            4'd14: begin
              LeadingZeroCount = 32'd28;
            end
            4'd15: begin
              LeadingZeroCount = 32'd28;
            end
          endcase
        end
        else
        begin
          case (TotalMantissa[7:4])
            4'd0: begin
              LeadingZeroCount = 32'd28;
            end
            4'd1: begin
              LeadingZeroCount = 32'd27;
            end
            4'd2: begin
              LeadingZeroCount = 32'd26;
            end
            4'd3: begin
              LeadingZeroCount = 32'd26;
            end
            4'd4: begin
              LeadingZeroCount = 32'd25;
            end
            4'd5: begin
              LeadingZeroCount = 32'd25;
            end
            4'd6: begin
              LeadingZeroCount = 32'd25;
            end
            4'd7: begin
              LeadingZeroCount = 32'd25;
            end
            4'd8: begin
              LeadingZeroCount = 32'd24;
            end
            4'd9: begin
              LeadingZeroCount = 32'd24;
            end
            4'd10: begin
              LeadingZeroCount = 32'd24;
            end
            4'd11: begin
              LeadingZeroCount = 32'd24;
            end
            4'd12: begin
              LeadingZeroCount = 32'd24;
            end
            4'd13: begin
              LeadingZeroCount = 32'd24;
            end
            4'd14: begin
              LeadingZeroCount = 32'd24;
            end
            4'd15: begin
              LeadingZeroCount = 32'd24;
            end
          endcase
        end
      end
      else
      begin
        if (TotalMantissa[15:12] == 32'd0)
        begin
          case (TotalMantissa[11:8])
            4'd0: begin
              LeadingZeroCount = 32'd24;
            end
            4'd1: begin
              LeadingZeroCount = 32'd23;
            end
            4'd2: begin
              LeadingZeroCount = 32'd22;
            end
            4'd3: begin
              LeadingZeroCount = 32'd22;
            end
            4'd4: begin
              LeadingZeroCount = 32'd21;
            end
            4'd5: begin
              LeadingZeroCount = 32'd21;
            end
            4'd6: begin
              LeadingZeroCount = 32'd21;
            end
            4'd7: begin
              LeadingZeroCount = 32'd21;
            end
            4'd8: begin
              LeadingZeroCount = 32'd20;
            end
            4'd9: begin
              LeadingZeroCount = 32'd20;
            end
            4'd10: begin
              LeadingZeroCount = 32'd20;
            end
            4'd11: begin
              LeadingZeroCount = 32'd20;
            end
            4'd12: begin
              LeadingZeroCount = 32'd20;
            end
            4'd13: begin
              LeadingZeroCount = 32'd20;
            end
            4'd14: begin
              LeadingZeroCount = 32'd20;
            end
            4'd15: begin
              LeadingZeroCount = 32'd20;
            end
          endcase
        end
        else
        begin
          case (TotalMantissa[15:12])
            4'd0: begin
              LeadingZeroCount = 32'd20;
            end
            4'd1: begin
              LeadingZeroCount = 32'd19;
            end
            4'd2: begin
              LeadingZeroCount = 32'd18;
            end
            4'd3: begin
              LeadingZeroCount = 32'd18;
            end
            4'd4: begin
              LeadingZeroCount = 32'd17;
            end
            4'd5: begin
              LeadingZeroCount = 32'd17;
            end
            4'd6: begin
              LeadingZeroCount = 32'd17;
            end
            4'd7: begin
              LeadingZeroCount = 32'd17;
            end
            4'd8: begin
              LeadingZeroCount = 32'd16;
            end
            4'd9: begin
              LeadingZeroCount = 32'd16;
            end
            4'd10: begin
              LeadingZeroCount = 32'd16;
            end
            4'd11: begin
              LeadingZeroCount = 32'd16;
            end
            4'd12: begin
              LeadingZeroCount = 32'd16;
            end
            4'd13: begin
              LeadingZeroCount = 32'd16;
            end
            4'd14: begin
              LeadingZeroCount = 32'd16;
            end
            4'd15: begin
              LeadingZeroCount = 32'd16;
            end
          endcase
        end
      end
    end
    else
    begin
      if (TotalMantissa[31:24] == 32'd0)
      begin
        if (TotalMantissa[23:20] == 32'd0)
        begin
          case (TotalMantissa[19:16])
            4'd0: begin
              LeadingZeroCount = 32'd16;
            end
            4'd1: begin
              LeadingZeroCount = 32'd15;
            end
            4'd2: begin
              LeadingZeroCount = 32'd14;
            end
            4'd3: begin
              LeadingZeroCount = 32'd14;
            end
            4'd4: begin
              LeadingZeroCount = 32'd13;
            end
            4'd5: begin
              LeadingZeroCount = 32'd13;
            end
            4'd6: begin
              LeadingZeroCount = 32'd13;
            end
            4'd7: begin
              LeadingZeroCount = 32'd13;
            end
            4'd8: begin
              LeadingZeroCount = 32'd12;
            end
            4'd9: begin
              LeadingZeroCount = 32'd12;
            end
            4'd10: begin
              LeadingZeroCount = 32'd12;
            end
            4'd11: begin
              LeadingZeroCount = 32'd12;
            end
            4'd12: begin
              LeadingZeroCount = 32'd12;
            end
            4'd13: begin
              LeadingZeroCount = 32'd12;
            end
            4'd14: begin
              LeadingZeroCount = 32'd12;
            end
            4'd15: begin
              LeadingZeroCount = 32'd12;
            end
          endcase
        end
        else
        begin
          case (TotalMantissa[23:20])
            4'd0: begin
              LeadingZeroCount = 32'd12;
            end
            4'd1: begin
              LeadingZeroCount = 32'd11;
            end
            4'd2: begin
              LeadingZeroCount = 32'd10;
            end
            4'd3: begin
              LeadingZeroCount = 32'd10;
            end
            4'd4: begin
              LeadingZeroCount = 32'd9;
            end
            4'd5: begin
              LeadingZeroCount = 32'd9;
            end
            4'd6: begin
              LeadingZeroCount = 32'd9;
            end
            4'd7: begin
              LeadingZeroCount = 32'd9;
            end
            4'd8: begin
              LeadingZeroCount = 32'd8;
            end
            4'd9: begin
              LeadingZeroCount = 32'd8;
            end
            4'd10: begin
              LeadingZeroCount = 32'd8;
            end
            4'd11: begin
              LeadingZeroCount = 32'd8;
            end
            4'd12: begin
              LeadingZeroCount = 32'd8;
            end
            4'd13: begin
              LeadingZeroCount = 32'd8;
            end
            4'd14: begin
              LeadingZeroCount = 32'd8;
            end
            4'd15: begin
              LeadingZeroCount = 32'd8;
            end
          endcase
        end
      end
      else
      begin
        if (TotalMantissa[31:28] == 32'd0)
        begin
          case (TotalMantissa[27:24])
            4'd0: begin
              LeadingZeroCount = 32'd8;
            end
            4'd1: begin
              LeadingZeroCount = 32'd7;
            end
            4'd2: begin
              LeadingZeroCount = 32'd6;
            end
            4'd3: begin
              LeadingZeroCount = 32'd6;
            end
            4'd4: begin
              LeadingZeroCount = 32'd5;
            end
            4'd5: begin
              LeadingZeroCount = 32'd5;
            end
            4'd6: begin
              LeadingZeroCount = 32'd5;
            end
            4'd7: begin
              LeadingZeroCount = 32'd5;
            end
            4'd8: begin
              LeadingZeroCount = 32'd4;
            end
            4'd9: begin
              LeadingZeroCount = 32'd4;
            end
            4'd10: begin
              LeadingZeroCount = 32'd4;
            end
            4'd11: begin
              LeadingZeroCount = 32'd4;
            end
            4'd12: begin
              LeadingZeroCount = 32'd4;
            end
            4'd13: begin
              LeadingZeroCount = 32'd4;
            end
            4'd14: begin
              LeadingZeroCount = 32'd4;
            end
            4'd15: begin
              LeadingZeroCount = 32'd4;
            end
          endcase
        end
        else
        begin
          case (TotalMantissa[31:28])
            4'd0: begin
              LeadingZeroCount = 32'd4;
            end
            4'd1: begin
              LeadingZeroCount = 32'd3;
            end
            4'd2: begin
              LeadingZeroCount = 32'd2;
            end
            4'd3: begin
              LeadingZeroCount = 32'd2;
            end
            4'd4: begin
              LeadingZeroCount = 32'd1;
            end
            4'd5: begin
              LeadingZeroCount = 32'd1;
            end
            4'd6: begin
              LeadingZeroCount = 32'd1;
            end
            4'd7: begin
              LeadingZeroCount = 32'd1;
            end
            4'd8: begin
              LeadingZeroCount = 32'd0;
            end
            4'd9: begin
              LeadingZeroCount = 32'd0;
            end
            4'd10: begin
              LeadingZeroCount = 32'd0;
            end
            4'd11: begin
              LeadingZeroCount = 32'd0;
            end
            4'd12: begin
              LeadingZeroCount = 32'd0;
            end
            4'd13: begin
              LeadingZeroCount = 32'd0;
            end
            4'd14: begin
              LeadingZeroCount = 32'd0;
            end
            4'd15: begin
              LeadingZeroCount = 32'd0;
            end
          endcase
        end
      end
    end
    PackedResult[31:31] = TotalSign;
    if (LeadingZeroCount > 32'd8)
    begin
      PackedResult[22:0] = TotalMantissa[31:0] << (LeadingZeroCount - 32'd8);
    end
    else
    begin
      PackedResult[22:0] = TotalMantissa[31:0] >> (32'd8 - LeadingZeroCount);
    end
    PackedResult[30:23] = UnpackedA[7:0] - UnpackedB[7:0] + (32'd8 - LeadingZeroCount) + 32'd127;
    OutValue = { PackedResult[31:31], PackedResult[30:23], PackedResult[22:0] };
  end
endmodule
