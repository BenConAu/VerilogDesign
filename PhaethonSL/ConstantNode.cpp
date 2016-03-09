#include "ConstantNode.h"
#include "PSLCompilerContext.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"

ConstantNode::ConstantNode(PSLCompilerContext* pContext, int v)  : ExpressionNode(pContext)
{
    _intValue = v;
    _type = Int;
}

ConstantNode::ConstantNode(PSLCompilerContext* pContext, float v) : ExpressionNode(pContext)
{
    _floatValue = v;
    _type = Float;
}

int ConstantNode::GetInteger()
{
    if (_type == Int)
    {
        return _intValue;
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

void ConstantNode::PostProcessNodeImpl()
{
    printf("mov r%d, %d\n", GetResultRegister(), GetInteger());
}

RegIndex ConstantNode::CalcResultLocationImpl()
{
    return GetContext()->_regCollection.AllocateRegister();
}
