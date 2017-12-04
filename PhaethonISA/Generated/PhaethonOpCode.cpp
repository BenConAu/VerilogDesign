#include "../InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , "mov" },
    { Instructions::Pack      , "pack" },
    { Instructions::Push      , "push" },
    { Instructions::Pop       , "pop" },
    { Instructions::Cmp       , "cmp" },
    { Instructions::CmpE      , "cmpe" },
    { Instructions::CmpNe     , "cmpne" },
    { Instructions::CmpLt     , "cmplt" },
    { Instructions::CmpGt     , "cmpgt" },
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
    { Instructions::Shl       , "shl" },
    { Instructions::Shr       , "shr" },
    { Instructions::Neg       , "neg" },
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
    { Instructions::Din       , "din" },
    { Instructions::Dlen      , "dlen" },
    { Instructions::ReadPort  , "readport" },
    { Instructions::WritePort , "writeport" },
    { Instructions::Exec      , "exec" },
    { Instructions::Exit      , "exit" },
    { Instructions::VpEnable  , "vpenable" },
    { Instructions::Lea       , "lea" },
    { Instructions::SysCall   , "syscall" },
};

int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);

OpCodeData OpCodeData::s_data[] = {
    { Instructions::Mov       , OpCode::MovRR          , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "MovRR" },
    { Instructions::Mov       , OpCode::MovRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "MovRC" },
    { Instructions::Mov       , OpCode::MovRdR         , { OperandType::Register              , OperandType::DerefRegister         , OperandType::None         }, -1, "MovRdR" },
    { Instructions::Mov       , OpCode::MovRdRo        , { OperandType::Register              , OperandType::DerefRegisterOffset   , OperandType::None         }, 1, "MovRdRo" },
    { Instructions::Mov       , OpCode::MovRdRoR       , { OperandType::Register              , OperandType::DerefRegisterOffset   , OperandType::Register     }, 1, "MovRdRoR" },
    { Instructions::Mov       , OpCode::MovRdC         , { OperandType::Register              , OperandType::DerefConstant         , OperandType::None         }, 1, "MovRdC" },
    { Instructions::Mov       , OpCode::MovdCR         , { OperandType::DerefConstant         , OperandType::Register              , OperandType::None         }, 0, "MovdCR" },
    { Instructions::Mov       , OpCode::MovdRoR        , { OperandType::DerefRegisterOffset   , OperandType::Register              , OperandType::None         }, 0, "MovdRoR" },
    { Instructions::Mov       , OpCode::MovdRoRR       , { OperandType::DerefRegisterOffset   , OperandType::Register              , OperandType::Register     }, 0, "MovdRoRR" },
    { Instructions::Pack      , OpCode::PackRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "PackRRR" },
    { Instructions::Push      , OpCode::PushR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "PushR" },
    { Instructions::Pop       , OpCode::PopR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "PopR" },
    { Instructions::Cmp       , OpCode::CmpRR          , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "CmpRR" },
    { Instructions::Cmp       , OpCode::CmpRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "CmpRC" },
    { Instructions::CmpE      , OpCode::CmpERRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "CmpERRR" },
    { Instructions::CmpNe     , OpCode::CmpNeRRR       , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "CmpNeRRR" },
    { Instructions::CmpLt     , OpCode::CmpLtRRR       , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "CmpLtRRR" },
    { Instructions::CmpGt     , OpCode::CmpGtRRR       , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "CmpGtRRR" },
    { Instructions::Jmp       , OpCode::JmpC           , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JmpC" },
    { Instructions::Jne       , OpCode::JneC           , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JneC" },
    { Instructions::Je        , OpCode::JeC            , { OperandType::Constant              , OperandType::None                  , OperandType::None         }, 0, "JeC" },
    { Instructions::Jz        , OpCode::JzRC           , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "JzRC" },
    { Instructions::Jnz       , OpCode::JnzRC          , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "JnzRC" },
    { Instructions::Call      , OpCode::CallR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "CallR" },
    { Instructions::Ret       , OpCode::Ret            , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "Ret" },
    { Instructions::RCall     , OpCode::RCallRC        , { OperandType::Register              , OperandType::Constant              , OperandType::None         }, 1, "RCallRC" },
    { Instructions::RRet      , OpCode::RRet           , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "RRet" },
    { Instructions::Add       , OpCode::AddRRC         , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "AddRRC" },
    { Instructions::Add       , OpCode::AddRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "AddRRR" },
    { Instructions::Sub       , OpCode::SubRRC         , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "SubRRC" },
    { Instructions::Sub       , OpCode::SubRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "SubRRR" },
    { Instructions::MulAdd    , OpCode::MulAddRRC      , { OperandType::Register              , OperandType::Register              , OperandType::Constant     }, 2, "MulAddRRC" },
    { Instructions::Inc       , OpCode::IncR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "IncR" },
    { Instructions::Dec       , OpCode::DecR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DecR" },
    { Instructions::Shl       , OpCode::ShlRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "ShlRRR" },
    { Instructions::Shr       , OpCode::ShrRRR         , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "ShrRRR" },
    { Instructions::Neg       , OpCode::NegRR          , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "NegRR" },
    { Instructions::Fadd      , OpCode::FaddRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FaddRRR" },
    { Instructions::Fsub      , OpCode::FsubRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FsubRR" },
    { Instructions::Fconv     , OpCode::FconvR         , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "FconvR" },
    { Instructions::Fmul      , OpCode::FmulRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FmulRRR" },
    { Instructions::Fdiv      , OpCode::FdivRRR        , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FdivRRR" },
    { Instructions::Fmuladd   , OpCode::FmuladdRRR     , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "FmuladdRRR" },
    { Instructions::Fmin      , OpCode::FminRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FminRR" },
    { Instructions::Fmax      , OpCode::FmaxRR         , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "FmaxRR" },
    { Instructions::Vfadd     , OpCode::VfaddRRR       , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "VfaddRRR" },
    { Instructions::Dout      , OpCode::DoutR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DoutR" },
    { Instructions::Din       , OpCode::DinR           , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DinR" },
    { Instructions::Dlen      , OpCode::DlenR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "DlenR" },
    { Instructions::ReadPort  , OpCode::ReadPortRR     , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "ReadPortRR" },
    { Instructions::WritePort , OpCode::WritePortRR    , { OperandType::Register              , OperandType::Register              , OperandType::None         }, -1, "WritePortRR" },
    { Instructions::Exec      , OpCode::ExecR          , { OperandType::Register              , OperandType::None                  , OperandType::None         }, -1, "ExecR" },
    { Instructions::Exit      , OpCode::Exit           , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "Exit" },
    { Instructions::VpEnable  , OpCode::VpEnable       , { OperandType::None                  , OperandType::None                  , OperandType::None         }, -1, "VpEnable" },
    { Instructions::Lea       , OpCode::LeaRRoR        , { OperandType::Register              , OperandType::RegisterOffset        , OperandType::Register     }, 1, "LeaRRoR" },
    { Instructions::SysCall   , OpCode::SysCallRRR     , { OperandType::Register              , OperandType::Register              , OperandType::Register     }, -1, "SysCallRRR" },
};

int OpCodeData::s_dataCount = sizeof(OpCodeData::s_data) / sizeof(OpCodeData::s_data[0]);

bool Is8ByteOpcode(OpCode opCodeParam)
{
    if (opCodeParam == OpCode::MovRC ||
        opCodeParam == OpCode::MovRdRo ||
        opCodeParam == OpCode::MovRdRoR ||
        opCodeParam == OpCode::MovRdC ||
        opCodeParam == OpCode::MovdCR ||
        opCodeParam == OpCode::MovdRoR ||
        opCodeParam == OpCode::MovdRoRR ||
        opCodeParam == OpCode::CmpRC ||
        opCodeParam == OpCode::JmpC ||
        opCodeParam == OpCode::JneC ||
        opCodeParam == OpCode::JeC ||
        opCodeParam == OpCode::JzRC ||
        opCodeParam == OpCode::JnzRC ||
        opCodeParam == OpCode::RCallRC ||
        opCodeParam == OpCode::AddRRC ||
        opCodeParam == OpCode::SubRRC ||
        opCodeParam == OpCode::MulAddRRC ||
        opCodeParam == OpCode::LeaRRoR)
        return true;
    else
        return false;
}

bool IsRAMOpcode(OpCode opCodeParam)
{
    if (opCodeParam == OpCode::MovRdR ||
        opCodeParam == OpCode::MovRdRo ||
        opCodeParam == OpCode::MovRdRoR ||
        opCodeParam == OpCode::MovRdC ||
        opCodeParam == OpCode::MovdCR ||
        opCodeParam == OpCode::MovdRoR ||
        opCodeParam == OpCode::MovdRoRR ||
        opCodeParam == OpCode::PushR ||
        opCodeParam == OpCode::PopR ||
        opCodeParam == OpCode::CallR ||
        opCodeParam == OpCode::Ret ||
        opCodeParam == OpCode::SysCallRRR)
        return true;
    else
        return false;
}

