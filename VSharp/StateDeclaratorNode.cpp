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
    _KnownState = KnownStates::None;

    AddNode(pStatementList);
}

StateDeclaratorNode::StateDeclaratorNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    KnownStates state,
    ASTNode *pStatementList) : ASTNode(pContext, location)
{
    _identifier = -1;
    _KnownState = state;

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
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    SymbolInfo* pStateSymbolInfo = nullptr;
    switch (_KnownState)
    {
        case KnownStates::None:
        {
            std::vector<SymbolInfo*> Symbols;
            GetContext()->GetSymbolTable()->GetSymbols(_identifier, pModule, Symbols);
            
            pStateSymbolInfo = Symbols[0];
            pContext->OutputLine("`__%s: begin", pStateSymbolInfo->GetSymbol());
            break;
        }

        case KnownStates::Initial:
            pContext->OutputLine("`__initial: begin");
            break;

        case KnownStates::Always:
            // Nothing output here intentionally
            break;
    }

    if (_KnownState != KnownStates::Always)
    {
        pContext->IncreaseIndent();        
    }

    return true;
}

void StateDeclaratorNode::PostProcessNodeImpl(OutputContext* pContext)
{
    if (_KnownState != KnownStates::Always)
    {
        pContext->DecreaseIndent();
        pContext->OutputLine("end");
    }
}
