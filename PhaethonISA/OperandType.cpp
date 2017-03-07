#include "OperandType.h"

const char* OperandTypeHelper::ppszTypeText[] = {
    "None",
    "ByteConstant",
    "Constant",
    "Register",
    "DerefConstant",
    "DerefRegister",
    "DerefRegisterOffset",
    "RegisterOffset",
};

const char* OperandTypeHelper::ppszShortTypeText[] = {
    "",
    "B",
    "C",
    "R",
    "dC",
    "dR",
    "dRo",
    "Ro"
};
