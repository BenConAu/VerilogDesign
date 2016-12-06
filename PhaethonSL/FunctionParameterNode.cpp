#include "FunctionParameterNode.h"
#include "FunctionDeclaratorNode.h"
#include "TypeNode.h"

void FunctionParameterNode::VerifyNodeImpl()
{
    //printf("Adding parameter %s\n", GetContext()->_symbols[_symIndex].c_str());
    // Is this a global?
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    // Our index in the function is the register we want
    int index = GetParent()->GetChildIndex(this);
    RegIndex regIndex = static_cast<RegIndex>(index - 1);

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_varCollection.AddVariable(
        _symIndex,
        pFunc,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());

    VariablePath* pPath = GetContext()->_pathCollection.EnsurePath(
        pParamInfo);

    pPath->ReserveRegister(pFunc, regIndex);
}
