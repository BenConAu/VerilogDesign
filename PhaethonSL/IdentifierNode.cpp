#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"

IdentifierNode::IdentifierNode(PSLCompilerContext* pContext, int symIndex) : ExpressionNode(pContext)
{
    _symIndex = symIndex;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Find the type of the expression
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);

    SetType(pInfo->GetTypeInfo());
}

void IdentifierNode::PreProcessNodeImpl()
{
}

RegIndex IdentifierNode::CalcResultRegisterImpl()
{
    return GetContext()->_varCollection.GetInfo(_symIndex)->GetRegIndex();
}
