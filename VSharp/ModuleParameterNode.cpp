#include "ModuleParameterNode.h"
#include "ModuleDefinitionNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"
#include "OutputContext.h"

void ModuleParameterNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

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
        GetContext()->ReportError(GetLocation(), "Parameters to modules need to be outputting verilog registers");
    }

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->GetSymbolTable()->AddVariable(
        pModule,
        _symIndex,
        location,
        TypeModifier::None,
        pTypeInfo
        );
}

void ModuleParameterNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pModule));
    const char* pszModifier = _fOut ? "output reg" : "input wire";

    pContext->OutputLine(
        "%s[%d:0] %s;", 
        pszModifier, 
        pInfo->GetTypeInfo()->GetBitLength() - 1, 
        pInfo->GetSymbol());
}

