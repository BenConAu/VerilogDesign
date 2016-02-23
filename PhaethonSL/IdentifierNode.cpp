#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"

IdentifierNode::IdentifierNode(PSLCompilerContext* pContext, int symIndex) : ExpressionNode(pContext)
{
    _symIndex = symIndex;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Add a reference to the variable
    GetContext()->_varCollection.AddReference(_symIndex, this);

    // Find the type of the expression
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);

    SetType(pInfo->GetTypeInfo());
}

void IdentifierNode::ProcessNodeImpl()
{
    SetResultRegister(GetContext()->_varCollection.GetInfo(_symIndex)->GetRegIndex());
}
