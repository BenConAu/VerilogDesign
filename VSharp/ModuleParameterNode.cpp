#include "ModuleParameterNode.h"
#include "ModuleDeclaratorNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void ModuleParameterNode::VerifyNodeImpl()
{
    //printf("Adding parameter %s\n", GetContext()->_symbols[_symIndex].c_str());
    // Is this a global?
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_symbolTable.AddVariable(
        _symIndex,
        pModule,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());

    // Our index in the function is the register we want
    int index = GetParent()->GetChildIndex(this);
    RegIndex regIndex = static_cast<RegIndex>(index - 1);
}
