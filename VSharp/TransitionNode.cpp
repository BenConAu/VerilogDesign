#include "TransitionNode.h"
#include "ExpressionNode.h"
#include "ModuleDeclaratorNode.h"
#include "StateInfo.h"

void TransitionNode::PostProcessNodeImpl()
{
    // What module are we transitioning in
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();

    // Get the info
    StateInfo* pInfo = dynamic_cast<StateInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pFunc));

    // Write out the state change
    GetContext()->OutputLine("fsmState <= `__%s;", pInfo->GetSymbol());
}
