#pragma once

namespace Instructions
{
    enum Enum
    {
        Unknown = 0,
        Mov = 1,
        Push = 2,
        Pop = 3,
        Cmp = 4,
        Jmp = 5,
        Jne = 6,
        Je = 7,
        Call = 8,
        Ret = 9,
        RCall = 10,
        RRet = 11,
        Add = 12,
        Sub = 13,
        MulAdd = 14,
        Inc = 15,
        Dec = 16,
        Fadd = 17,
        Fsub = 18,
        Fconv = 19,
        Fmul = 20,
        Fdiv = 21,
        Fmuladd = 22,
        Fmin = 23,
        Fmax = 24,
        Vfadd = 25,
        Dout = 26,
        Stall = 27,
    };
}
namespace OpCodes
{
    enum Enum
    {
        Unknown = 0,
        MovRR = 1,
        MovRC = 2,
        MovRdR = 3,
        MovRdRo = 4,
        MovRdC = 5,
        MovdCR = 6,
        MovdRoR = 7,
        PushR = 8,
        PopR = 9,
        CmpRR = 10,
        CmpRC = 11,
        JmpC = 12,
        JneC = 13,
        JeC = 14,
        CallR = 15,
        Ret = 16,
        RCallRC = 17,
        RRet = 18,
        AddRRC = 19,
        AddRRR = 20,
        SubRRC = 21,
        SubRRR = 22,
        MulAddRRC = 23,
        IncR = 24,
        DecR = 25,
        FaddRRR = 26,
        FsubRR = 27,
        FconvR = 28,
        FmulRRR = 29,
        FdivRR = 30,
        FmuladdRRR = 31,
        FminRR = 32,
        FmaxRR = 33,
        VfaddRRR = 34,
        DoutR = 35,
        Stall = 36,
    };
}
bool Is8ByteOpcode(OpCodes::Enum opCodeParam);
bool IsRAMOpcode(OpCodes::Enum opCodeParam);
