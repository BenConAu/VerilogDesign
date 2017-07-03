#include "ModuleParameterNode.h"
#include "ModuleDeclaratorNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void ModuleParameterNode::VerifyNodeImpl()
{
    //printf("Adding parameter %s\n", GetContext()->_symbols[_symIndex].c_str());
    // Is this a global?
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    VariableLocationType location = VariableLocationType::Member;
    if (_fOut)
    {
        location = VariableLocationType::Output;
    }
    else
    {
        location = VariableLocationType::Input;
    }

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_symbolTable.AddVariable(
        pModule,
        _symIndex,
        location,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());
}
