#include "ModuleParameterNode.h"
#include "ModuleDefinitionNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"
#include "OutputContext.h"

void ModuleParameterNode::VerifyNodeImpl()
{
    VariableLocationType location = VariableLocationType::Input;
    if (_fOut)
    {
        location = VariableLocationType::Output;
    }

    TypeNode* pTypeNode = dynamic_cast<TypeNode *>(GetChild(0));
    TypeInfo* pTypeInfo = pTypeNode->GetTypeInfo();

    // Needs to be a register
    if (!pTypeInfo->IsVerilogRegister())
    {
        GetContext()->ReportError(GetLocation(), "Parameters to modules need to be outputting verilog registers");
    }

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->GetSymbolTable()->AddVariable(
        GetTypedParent<ModuleDefinitionNode>(),
        _symIndex,
        location,
        pTypeNode->GetModifier(),
        pTypeInfo
        );
}

void ModuleParameterNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pModule));
    const char* pszInOut = _fOut ? "output" : "input";
    const char* pszModifier = (pInfo->GetModifier() == TypeModifier::Wire || !_fOut) ? "wire" : "reg";
    
    pContext->OutputLine(
        "%s %s[%d:0] %s;",
        pszInOut,
        pszModifier, 
        pInfo->GetTypeInfo()->GetBitLength() - 1, 
        pInfo->GetSymbol());
}

