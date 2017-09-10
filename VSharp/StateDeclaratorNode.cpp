#include "StateDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

StateDeclaratorNode::StateDeclaratorNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int ident,
    ASTNode *pStatementList) : ASTNode(pContext, location)
{
    _identifier = ident;

    AddNode(pStatementList);
}

void StateDeclaratorNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    // Add function to collection
    GetContext()->_symbolTable.AddState(
        _identifier,
        pFunc
        );    
}

bool StateDeclaratorNode::PreProcessNodeImpl()
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    SymbolInfo* pStateSymbolInfo = nullptr;
    if (_identifier != -1)
    {
        pStateSymbolInfo = GetContext()->_symbolTable.GetInfo(_identifier, pFunc);
        GetContext()->OutputLine("`__%s: begin", pStateSymbolInfo->GetSymbol());
    }
    else
    {
        GetContext()->OutputLine("`__initial: begin");
    }

    GetContext()->IncreaseIndent();

    return true;
}

void StateDeclaratorNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
