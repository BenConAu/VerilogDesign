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
        Inc,
        Dec,
        Fadd,
        Fsub,
        Fconv,
        Fmul,
        Fmuladd,
        Fmin,
        Fmax,
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
        CallR = 14,
        Ret = 15,
        AddRC = 16,
        IncR = 17,
        DecR = 18,
        FaddRR = 19,
        FsubRR = 20,
        FconvR = 21,
        FmulRR = 22,
        FmuladdRRR = 23,
        FminRR = 24,
        FmaxRR = 25,
        DoutR = 26,
    };
}
