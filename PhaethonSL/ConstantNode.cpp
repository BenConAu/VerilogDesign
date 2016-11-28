#include "ConstantNode.h"
#include "PSLCompilerContext.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"

ConstantNode::ConstantNode(PSLCompilerContext *pContext, int v) : ExpressionNode(pContext)
{
    _intValue = v;
    _type = Int;
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
    if (_type == Int)
    {
        return _intValue;
    }
    else if (_type == Float)
    {
        int intValue;
        ::memcpy(&intValue, &_floatValue, 4);
        return intValue;
    }
    else
    {
        throw "Not an integer";
    }
}

bool ConstantNode::IsConstant() const { return true; }

void ConstantNode::VerifyNodeImpl()
{
    SetType(GetContext()->_typeCollection.GetBasicType(INT_TOKEN));
}

ExpressionResult *ConstantNode::CalculateResult()
{
    TypeInfo *pTypeInfo = nullptr;

    if (_type == Int)
    {
        pTypeInfo = GetContext()->_typeCollection.GetBasicType(INT_TOKEN);
    }
    else if (_type == Float)
    {
        pTypeInfo = GetContext()->_typeCollection.GetBasicType(FLOAT_TOKEN);
    }
    else
    {
        throw "Unknown type so cannot calculate result";
    }

    return new ExpressionResult(pTypeInfo, Operand(GetInteger()));
}
