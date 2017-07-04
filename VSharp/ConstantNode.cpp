#include "ConstantNode.h"
#include "PSLCompilerContext.h"
#include "VSharp.tab.h"
#include "RegisterTypeInfo.h"
#include <string.h>

ConstantNode::ConstantNode(PSLCompilerContext *pContext, ConstantType t, int v) : ExpressionNode(pContext)
{
    _intValue = v;
    _type = t;
}

ConstantNode::ConstantNode(PSLCompilerContext *pContext, float v) : ExpressionNode(pContext)
{
    _floatValue = v;
    _type = Float;
}

ConstantNode::ConstantNode(PSLCompilerContext *pContext, ConstantType t) : ExpressionNode(pContext)
{
    _intValue = 0;
    _type = t;
}

int ConstantNode::GetInteger()
{
    switch (_type)
    {
    case Word:
    case Bool:
        return _intValue;

    case Float:
        int intValue;
        ::memcpy(&intValue, &_floatValue, 4);
        return intValue;

    default:
        throw "Not an integer";
    }
}

bool ConstantNode::IsConstant() const 
{ 
    return true; 
}

void ConstantNode::VerifyNodeImpl()
{
    // Constants are 32 bit unless we extend things somehow
    SetType(GetContext()->_typeCollection.GetRegisterType(32));
}

ExpressionResult *ConstantNode::CalculateResult()
{
    char result[100];
    sprintf(result, "%d", GetInteger());
    return new ExpressionResult(result);
}
