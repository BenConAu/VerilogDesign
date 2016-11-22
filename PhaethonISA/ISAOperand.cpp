#include "ISAOperand.h"

const char* ISAOperand::ppszTypeText[] = {
    "None",
    "Constant",
    "Register",
    "DerefConstant",
    "DerefRegister",
    "DerefRegisterOffset",
};

const char* ISAOperand::ppszShortTypeText[] = {
    "",
    "C",
    "R",
    "dC",
    "dR",
    "dRo",
};
