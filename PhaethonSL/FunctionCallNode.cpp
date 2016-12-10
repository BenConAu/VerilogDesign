#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "FunctionDeclaratorNode.h"

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    int symIndex,
    ASTNode *pFirstArg) : ExpressionNode(pContext)
{
    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
}

void FunctionCallNode::VerifyNodeImpl()
{
    // Function needs to be defined
    FunctionInfo *pInfo = GetFunctionInfo();

    SetType(pInfo->GetReturnTypeInfo());
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    // Figure out how many registers are in use in our scope
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();
    RegIndex firstAvail = pScope->GetRegCollection()->FirstUnused();
    RegIndex firstArg = firstAvail + 2;

    return nullptr;
}

FunctionInfo *FunctionCallNode::GetFunctionInfo()
{
    return dynamic_cast<FunctionInfo*>(GetContext()->_varCollection.GetInfo(_symIndex));
}
