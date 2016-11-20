#include "../PhaethonASM/InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRR          , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "MovRR" },
    { Instructions::Mov       , OpCodes::MovRC          , { Operand::Register()            , Operand::Constant()            , Operand::None()       }, 1, "MovRC" },
    { Instructions::Mov       , OpCodes::MovRdR         , { Operand::Register()            , Operand::DerefRegister()       , Operand::None()       }, -1, "MovRdR" },
    { Instructions::Mov       , OpCodes::MovRdRo        , { Operand::Register()            , Operand::DerefRegisterOffset() , Operand::None()       }, 1, "MovRdRo" },
    { Instructions::Mov       , OpCodes::MovRdC         , { Operand::Register()            , Operand::DerefConstant()       , Operand::None()       }, 1, "MovRdC" },
    { Instructions::Mov       , OpCodes::MovdCR         , { Operand::DerefConstant()       , Operand::Register()            , Operand::None()       }, 0, "MovdCR" },
    { Instructions::Mov       , OpCodes::MovdRoR        , { Operand::DerefRegisterOffset() , Operand::Register()            , Operand::None()       }, 0, "MovdRoR" },
    { Instructions::Push      , OpCodes::PushR          , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "PushR" },
    { Instructions::Pop       , OpCodes::PopR           , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "PopR" },
    { Instructions::Cmp       , OpCodes::CmpRR          , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "CmpRR" },
    { Instructions::Cmp       , OpCodes::CmpRC          , { Operand::Register()            , Operand::Constant()            , Operand::None()       }, 1, "CmpRC" },
    { Instructions::Jmp       , OpCodes::JmpC           , { Operand::Constant()            , Operand::None()                , Operand::None()       }, 0, "JmpC" },
    { Instructions::Jne       , OpCodes::JneC           , { Operand::Constant()            , Operand::None()                , Operand::None()       }, 0, "JneC" },
    { Instructions::Je        , OpCodes::JeC            , { Operand::Constant()            , Operand::None()                , Operand::None()       }, 0, "JeC" },
    { Instructions::Call      , OpCodes::CallR          , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "CallR" },
    { Instructions::Ret       , OpCodes::Ret            , { Operand::None()                , Operand::None()                , Operand::None()       }, -1, "Ret" },
    { Instructions::RCall     , OpCodes::RCallRC        , { Operand::Register()            , Operand::Constant()            , Operand::None()       }, 1, "RCallRC" },
    { Instructions::RRet      , OpCodes::RRet           , { Operand::None()                , Operand::None()                , Operand::None()       }, -1, "RRet" },
    { Instructions::Add       , OpCodes::AddRC          , { Operand::Register()            , Operand::Constant()            , Operand::None()       }, 1, "AddRC" },
    { Instructions::Add       , OpCodes::AddRR          , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "AddRR" },
    { Instructions::MulAdd    , OpCodes::MulAddRRC      , { Operand::Register()            , Operand::Register()            , Operand::Constant()   }, 2, "MulAddRRC" },
    { Instructions::Inc       , OpCodes::IncR           , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "IncR" },
    { Instructions::Dec       , OpCodes::DecR           , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "DecR" },
    { Instructions::Fadd      , OpCodes::FaddRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FaddRR" },
    { Instructions::Fsub      , OpCodes::FsubRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FsubRR" },
    { Instructions::Fconv     , OpCodes::FconvR         , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "FconvR" },
    { Instructions::Fmul      , OpCodes::FmulRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FmulRR" },
    { Instructions::Fdiv      , OpCodes::FdivRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FdivRR" },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { Operand::Register()            , Operand::Register()            , Operand::Register()   }, -1, "FmuladdRRR" },
    { Instructions::Fmin      , OpCodes::FminRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FminRR" },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "FmaxRR" },
    { Instructions::Vfadd     , OpCodes::VfaddRR        , { Operand::Register()            , Operand::Register()            , Operand::None()       }, -1, "VfaddRR" },
    { Instructions::Dout      , OpCodes::DoutR          , { Operand::Register()            , Operand::None()                , Operand::None()       }, -1, "DoutR" },
};

int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);

bool Is8ByteOpcode(OpCodes::Enum opCodeParam)
{
    if (opCodeParam == OpCodes::MovRC ||
        opCodeParam == OpCodes::MovRdRo ||
        opCodeParam == OpCodes::MovRdC ||
        opCodeParam == OpCodes::MovdCR ||
        opCodeParam == OpCodes::MovdRoR ||
        opCodeParam == OpCodes::CmpRC ||
        opCodeParam == OpCodes::JmpC ||
        opCodeParam == OpCodes::JneC ||
        opCodeParam == OpCodes::JeC ||
        opCodeParam == OpCodes::RCallRC ||
        opCodeParam == OpCodes::AddRC ||
        opCodeParam == OpCodes::MulAddRRC)
        return true;
    else
        return false;
}

bool IsRAMOpcode(OpCodes::Enum opCodeParam)
{
    if (opCodeParam == OpCodes::MovRdR ||
        opCodeParam == OpCodes::MovRdRo ||
        opCodeParam == OpCodes::MovRdC ||
        opCodeParam == OpCodes::MovdCR ||
        opCodeParam == OpCodes::MovdRoR ||
        opCodeParam == OpCodes::PushR ||
        opCodeParam == OpCodes::PopR ||
        opCodeParam == OpCodes::CallR ||
        opCodeParam == OpCodes::Ret)
        return true;
    else
        return false;
}

