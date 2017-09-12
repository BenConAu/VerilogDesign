#include "TransitionNode.h"
#include "ExpressionNode.h"
#include "ModuleDefinitionNode.h"
#include "StateInfo.h"

void TransitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // What module are we transitioning in
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    // Get the info
    StateInfo* pInfo = dynamic_cast<StateInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pFunc));

    // Write out the state change
    pContext->OutputLine("fsmState <= `__%s;", pInfo->GetSymbol());
}

ASTNode* TransitionNode::DuplicateNodeImpl()
{
    return new TransitionNode(GetContext(), GetLocation(), _symIndex);
}
