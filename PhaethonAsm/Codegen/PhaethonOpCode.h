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
        AddRC = 14,
        IncR = 15,
        DecR = 16,
        FaddRR = 17,
        FsubRR = 18,
        FconvR = 19,
        FmulRR = 20,
        FmuladdRRR = 21,
        FminRR = 22,
        FmaxRR = 23,
        DoutR = 24,
    };
}
