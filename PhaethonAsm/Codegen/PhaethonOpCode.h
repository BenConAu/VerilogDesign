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
        AddRC = 16,
        MulAddRRC = 17,
        IncR = 18,
        DecR = 19,
        FaddRR = 20,
        FsubRR = 21,
        FconvR = 22,
        FmulRR = 23,
        FdivRR = 24,
        FmuladdRRR = 25,
        FminRR = 26,
        FmaxRR = 27,
        VfaddRR = 28,
        DoutR = 29,
    };
}
