#include "AttachModuleNode.h"
#include "ModuleDefinitionNode.h"
#include "AssignmentNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableLocationType.h"
#include "VariableInfo.h"
#include "OutputContext.h"

int AttachModuleNode::s_attachCount = 0;

AttachModuleNode::AttachModuleNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pInitExpr) : ASTNode(pContext, location)
{
    AddNode(pInitExpr);

    _symIndex = -1;
    _pModuleTypeInfo = nullptr;
}

void AttachModuleNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    // Attaching modules does not require an identifier because it isn't needed,
    // but the verilog output needs something.
    char genName[128];
    ::sprintf(genName, "__attach__%d", s_attachCount);
    _symIndex = GetContext()->AddSymbol(genName);

    // Find the type info for the module
    _pModuleTypeInfo = dynamic_cast<ModuleTypeInfo*>(GetContext()->GetTypeCollection()->GetModuleType(_symIndex)); 

    if (_pModuleTypeInfo == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Unknown module type %s", GetContext()->GetSymbolString(_symIndex).c_str());
    }

    // Add variable to collection and mark first usage
    VariableInfo* pVarInfo = GetContext()->GetSymbolTable()->AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::None,
        TypeModifier::None,
        _pModuleTypeInfo);

    if (pVarInfo == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Duplicate variable declaration %s", GetContext()->GetSymbolString(_symIndex).c_str());
    }
}

void AttachModuleNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    std::vector<VariableInfo*> Symbols;
    GetContext()->GetSymbolTable()->GetSymbols(_symIndex, pModule, Symbols);

    VariableInfo* pInfo = Symbols[0];

    // Each type should know how to make a declaration
    std::string decl = pInfo->GetTypeInfo()->GetDeclaration(pInfo, GetInitNode());

    // This node owns putting the semicolon on it
    pContext->OutputLine("%s;", decl.c_str());    
}

ExpressionNode* AttachModuleNode::GetInitNode()
{
    return dynamic_cast<ExpressionNode *>(GetChild(0));
}