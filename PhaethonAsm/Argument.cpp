#include "Argument.h"
#include "DataSegmentDef.h"

const char* Argument::ppszTypeText[] = {
    "None",
    "Constant",
    "Register",
    "ConstAddress",
    "RegAddress",
};

const char* Argument::ppszShortTypeText[] = {
    "",
    "C",
    "R",
    "cA",
    "rA",
};

void Argument::ResolveSymbol()
{
    if (_fDelayed)
    {
        _value = DataSegmentDef::CalcAddress(_value);
        _fDelayed = false;

        //printf("Resolving symbol to %x\n", _value);
    }
}
