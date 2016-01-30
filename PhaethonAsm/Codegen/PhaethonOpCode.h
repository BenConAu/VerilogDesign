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
        Jnz,
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
        MovRC = 1,
        MovRcA = 2,
        MovRR = 3,
        MovcAR = 4,
        MovRrAC = 5,
        MovrACR = 6,
        MovRrA = 7,
        PushR = 8,
        PopR = 9,
        CmpRR = 10,
        CmpRC = 11,
        JmpC = 12,
        JneC = 13,
        JnzC = 14,
        CallR = 15,
        Ret = 16,
        AddRC = 17,
        MulAddRRC = 18,
        IncR = 19,
        DecR = 20,
        FaddRR = 21,
        FsubRR = 22,
        FconvR = 23,
        FmulRR = 24,
        FmuladdRRR = 25,
        FminRR = 26,
        FmaxRR = 27,
        VfaddRR = 28,
        DoutR = 29,
    };
}
