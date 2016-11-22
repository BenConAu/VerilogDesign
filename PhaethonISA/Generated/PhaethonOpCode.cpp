#include "../InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRR          , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "MovRR" },
    { Instructions::Mov       , OpCodes::MovRC          , { ISAOperand::Register()            , ISAOperand::Constant()            , ISAOperand::None()       }, 1, "MovRC" },
    { Instructions::Mov       , OpCodes::MovRdR         , { ISAOperand::Register()            , ISAOperand::DerefRegister()       , ISAOperand::None()       }, -1, "MovRdR" },
    { Instructions::Mov       , OpCodes::MovRdRo        , { ISAOperand::Register()            , ISAOperand::DerefRegisterOffset() , ISAOperand::None()       }, 1, "MovRdRo" },
    { Instructions::Mov       , OpCodes::MovRdC         , { ISAOperand::Register()            , ISAOperand::DerefConstant()       , ISAOperand::None()       }, 1, "MovRdC" },
    { Instructions::Mov       , OpCodes::MovdCR         , { ISAOperand::DerefConstant()       , ISAOperand::Register()            , ISAOperand::None()       }, 0, "MovdCR" },
    { Instructions::Mov       , OpCodes::MovdRoR        , { ISAOperand::DerefRegisterOffset() , ISAOperand::Register()            , ISAOperand::None()       }, 0, "MovdRoR" },
    { Instructions::Push      , OpCodes::PushR          , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "PushR" },
    { Instructions::Pop       , OpCodes::PopR           , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "PopR" },
    { Instructions::Cmp       , OpCodes::CmpRR          , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "CmpRR" },
    { Instructions::Cmp       , OpCodes::CmpRC          , { ISAOperand::Register()            , ISAOperand::Constant()            , ISAOperand::None()       }, 1, "CmpRC" },
    { Instructions::Jmp       , OpCodes::JmpC           , { ISAOperand::Constant()            , ISAOperand::None()                , ISAOperand::None()       }, 0, "JmpC" },
    { Instructions::Jne       , OpCodes::JneC           , { ISAOperand::Constant()            , ISAOperand::None()                , ISAOperand::None()       }, 0, "JneC" },
    { Instructions::Je        , OpCodes::JeC            , { ISAOperand::Constant()            , ISAOperand::None()                , ISAOperand::None()       }, 0, "JeC" },
    { Instructions::Call      , OpCodes::CallR          , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "CallR" },
    { Instructions::Ret       , OpCodes::Ret            , { ISAOperand::None()                , ISAOperand::None()                , ISAOperand::None()       }, -1, "Ret" },
    { Instructions::RCall     , OpCodes::RCallRC        , { ISAOperand::Register()            , ISAOperand::Constant()            , ISAOperand::None()       }, 1, "RCallRC" },
    { Instructions::RRet      , OpCodes::RRet           , { ISAOperand::None()                , ISAOperand::None()                , ISAOperand::None()       }, -1, "RRet" },
    { Instructions::Add       , OpCodes::AddRC          , { ISAOperand::Register()            , ISAOperand::Constant()            , ISAOperand::None()       }, 1, "AddRC" },
    { Instructions::Add       , OpCodes::AddRR          , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "AddRR" },
    { Instructions::MulAdd    , OpCodes::MulAddRRC      , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::Constant()   }, 2, "MulAddRRC" },
    { Instructions::Inc       , OpCodes::IncR           , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "IncR" },
    { Instructions::Dec       , OpCodes::DecR           , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "DecR" },
    { Instructions::Fadd      , OpCodes::FaddRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FaddRR" },
    { Instructions::Fsub      , OpCodes::FsubRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FsubRR" },
    { Instructions::Fconv     , OpCodes::FconvR         , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "FconvR" },
    { Instructions::Fmul      , OpCodes::FmulRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FmulRR" },
    { Instructions::Fdiv      , OpCodes::FdivRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FdivRR" },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::Register()   }, -1, "FmuladdRRR" },
    { Instructions::Fmin      , OpCodes::FminRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FminRR" },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "FmaxRR" },
    { Instructions::Vfadd     , OpCodes::VfaddRR        , { ISAOperand::Register()            , ISAOperand::Register()            , ISAOperand::None()       }, -1, "VfaddRR" },
    { Instructions::Dout      , OpCodes::DoutR          , { ISAOperand::Register()            , ISAOperand::None()                , ISAOperand::None()       }, -1, "DoutR" },
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

