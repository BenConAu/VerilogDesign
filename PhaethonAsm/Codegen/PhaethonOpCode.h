#pragma once

namespace Instructions
{
    enum Enum
    {
        Unknown,
        Mov,
        Push,
        Pop,
        Cmp,
        Jmp,
        Jne,
        Call,
        Ret,
        RCall,
        RRet,
        Add,
        MulAdd,
        Inc,
        Dec,
        Fadd,
        Fsub,
        Fconv,
        Fmul,
        Fdiv,
        Fmuladd,
        Fmin,
        Fmax,
        Vfadd,
        Dout,
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
        CallR = 14,
        Ret = 15,
        RCallRC = 16,
        RRet = 17,
        AddRC = 18,
        MulAddRRC = 19,
        IncR = 20,
        DecR = 21,
        FaddRR = 22,
        FsubRR = 23,
        FconvR = 24,
        FmulRR = 25,
        FdivRR = 26,
        FmuladdRRR = 27,
        FminRR = 28,
        FmaxRR = 29,
        VfaddRR = 30,
        DoutR = 31,
    };
}
