#include "ConstantNode.h"
#include "PSLCompilerContext.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"
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
    case Pointer:
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
    TypeInfo *pTypeInfo = nullptr;

    switch (_type)
    {
    case Bool:
        pTypeInfo = GetContext()->_typeCollection.GetBasicType(BOOL_TOKEN);
        break;

    case Word:
        pTypeInfo = GetContext()->_typeCollection.GetBasicType(WORD_TOKEN);
        break;

    case Float:
        pTypeInfo = GetContext()->_typeCollection.GetBasicType(FLOAT_TOKEN);
        break;

    case Pointer:
        pTypeInfo = GetContext()->_typeCollection.GetPointerType(nullptr);
        break;

    default:
        throw "Unknown type so cannot calculate result";
    }

    SetType(pTypeInfo);
}

ExpressionResult *ConstantNode::CalculateResult()
{
    return new ExpressionResult(Operand(GetInteger()));
}
