#include "StateDeclaratorNode.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "OutputContext.h"

StateDeclaratorNode::StateDeclaratorNode(
    ParserContext *pContext,
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
    GetContext()->GetSymbolTable()->AddState(
        _identifier,
        pFunc
        );    
}

bool StateDeclaratorNode::PreProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    SymbolInfo* pStateSymbolInfo = nullptr;
    if (_identifier != -1)
    {
        pStateSymbolInfo = GetContext()->GetSymbolTable()->GetInfo(_identifier, pFunc);
        pContext->OutputLine("`__%s: begin", pStateSymbolInfo->GetSymbol());
    }
    else
    {
        pContext->OutputLine("`__initial: begin");
    }

    pContext->IncreaseIndent();

    return true;
}

void StateDeclaratorNode::PostProcessNodeImpl(OutputContext* pContext)
{
    pContext->DecreaseIndent();
    pContext->OutputLine("end");
}
