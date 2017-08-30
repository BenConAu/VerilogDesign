#include "ConstantNode.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"
#include "RegisterTypeInfo.h"
#include <string.h>

ConstantNode::ConstantNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE& location, 
    const UIntConstant& v) : ExpressionNode(pContext, location)
{
    _value = v;
}

unsigned int ConstantNode::GetUInt()
{
    return _value._value;
}

bool ConstantNode::IsConstant() const 
{ 
    return true; 
}

void ConstantNode::VerifyNodeImpl()
{
    SetType(GetContext()->_typeCollection.GetRegisterType(_value._bitLength));
}

ExpressionResult *ConstantNode::CalculateResult()
{
    char result[100];
    sprintf(result, "%u", GetUInt());
    return new ExpressionResult(result);
}
