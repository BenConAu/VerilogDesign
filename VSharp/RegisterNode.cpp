#include "RegisterNode.h"
#include "PSLCompilerContext.h"

RegisterNode::RegisterNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    RegIndex index) : ExpressionNode(pContext)
{
    _location = location;
    _index = index;
}

void RegisterNode::VerifyNodeImpl()
{
}

ExpressionResult *RegisterNode::CalculateResult()
{
    Operand opReg(_index);

    return new ExpressionResult(opReg);
}
