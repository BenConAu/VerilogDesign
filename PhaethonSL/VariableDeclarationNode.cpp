#include "VariableDeclarationNode.h"
#include "TypeNode.h"

VariableDeclarationNode::VariableDeclarationNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex) : ASTNode(pContext)
{
    AddNode(pType);
    _symIndex = symIndex;
}

void VariableDeclarationNode::VerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());

    // Add variable to collection and mark first usage
    GetContext()->_varCollection.AddVariable(_symIndex, this, dynamic_cast<TypeNode*>(GetChild(0))->GetTypeInfo());
}

void VariableDeclarationNode::ProcessNodeImpl()
{
    // Nothing to output for declarations
}
