#include "VariableDeclarationNode.h"
#include "FunctionDeclaratorNode.h"
#include "AssignmentNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr) : ASTNode(pContext)
{
    AddNode(pType);

    if (pInitExpr != nullptr)
    {
        IdentifierNode *pLeft = new IdentifierNode(pContext, location, symIndex);
        AssignmentNode *pAssignment = new AssignmentNode(pContext, pLeft, pInitExpr);

        AddNode(pAssignment);
    }

    _symIndex = symIndex;
    _fGlobal = false;
}

void VariableDeclarationNode::PreVerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());
    // Is this a global?
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();
    if (pFunc == nullptr)
    {
        _fGlobal = true;
    }

    // Add variable to collection and mark first usage
    GetContext()->_varCollection.AddVariable(
        _symIndex,
        pFunc,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());
}

void VariableDeclarationNode::PostProcessNodeImpl()
{
    // Nothing to output for declarations
}
