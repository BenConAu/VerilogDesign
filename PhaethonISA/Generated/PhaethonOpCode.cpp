#include "../InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , "mov" },
    { Instructions::Push      , "push" },
    { Instructions::Pop       , "pop" },
    { Instructions::Cmp       , "cmp" },
    { Instructions::CmpE      , "cmpe" },
    { Instructions::Jmp       , "jmp" },
    { Instructions::Jne       , "jne" },
    { Instructions::Je        , "je" },
    { Instructions::Jz        , "jz" },
    { Instructions::Jnz       , "jnz" },
    { Instructions::Call      , "call" },
    { Instructions::Ret       , "ret" },
    { Instructions::RCall     , "rcall" },
    { Instructions::RRet      , "rret" },
    { Instructions::Add       , "add" },
    { Instructions::Sub       , "sub" },
    { Instructions::MulAdd    , "muladd" },
    { Instructions::Inc       , "inc" },
    { Instructions::Dec       , "dec" },
    { Instructions::Fadd      , "fadd" },
    { Instructions::Fsub      , "fsub" },
    { Instructions::Fconv     , "fconv" },
    { Instructions::Fmul      , "fmul" },
    { Instructions::Fdiv      , "fdiv" },
    { Instructions::Fmuladd   , "fmuladd" },
    { Instructions::Fmin      , "fmin" },
    { Instructions::Fmax      , "fmax" },
    { Instructions::Vfadd     , "vfadd" },
    { Instructions::Dout      , "dout" },
    { Instructions::Stall     , "stall" },
};

int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);

OpCodeData OpCodeData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRR          , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "MovRR" },
    { Instructions::Mov       , OpCodes::MovRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "MovRC" },
    { Instructions::Mov       , OpCodes::MovRdR         , { OperandType::Register              , OperandType::DerefRegister         , OperandType::None         }, -1, "MovRdR" },
    { Instructions::Mov       , OpCodes::MovRdRo        , { OperandType::Register              , OperandType::DerefRegisterOffset   , OperandType::None         }, 1, "MovRdRo" },
    { Instructions::Mov       , OpCodes::MovRdC         , { OperandType::Register              , OperandType::DerefConstant         , OperandType::None         }, 1, "MovRdC" },
    { Instructions::Mov       , OpCodes::MovdCR         , { OperandType::DerefConstant         , OperandType::Register              , OperandType::None         }, 0, "MovdCR" },
    { Instructions::Mov       , OpCodes::MovdRoR        , { OperandType::DerefRegisterOffset   , OperandType::Register              , OperandType::None         }, 0, "MovdRoR" },
    { Instructions::Push      , OpCodes::PushR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "PushR" },
    { Instructions::Pop       , OpCodes::PopR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "PopR" },
    { Instructions::Cmp       , OpCodes::CmpRR          , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "CmpRR" },
    { Instructions::Cmp       , OpCodes::CmpRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "CmpRC" },
    { Instructions::CmpE      , OpCodes::CmpERRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "CmpERRR" },
    { Instructions::Jmp       , OpCodes::JmpC           , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JmpC" },
    { Instructions::Jne       , OpCodes::JneC           , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JneC" },
    { Instructions::Je        , OpCodes::JeC            , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JeC" },
    { Instructions::Jz        , OpCodes::JzRC           , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "JzRC" },
    { Instructions::Jnz       , OpCodes::JnzRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "JnzRC" },
    { Instructions::Call      , OpCodes::CallR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "CallR" },
    { Instructions::Ret       , OpCodes::Ret            , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "Ret" },
    { Instructions::RCall     , OpCodes::RCallRC        , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "RCallRC" },
    { Instructions::RRet      , OpCodes::RRet           , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "RRet" },
    { Instructions::Add       , OpCodes::AddRRC         , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "AddRRC" },
    { Instructions::Add       , OpCodes::AddRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "AddRRR" },
    { Instructions::Sub       , OpCodes::SubRRC         , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "SubRRC" },
    { Instructions::Sub       , OpCodes::SubRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "SubRRR" },
    { Instructions::MulAdd    , OpCodes::MulAddRRC      , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "MulAddRRC" },
    { Instructions::Inc       , OpCodes::IncR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "IncR" },
    { Instructions::Dec       , OpCodes::DecR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DecR" },
    { Instructions::Fadd      , OpCodes::FaddRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FaddRRR" },
    { Instructions::Fsub      , OpCodes::FsubRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FsubRR" },
    { Instructions::Fconv     , OpCodes::FconvR         , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "FconvR" },
    { Instructions::Fmul      , OpCodes::FmulRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FmulRRR" },
    { Instructions::Fdiv      , OpCodes::FdivRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FdivRR" },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FmuladdRRR" },
    { Instructions::Fmin      , OpCodes::FminRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FminRR" },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FmaxRR" },
    { Instructions::Vfadd     , OpCodes::VfaddRRR       , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "VfaddRRR" },
    { Instructions::Dout      , OpCodes::DoutR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DoutR" },
    { Instructions::Stall     , OpCodes::Stall          , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "Stall" },
};

int OpCodeData::s_dataCount = sizeof(OpCodeData::s_data) / sizeof(OpCodeData::s_data[0]);

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
        opCodeParam == OpCodes::JzRC ||
        opCodeParam == OpCodes::JnzRC ||
        opCodeParam == OpCodes::RCallRC ||
        opCodeParam == OpCodes::AddRRC ||
        opCodeParam == OpCodes::SubRRC ||
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

