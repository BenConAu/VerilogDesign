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
    if (!pTypeInfo->IsVerilogRegister())
    {
        GetContext()->ReportError(_location, "Parameters to modules need to be outputting verilog registers");
    }

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->_symbolTable.AddVariable(
        pModule,
        _symIndex,
        location,
        pTypeInfo
        );
}

void ModuleParameterNode::PostProcessNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    const char* pszModifier = _fOut ? "output reg" : "input wire";

    GetContext()->OutputLine(
        "%s[%d:0] %s;", 
        pszModifier, 
        pInfo->GetTypeInfo()->GetBitLength() - 1, 
        pInfo->GetSymbol());
}

