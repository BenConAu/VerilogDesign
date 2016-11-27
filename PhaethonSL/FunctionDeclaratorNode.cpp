#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"

void FunctionDeclaratorNode::PreProcessNodeImpl()
{
    // Allocate registers for locals
    for (int i = 0; i < _paramCount; i++)
    {
        FunctionParameterNode* pParam = dynamic_cast<FunctionParameterNode*>(GetChild(i));

         
    }

    // non-main functions have a prologue
    if (!IsEntryPoint())
    {
        GetContext()->OutputLabel(GetContext()->_symbols[_symIndex].c_str());
    }
}
