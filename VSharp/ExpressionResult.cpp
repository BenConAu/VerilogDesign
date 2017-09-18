#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

ExpressionResult::ExpressionResult(const std::string& str)
{
    _result = str;
    _IsConstant = false;
    _pStaticInfo = nullptr;
    _pConstructorCall = nullptr;
}

ExpressionResult::ExpressionResult(StaticTypeInfo* pInfo)
{
    //printf("Creating expression result from static type info\n");
    _IsConstant = false;
    _pStaticInfo = pInfo;
    _pConstructorCall = nullptr;
}

ExpressionResult::ExpressionResult(const std::string& str, FunctionCallNode* pNode)
{
    _result = str;
    _IsConstant = false;
    _pStaticInfo = nullptr;
    _pConstructorCall = pNode;
}

ExpressionResult::ExpressionResult(FieldSelectResult* pRes)
{
    _FieldSelect.reset(pRes);

    char result[1024];
    sprintf(
        result,
        "%s[%u:%u]",
        _FieldSelect->_structResult.c_str(),
        _FieldSelect->_i1,
        _FieldSelect->_i2);

    _result = result;
    _IsConstant = false;
    _pStaticInfo = nullptr;
    _pConstructorCall = nullptr;
}

ExpressionResult::ExpressionResult(const UIntConstant& ConstUInt)
{
    if (ConstUInt._bitLength == 1)
    {
        _result = (ConstUInt._value == 1) ? "1'b1" : "1'b0";
        _IsConstant = true;
        _ConstantValue = (ConstUInt._value == 1);
    }
    else
    {
        char result[100];
        sprintf(result, "%u'd%u", ConstUInt._bitLength, ConstUInt._value);
    
        _result = result;
        _IsConstant = false;
    }    

    _pStaticInfo = nullptr;
    _pConstructorCall = nullptr;
}

const std::string& ExpressionResult::GetString() const 
{ 
    if (_pStaticInfo != nullptr)
    {
        throw "Oops!\n";
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
