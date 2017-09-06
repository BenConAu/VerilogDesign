#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

ExpressionResult::ExpressionResult(const std::string& str)
{
    _result = str;
    _pStaticInfo = nullptr;
    _pConstructorCall = nullptr;
}

ExpressionResult::ExpressionResult(StaticTypeInfo* pInfo)
{
    //printf("Creating expression result from static type info\n");

    _pStaticInfo = pInfo;
    _pConstructorCall = nullptr;
}

ExpressionResult::ExpressionResult(const std::string& str, FunctionCallNode* pNode)
{
    _result = str;
    _pConstructorCall = pNode;
}

const std::string& ExpressionResult::GetString() const 
{ 
    if (_pStaticInfo != nullptr)
    {
        printf("Oops!\n");
    }

    return _result; 
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
