#include "OperandType.h"

const char* OperandTypeHelper::ppszTypeText[] = {
    "None",
    "Constant",
    "Register",
    "DerefConstant",
    "DerefRegister",
    "DerefRegisterOffset",
    "DerefRegisterIndex"
};

const char* OperandTypeHelper::ppszShortTypeText[] = {
    "",
    "C",
    "R",
    "dC",
    "dR",
    "dRo",
    "dRi",
};
