#include "../PhaethonAsm/InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRR          , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "MovRR" },
    { Instructions::Mov       , OpCodes::MovRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1, "MovRC" },
    { Instructions::Mov       , OpCodes::MovRdR         , { ArgumentBase::Register()            , ArgumentBase::DerefRegister()       , ArgumentBase::None()       }, -1, "MovRdR" },
    { Instructions::Mov       , OpCodes::MovRdRo        , { ArgumentBase::Register()            , ArgumentBase::DerefRegisterOffset() , ArgumentBase::None()       }, 1, "MovRdRo" },
    { Instructions::Mov       , OpCodes::MovRdC         , { ArgumentBase::Register()            , ArgumentBase::DerefConstant()       , ArgumentBase::None()       }, 1, "MovRdC" },
    { Instructions::Mov       , OpCodes::MovdCR         , { ArgumentBase::DerefConstant()       , ArgumentBase::Register()            , ArgumentBase::None()       }, 0, "MovdCR" },
    { Instructions::Mov       , OpCodes::MovdRoR        , { ArgumentBase::DerefRegisterOffset() , ArgumentBase::Register()            , ArgumentBase::None()       }, 0, "MovdRoR" },
    { Instructions::Push      , OpCodes::PushR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "PushR" },
    { Instructions::Pop       , OpCodes::PopR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "PopR" },
    { Instructions::Cmp       , OpCodes::CmpRR          , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "CmpRR" },
    { Instructions::Cmp       , OpCodes::CmpRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1, "CmpRC" },
    { Instructions::Jmp       , OpCodes::JmpC           , { ArgumentBase::Constant()            , ArgumentBase::None()                , ArgumentBase::None()       }, 0, "JmpC" },
    { Instructions::Jne       , OpCodes::JneC           , { ArgumentBase::Constant()            , ArgumentBase::None()                , ArgumentBase::None()       }, 0, "JneC" },
    { Instructions::Je        , OpCodes::JeC            , { ArgumentBase::Constant()            , ArgumentBase::None()                , ArgumentBase::None()       }, 0, "JeC" },
    { Instructions::Call      , OpCodes::CallR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "CallR" },
    { Instructions::Ret       , OpCodes::Ret            , { ArgumentBase::None()                , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "Ret" },
    { Instructions::RCall     , OpCodes::RCallRC        , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1, "RCallRC" },
    { Instructions::RRet      , OpCodes::RRet           , { ArgumentBase::None()                , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "RRet" },
    { Instructions::Add       , OpCodes::AddRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1, "AddRC" },
    { Instructions::Add       , OpCodes::AddRR          , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "AddRR" },
    { Instructions::MulAdd    , OpCodes::MulAddRRC      , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::Constant()   }, 2, "MulAddRRC" },
    { Instructions::Inc       , OpCodes::IncR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "IncR" },
    { Instructions::Dec       , OpCodes::DecR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "DecR" },
    { Instructions::Fadd      , OpCodes::FaddRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FaddRR" },
    { Instructions::Fsub      , OpCodes::FsubRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FsubRR" },
    { Instructions::Fconv     , OpCodes::FconvR         , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "FconvR" },
    { Instructions::Fmul      , OpCodes::FmulRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FmulRR" },
    { Instructions::Fdiv      , OpCodes::FdivRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FdivRR" },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::Register()   }, -1, "FmuladdRRR" },
    { Instructions::Fmin      , OpCodes::FminRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FminRR" },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "FmaxRR" },
    { Instructions::Vfadd     , OpCodes::VfaddRR        , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1, "VfaddRR" },
    { Instructions::Dout      , OpCodes::DoutR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1, "DoutR" },
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

