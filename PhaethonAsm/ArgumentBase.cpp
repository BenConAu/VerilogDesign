#include "ArgumentBase.h"

const char* ArgumentBase::ppszTypeText[] = {
    "None",
    "Constant",
    "Register",
    "ConstAddress",
    "RegAddress",
};

const char* ArgumentBase::ppszShortTypeText[] = {
    "",
    "C",
    "R",
    "cA",
    "rA",
};
