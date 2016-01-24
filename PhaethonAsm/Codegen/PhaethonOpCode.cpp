InstructionData g_data[] = {
    { Instructions::Mov       , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Mov       , { Argument::Register       , Argument::ConstAddress   , Argument::None            }, 1 },
    { Instructions::Mov       , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Mov       , { Argument::ConstAddress   , Argument::Register       , Argument::None            }, 0 },
    { Instructions::Mov       , { Argument::Register       , Argument::RegAddress     , Argument::Constant        }, 2 },
    { Instructions::Mov       , { Argument::RegAddress     , Argument::Constant       , Argument::Register        }, 1 },
    { Instructions::Mov       , { Argument::Register       , Argument::RegAddress     , Argument::None            }, -1 },
    { Instructions::Cmp       , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Cmp       , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Jmp       , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Jne       , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Add       , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Dec       , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fadd      , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fsub      , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fconv     , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fmul      , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fmuladd   , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Fmin      , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Fmax      , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Dout      , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
};
