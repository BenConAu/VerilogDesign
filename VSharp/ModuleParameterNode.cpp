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

void ModuleParameterNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    const char* pszModifier = _fOut ? "output reg" : "input wire";

    // Find out the bit width
    RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pInfo->GetTypeInfo());

    GetContext()->OutputLine("%s[%d:0] %s;", pszModifier, pRegInfo->GetBitLength() - 1, pInfo->GetSymbol());
}

