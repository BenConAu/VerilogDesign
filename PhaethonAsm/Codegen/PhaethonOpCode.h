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
        AddRR = 19,
        MulAddRRC = 20,
        IncR = 21,
        DecR = 22,
        FaddRR = 23,
        FsubRR = 24,
        FconvR = 25,
        FmulRR = 26,
        FdivRR = 27,
        FmuladdRRR = 28,
        FminRR = 29,
        FmaxRR = 30,
        VfaddRR = 31,
        DoutR = 32,
    };
}
bool Is8ByteOpcode(OpCodes::Enum opCodeParam);
bool IsRAMOpcode(OpCodes::Enum opCodeParam);
