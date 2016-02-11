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
        Je,
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
        JeC = 14,
        CallR = 15,
        Ret = 16,
        RCallRC = 17,
        RRet = 18,
        AddRC = 19,
        AddRR = 20,
        MulAddRRC = 21,
        IncR = 22,
        DecR = 23,
        FaddRR = 24,
        FsubRR = 25,
        FconvR = 26,
        FmulRR = 27,
        FdivRR = 28,
        FmuladdRRR = 29,
        FminRR = 30,
        FmaxRR = 31,
        VfaddRR = 32,
        DoutR = 33,
    };
}
bool Is8ByteOpcode(OpCodes::Enum opCodeParam);
bool IsRAMOpcode(OpCodes::Enum opCodeParam);
