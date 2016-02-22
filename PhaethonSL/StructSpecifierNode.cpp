#include "StructSpecifierNode.h"
#include "TypeCollection.h"
#include "StructDeclarationNode.h"

StructSpecifierNode::StructSpecifierNode(PSLCompilerContext* pContext, ASTNode* pTypeNode) : ASTNode(pContext)
{
    AddNode(pTypeNode);
}

void StructSpecifierNode::SetName(int symIndex)
{
    _symIndex = symIndex;
}

void StructSpecifierNode::ProcessNodeImpl()
{
}

void StructSpecifierNode::VerifyNodeImpl()
{
    // TODO: Struct cannot be declared twice

    // Make the info for the type we are creating
    StructTypeInfo* pNewType = new StructTypeInfo(_symIndex);

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        StructDeclarationNode* pSpecifier = dynamic_cast<StructDeclarationNode*>(GetChild(i));

        pNewType->AddMember(pSpecifier->GetName(), pSpecifier->GetTypeInfo());
    }
}
