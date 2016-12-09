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
        MulAdd = 13,
        Inc = 14,
        Dec = 15,
        Fadd = 16,
        Fsub = 17,
        Fconv = 18,
        Fmul = 19,
        Fdiv = 20,
        Fmuladd = 21,
        Fmin = 22,
        Fmax = 23,
        Vfadd = 24,
        Dout = 25,
        Stall = 26,
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
        MulAddRRC = 21,
        IncR = 22,
        DecR = 23,
        FaddRRR = 24,
        FsubRR = 25,
        FconvR = 26,
        FmulRR = 27,
        FdivRR = 28,
        FmuladdRRR = 29,
        FminRR = 30,
        FmaxRR = 31,
        VfaddRRR = 32,
        DoutR = 33,
        Stall = 34,
    };
}
bool Is8ByteOpcode(OpCodes::Enum opCodeParam);
bool IsRAMOpcode(OpCodes::Enum opCodeParam);
