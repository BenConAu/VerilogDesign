#include "../InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRR          , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Mov       , OpCodes::MovRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1 },
    { Instructions::Mov       , OpCodes::MovRdR         , { ArgumentBase::Register()            , ArgumentBase::DerefRegister()       , ArgumentBase::None()       }, -1 },
    { Instructions::Mov       , OpCodes::MovRdRo        , { ArgumentBase::Register()            , ArgumentBase::DerefRegisterOffset() , ArgumentBase::None()       }, 1 },
    { Instructions::Mov       , OpCodes::MovRdC         , { ArgumentBase::Register()            , ArgumentBase::DerefConstant()       , ArgumentBase::None()       }, 1 },
    { Instructions::Mov       , OpCodes::MovdCR         , { ArgumentBase::DerefConstant()       , ArgumentBase::Register()            , ArgumentBase::None()       }, 0 },
    { Instructions::Mov       , OpCodes::MovdRoR        , { ArgumentBase::DerefRegisterOffset() , ArgumentBase::Register()            , ArgumentBase::None()       }, 0 },
    { Instructions::Push      , OpCodes::PushR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Pop       , OpCodes::PopR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRR          , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1 },
    { Instructions::Jmp       , OpCodes::JmpC           , { ArgumentBase::Constant()            , ArgumentBase::None()                , ArgumentBase::None()       }, 0 },
    { Instructions::Jne       , OpCodes::JneC           , { ArgumentBase::Constant()            , ArgumentBase::None()                , ArgumentBase::None()       }, 0 },
    { Instructions::Call      , OpCodes::CallR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Ret       , OpCodes::Ret            , { ArgumentBase::None()                , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Add       , OpCodes::AddRC          , { ArgumentBase::Register()            , ArgumentBase::Constant()            , ArgumentBase::None()       }, 1 },
    { Instructions::MulAdd    , OpCodes::MulAddRRC      , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::Constant()   }, 2 },
    { Instructions::Inc       , OpCodes::IncR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Dec       , OpCodes::DecR           , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Fadd      , OpCodes::FaddRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Fsub      , OpCodes::FsubRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Fconv     , OpCodes::FconvR         , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
    { Instructions::Fmul      , OpCodes::FmulRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Fdiv      , OpCodes::FdivRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::Register()   }, -1 },
    { Instructions::Fmin      , OpCodes::FminRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Vfadd     , OpCodes::VfaddRR        , { ArgumentBase::Register()            , ArgumentBase::Register()            , ArgumentBase::None()       }, -1 },
    { Instructions::Dout      , OpCodes::DoutR          , { ArgumentBase::Register()            , ArgumentBase::None()                , ArgumentBase::None()       }, -1 },
};

int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);

