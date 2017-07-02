#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

// ExpressionResult to represent a constant
ExpressionResult::ExpressionResult(const std::string& str)
{
    _result = str;
}

std::string ExpressionResult::DebugPrint()
{
    char debug[200];

    sprintf(
        debug,
        "ExpressionResult result = %s\n",
        _result.c_str());

    return debug;
}
