#include "StructSpecifierNode.h"
#include "TypeCollection.h"
#include "StructDeclarationNode.h"
#include "StructTypeInfo.h"
#include "PSLCompilerContext.h"

StructSpecifierNode::StructSpecifierNode(PSLCompilerContext* pContext, ASTNode* pTypeNode) : ASTNode(pContext)
{
    AddNode(pTypeNode);
}

void StructSpecifierNode::SetName(int symIndex)
{
    _symIndex = symIndex;
}

void StructSpecifierNode::PreProcessNodeImpl()
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

    GetContext()->_typeCollection.AddStructType(_symIndex, pNewType);

    //printf("Added a struct\n");
}
