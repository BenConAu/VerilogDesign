#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"

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

ExpressionResult* IdentifierNode::CalculateResult()
{
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);

    // See where the variable lives
    if (pInfo->GetLocationType() == LocationType::Memory)
    {
        // Return it as a memory expression
        return new ExpressionResult(pInfo, Operand(pInfo, GetContext()));
    }
    else
    {
        // It is a register already, so return that
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();
        RegIndex regIndex = pInfo->GetRegIndex(pScope);

        return new ExpressionResult(pInfo, Operand(regIndex));
    }
}
