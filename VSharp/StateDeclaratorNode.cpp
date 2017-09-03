#include "StateDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

StateDeclaratorNode::StateDeclaratorNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int ident,
    ASTNode *pStatementList) : ASTNode(pContext)
{
    _location = location;
    _identifier = ident;

    AddNode(pStatementList);
}

void StateDeclaratorNode::VerifyNodeImpl()
{
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();

    // Add function to collection
    GetContext()->_symbolTable.AddState(
        _identifier,
        pFunc
        );    
}

bool StateDeclaratorNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();

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
