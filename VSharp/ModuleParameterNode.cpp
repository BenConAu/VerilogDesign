#include "ModuleParameterNode.h"
#include "ModuleDeclaratorNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void ModuleParameterNode::VerifyNodeImpl()
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

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_symbolTable.AddVariable(
        pModule,
        _symIndex,
        location,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());
}

void ModuleParameterNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    const char* pszModifier = _fOut ? "output reg" : "input wire";

    GetContext()->OutputLine("%s[7:0] %s;", pszModifier, pInfo->GetSymbol());
}

