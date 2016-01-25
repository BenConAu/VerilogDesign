#include "../InstructionData.h"

InstructionData InstructionData::s_data[] = {
    { Instructions::Mov       , OpCodes::MovRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Mov       , OpCodes::MovRcA         , { Argument::Register       , Argument::ConstAddress   , Argument::None            }, 1 },
    { Instructions::Mov       , OpCodes::MovRR          , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Mov       , OpCodes::MovcAR         , { Argument::ConstAddress   , Argument::Register       , Argument::None            }, 0 },
    { Instructions::Mov       , OpCodes::MovRrAC        , { Argument::Register       , Argument::RegAddress     , Argument::Constant        }, 2 },
    { Instructions::Mov       , OpCodes::MovrACR        , { Argument::RegAddress     , Argument::Constant       , Argument::Register        }, 1 },
    { Instructions::Mov       , OpCodes::MovRrA         , { Argument::Register       , Argument::RegAddress     , Argument::None            }, -1 },
    { Instructions::Push      , OpCodes::PushR          , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Pop       , OpCodes::PopR           , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRR          , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Jmp       , OpCodes::JmpC           , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Jne       , OpCodes::JneC           , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Add       , OpCodes::AddRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Inc       , OpCodes::IncR           , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Dec       , OpCodes::DecR           , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fadd      , OpCodes::FaddRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fsub      , OpCodes::FsubRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fconv     , OpCodes::FconvR         , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fmul      , OpCodes::FmulRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Fmin      , OpCodes::FminRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fmax      , OpCodes::FmaxRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Dout      , OpCodes::DoutR          , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
};

int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);

