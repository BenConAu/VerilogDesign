#include "StructSpecifierNode.h"
#include "TypeCollection.h"
#include "StructDeclarationNode.h"
#include "StructTypeInfo.h"
#include "VSharpCompilerContext.h"

StructSpecifierNode::StructSpecifierNode(ParserContext* pContext, const YYLTYPE &location, ASTNode* pTypeNode) : ASTNode(pContext, location)
{
    AddNode(pTypeNode);
}

void StructSpecifierNode::SetName(int symIndex)
{
    _symIndex = symIndex;
}

void StructSpecifierNode::VerifyNodeImpl()
{
    // TODO: Struct cannot be declared twice

    // Make the info for the type we are creating
    StructTypeInfo* pNewType = new StructTypeInfo(_symIndex, GetContext());
    GetContext()->GetTypeCollection()->AddStructType(_symIndex, pNewType);

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        StructDeclarationNode* pSpecifier = dynamic_cast<StructDeclarationNode*>(GetChild(i));

        pNewType->AddMember(
            GetContext(),
            pSpecifier->GetName(), 
            pSpecifier->GetTypeInfo(), 
            pSpecifier->GetDimension());
    }

    //printf("Added a struct\n");
}
