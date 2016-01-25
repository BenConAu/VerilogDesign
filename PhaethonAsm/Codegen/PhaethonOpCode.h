#pragma once

namespace Instructions
{
    enum Enum
    {
        Unknown,
        Mov,
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
        CmpRR = 8,
        CmpRC = 9,
        JmpC = 10,
        JneC = 11,
        AddRC = 12,
        IncR = 13,
        DecR = 14,
        FaddRR = 15,
        FsubRR = 16,
        FconvR = 17,
        FmulRR = 18,
        FmuladdRRR = 19,
        FminRR = 20,
        FmaxRR = 21,
        DoutR = 22,
    };
}
