#include "TransitionNode.h"
#include "ExpressionNode.h"
#include "ModuleDefinitionNode.h"
#include "StateInfo.h"
#include "OutputContext.h"

void TransitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // What module are we transitioning in
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Get the info
    std::vector<StateInfo*> Symbols;
    GetContext()->GetSymbolTable()->GetSymbols(_symIndex, pModule, Symbols);

    if (Symbols.size() == 0)
    {
        GetContext()->ReportError(GetLocation(), "Unknown state %s", GetContext()->GetSymbolString(_symIndex).c_str());        
    }

    StateInfo* pStateInfo = Symbols[0];

    // Write out the state change
    pContext->OutputLine("fsmState <= `__%s;", pStateInfo->GetSymbol());
}

ASTNode* TransitionNode::DuplicateNodeImpl(FunctionExpandType type)
{
    return new TransitionNode(GetContext(), GetLocation(), _symIndex);
}
