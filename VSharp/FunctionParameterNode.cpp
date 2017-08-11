#include "FunctionParameterNode.h"
#include "ModuleDeclaratorNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void FunctionParameterNode::VerifyNodeImpl()
{
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

    TypeInfo* pTypeInfo = dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo();

    // Needs to be a register
    RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pTypeInfo);
    if (pRegInfo == nullptr)
    {
        throw "Parameters to modules need to be registers";
    }

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_symbolTable.AddVariable(
        pModule,
        _symIndex,
        location,
        pTypeInfo
        );
}

void FunctionParameterNode::PreProcessNodeImpl()
{
}

