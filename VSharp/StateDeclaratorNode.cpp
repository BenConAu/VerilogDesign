#include "StateDeclaratorNode.h"
#include "PSLCompilerContext.h"
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

void StateDeclaratorNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();
    SymbolInfo* pStateSymbolInfo = GetContext()->_symbolTable.GetInfo(_identifier, pFunc);

    GetContext()->OutputLine("case %s", pStateSymbolInfo->GetSymbol());
    GetContext()->OutputLine("begin");
    GetContext()->IncreaseIndent();
}

void StateDeclaratorNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
