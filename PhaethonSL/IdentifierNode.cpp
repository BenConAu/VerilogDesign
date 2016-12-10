#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"

IdentifierNode::IdentifierNode(PSLCompilerContext *pContext, int symIndex) : ExpressionNode(pContext)
{
    _symIndex = symIndex;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Find the type of the expression
    VariableInfo *pInfo = GetVariableInfo();

    SetType(pInfo->GetTypeInfo());
}

ExpressionResult *IdentifierNode::CalculateResult()
{
    VariableInfo *pInfo = GetVariableInfo();
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    return pInfo->CalculateResult(pScope);
}

VariableInfo *IdentifierNode::GetVariableInfo()
{
    return dynamic_cast<VariableInfo*>(GetContext()->_varCollection.GetInfo(_symIndex));
}
