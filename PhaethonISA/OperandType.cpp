#include "OperandType.h"

const char* OperandTypeHelper::ppszTypeText[] = {
    "None",
    "Constant",
    "Register",
    "DerefConstant",
    "DerefRegister",
    "DerefRegisterOffset",
};

const char* OperandTypeHelper::ppszShortTypeText[] = {
    "",
    "C",
    "R",
    "dC",
    "dR",
    "dRo",
};
