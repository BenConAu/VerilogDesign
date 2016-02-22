#include "StructDeclarationNode.h"
#include "TypeCollection.h"
#include "StructSpecifierNode.h"
#include "TypeNode.h"

StructDeclarationNode::StructDeclarationNode(PSLCompilerContext* pContext, ASTNode* pTypeNode, int symId) : ASTNode(pContext)
{
    AddNode(pTypeNode);
    _symIndex = symId;
}

TypeInfo* StructDeclarationNode::GetTypeInfo()
{
    TypeNode* pTypeNode = dynamic_cast<TypeNode*>(GetChild(0));
    return pTypeNode->GetTypeInfo();
}

void StructDeclarationNode::ProcessNodeImpl()
{
}

void StructDeclarationNode::VerifyNodeImpl()
{
}