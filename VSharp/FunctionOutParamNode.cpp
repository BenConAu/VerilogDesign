#include "FunctionOutParamNode.h"
#include "FunctionDeclaratorNode.h"
#include "ModuleDeclaratorNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void FunctionOutParamNode::VerifyNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Needs to refer to an existing variable
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    if (pInfo == nullptr)
    {
        throw "Unknown identifier used as out param in function";
    }

    // TODO: Make a mapping from the variable here to the one in the function definition
}

void FunctionOutParamNode::PreProcessNodeImpl()
{
    // Nothing generated specifically for these, we replace at place of use
}

