#include "ConstantNode.h"
#include "ParserContext.h"
#include "VSharp.tab.h"
#include "RegisterTypeInfo.h"
#include <string.h>

ConstantNode::ConstantNode(
    ParserContext *pContext, 
    const YYLTYPE& location, 
    const UIntConstant& v) : ExpressionNode(pContext, location)
{
    _value = v;
}

ASTNode* ConstantNode::DuplicateNodeImpl(FunctionExpandType type)
{
    return new ConstantNode(GetContext(), GetLocation(), _value);
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
    SetType(GetContext()->GetTypeCollection()->GetRegisterType(_value._bitLength));
}

ExpressionResult *ConstantNode::CalculateResult()
{
    return new ExpressionResult(_value);
}

bool ConstantNode::ConstEvaluate(UIntConstant* pVal)
{
    (*pVal) = _value;
    return true;
}
