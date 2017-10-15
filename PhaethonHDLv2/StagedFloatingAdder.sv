module FloatingAdd(
  clk,
  OutValue,
  inputA,
  inputB,
  negate
  );
  // inputs / outputs
  input wire reset;
  input wire[0:0] clk;
  output reg[31:0] OutValue;
  input wire[31:0] inputA;
  input wire[31:0] inputB;
  input wire[0:0] negate;
  reg[31:0] a;
  reg[31:0] b;
  reg[39:0] UnpackedA;
  reg[39:0] UnpackedB;
  reg[31:0] TotalMantissa;
  reg[31:0] SignedMantissa;
  reg[0:0] Sign;
  reg[31:0] LeadingZeroCount;
  reg[31:0] PackedResult;
  always @(posedge clk)
  begin
    a = { inputA[31:31], inputA[30:23], inputA[22:0] };
    b = { inputB[31:31], inputB[30:23], inputB[22:0] };
    if (a[30:23] < b[30:23])
    begin
      if ((a[31:31] ^ 1'b0))
      begin
        UnpackedA = { 32'd1 + { 9'd1, a[22:0] }, a[30:23] };
      end
      else
      begin
        UnpackedA = { { 9'd1, a[22:0] }, a[30:23] };
      end
      if ((b[31:31] ^ negate))
      begin
        UnpackedB = { 32'd1 + { 9'd1, b[22:0] }, b[30:23] };
      end
      else
      begin
        UnpackedB = { { 9'd1, b[22:0] }, b[30:23] };
      end
    end
    else
    begin
      if ((b[31:31] ^ negate))
      begin
        UnpackedA = { 32'd1 + { 9'd1, b[22:0] }, b[30:23] };
      end
      else
      begin
        UnpackedA = { { 9'd1, b[22:0] }, b[30:23] };
      end
      if ((a[31:31] ^ 1'b0))
      begin
        UnpackedB = { 32'd1 + { 9'd1, a[22:0] }, a[30:23] };
      end
      else
      begin
        UnpackedB = { { 9'd1, a[22:0] }, a[30:23] };
      end
    end
    if (UnpackedA[39:39])
    begin
      TotalMantissa = ((32'd4294967295 << (32'd32 - UnpackedB[7:0] - UnpackedA[7:0])) | (UnpackedA[39:8] >> UnpackedB[7:0] - UnpackedA[7:0])) + UnpackedB[39:8];
    end
    else
    begin
      TotalMantissa = (32'd0 | (UnpackedA[39:8] >> UnpackedB[7:0] - UnpackedA[7:0])) + UnpackedB[39:8];
    end
    if (TotalMantissa[31:31])
    begin
      Sign = 1'b1;
      SignedMantissa = (TotalMantissa) + 32'd1;
    end
    else
    begin
      Sign = 1'b0;
      SignedMantissa = TotalMantissa;
    end
    if (SignedMantissa[31:16] == 32'd0)
    begin
      if (SignedMantissa[15:8] == 32'd0)
      begin
        if (SignedMantissa[7:4] == 32'd0)
        begin
          case (SignedMantissa[3:0])
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
          case (SignedMantissa[7:4])
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
        if (SignedMantissa[15:12] == 32'd0)
        begin
          case (SignedMantissa[11:8])
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
          case (SignedMantissa[15:12])
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
      if (SignedMantissa[31:24] == 32'd0)
      begin
        if (SignedMantissa[23:20] == 32'd0)
        begin
          case (SignedMantissa[19:16])
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
          case (SignedMantissa[23:20])
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
        if (SignedMantissa[31:28] == 32'd0)
        begin
          case (SignedMantissa[27:24])
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
          case (SignedMantissa[31:28])
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
    PackedResult[31:31] = Sign;
    if (LeadingZeroCount > 32'd8)
    begin
      PackedResult[22:0] = SignedMantissa << (LeadingZeroCount - 32'd8);
    end
    else
    begin
      PackedResult[22:0] = SignedMantissa >> (32'd8 - LeadingZeroCount);
    end
    PackedResult[30:23] = UnpackedB[7:0] + (32'd8 - LeadingZeroCount);
    OutValue = { PackedResult[31:31], PackedResult[30:23], PackedResult[22:0] };
  end
endmodule
