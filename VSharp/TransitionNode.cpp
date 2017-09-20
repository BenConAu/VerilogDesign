#include "TransitionNode.h"
#include "ExpressionNode.h"
#include "ModuleDefinitionNode.h"
#include "StateInfo.h"
#include "OutputContext.h"

void TransitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // What module are we transitioning in
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();
    SymbolInfo* pInfo = GetContext()->GetSymbolTable()->GetInfo(_symIndex, pFunc);

    // Get the info
    StateInfo* pStateInfo = dynamic_cast<StateInfo*>(pInfo);
    if (pStateInfo == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Unknown state %s", GetContext()->GetSymbolString(_symIndex).c_str());
    }

    // Write out the state change
    pContext->OutputLine("fsmState <= `__%s;", pStateInfo->GetSymbol());
}

ASTNode* TransitionNode::DuplicateNodeImpl()
{
    return new TransitionNode(GetContext(), GetLocation(), _symIndex);
}
