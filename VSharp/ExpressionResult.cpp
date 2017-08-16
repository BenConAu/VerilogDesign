#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

ExpressionResult::ExpressionResult(const std::string& str)
{
    _result = str;
    _pStaticInfo = nullptr;
}

ExpressionResult::ExpressionResult(StaticTypeInfo* pInfo)
{
    _pStaticInfo = pInfo;
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
