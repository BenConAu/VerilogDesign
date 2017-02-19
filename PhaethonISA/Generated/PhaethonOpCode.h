#pragma once

namespace Instructions
{
    enum Enum
    {
        Unknown = 0,
        Mov = 1,
        Pack = 2,
        Push = 3,
        Pop = 4,
        Cmp = 5,
        CmpE = 6,
        CmpNe = 7,
        CmpLt = 8,
        CmpGt = 9,
        Jmp = 10,
        Jne = 11,
        Je = 12,
        Jz = 13,
        Jnz = 14,
        Call = 15,
        Ret = 16,
        RCall = 17,
        RRet = 18,
        Add = 19,
        Sub = 20,
        MulAdd = 21,
        Inc = 22,
        Dec = 23,
        Shl = 24,
        Shr = 25,
        Neg = 26,
        Fadd = 27,
        Fsub = 28,
        Fconv = 29,
        Fmul = 30,
        Fdiv = 31,
        Fmuladd = 32,
        Fmin = 33,
        Fmax = 34,
        Vfadd = 35,
        Dout = 36,
        Din = 37,
        Dlen = 38,
        ReadPort = 39,
        WritePort = 40,
        Stall = 41,
        Exec = 42,
        Exit = 43,
    };
}
enum class OpCode
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
    Stall = 52,
    ExecR = 53,
    Exit = 54,
};
bool Is8ByteOpcode(OpCode opCodeParam);
bool IsRAMOpcode(OpCode opCodeParam);
