#include "StructDeclarationNode.h"
#include "TypeCollection.h"
#include "StructSpecifierNode.h"
#include "TypeNode.h"

StructDeclarationNode::StructDeclarationNode(
    PSLCompilerContext* pContext, 
    ASTNode* pTypeNode, 
    int symId,
    int dimension
    ) : ASTNode(pContext)
{
    AddNode(pTypeNode);
    _symIndex = symId;
    _dimension = dimension;
}

TypeInfo* StructDeclarationNode::GetTypeInfo()
{
    TypeNode* pTypeNode = dynamic_cast<TypeNode*>(GetChild(0));
    return pTypeNode->GetTypeInfo();
}

void StructDeclarationNode::PreProcessNodeImpl()
{
}

void StructDeclarationNode::VerifyNodeImpl()
{
}
