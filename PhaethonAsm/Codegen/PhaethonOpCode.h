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
        DecR = 13,
        FaddRR = 14,
        FsubRR = 15,
        FconvR = 16,
        FmulRR = 17,
        FmuladdRRR = 18,
        FminRRR = 19,
        FmaxRRR = 20,
        DoutR = 21,
    };
}
