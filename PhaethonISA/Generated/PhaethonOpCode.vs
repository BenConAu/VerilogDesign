enum OpCode
{
    Unknown = 0,
    MovRR = 1,
    MovRC = 2,
    MovRdR = 3,
    MovRdRo = 4,
    MovRdRoR = 5,
    MovRdC = 6,
    MovdCR = 7,
    MovdRoR = 8,
    MovdRoRR = 9,
    PackRRR = 10,
    PushR = 11,
    PopR = 12,
    CmpRR = 13,
    CmpRC = 14,
    CmpERRR = 15,
    CmpNeRRR = 16,
    CmpLtRRR = 17,
    CmpGtRRR = 18,
    JmpC = 19,
    JneC = 20,
    JeC = 21,
    JzRC = 22,
    JnzRC = 23,
    CallR = 24,
    Ret = 25,
    RCallRC = 26,
    RRet = 27,
    AddRRC = 28,
    AddRRR = 29,
    SubRRC = 30,
    SubRRR = 31,
    MulAddRRC = 32,
    IncR = 33,
    DecR = 34,
    ShlRRR = 35,
    ShrRRR = 36,
    NegRR = 37,
    FaddRRR = 38,
    FsubRR = 39,
    FconvR = 40,
    FmulRRR = 41,
    FdivRR = 42,
    FmuladdRRR = 43,
    FminRR = 44,
    FmaxRR = 45,
    VfaddRRR = 46,
    DoutR = 47,
    DinR = 48,
    DlenR = 49,
    ReadPortRR = 50,
    WritePortRR = 51,
    ExecR = 52,
    Exit = 53,
    VpEnable = 54,
    LeaRRoR = 55,
    SysCallRRR = 56,
    MaxOpCode = 56
}

bool Is8ByteOpcode(OpCode opCodeParam)
{
  if (opCodeParam == OpCode.MovRC ||
      opCodeParam == OpCode.MovRdRo ||
      opCodeParam == OpCode.MovRdRoR ||
      opCodeParam == OpCode.MovRdC ||
      opCodeParam == OpCode.MovdCR ||
      opCodeParam == OpCode.MovdRoR ||
      opCodeParam == OpCode.MovdRoRR ||
      opCodeParam == OpCode.CmpRC ||
      opCodeParam == OpCode.JmpC ||
      opCodeParam == OpCode.JneC ||
      opCodeParam == OpCode.JeC ||
      opCodeParam == OpCode.JzRC ||
      opCodeParam == OpCode.JnzRC ||
      opCodeParam == OpCode.RCallRC ||
      opCodeParam == OpCode.AddRRC ||
      opCodeParam == OpCode.SubRRC ||
      opCodeParam == OpCode.MulAddRRC ||
      opCodeParam == OpCode.LeaRRoR)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool IsRAMOpcode(OpCode opCodeParam)
{
  if (opCodeParam == OpCode.MovRdR ||
      opCodeParam == OpCode.MovRdRo ||
      opCodeParam == OpCode.MovRdRoR ||
      opCodeParam == OpCode.MovRdC ||
      opCodeParam == OpCode.MovdCR ||
      opCodeParam == OpCode.MovdRoR ||
      opCodeParam == OpCode.MovdRoRR ||
      opCodeParam == OpCode.PushR ||
      opCodeParam == OpCode.PopR ||
      opCodeParam == OpCode.CallR ||
      opCodeParam == OpCode.Ret ||
      opCodeParam == OpCode.SysCallRRR)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool IsIOOpcode(OpCode opCodeParam)
{
  if (opCodeParam == OpCode.DoutR ||
      opCodeParam == OpCode.DinR ||
      opCodeParam == OpCode.ReadPortRR ||
      opCodeParam == OpCode.WritePortRR)
  {
    return true;
  }
  else
  {
    return false;
  }
}

