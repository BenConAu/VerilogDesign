#include "EnumDefinitionNode.h"
#include "TypeCollection.h"
#include "StructSpecifierNode.h"
#include "TypeNode.h"
#include "VSharpCompilerContext.h"

EnumDefinitionNode::EnumDefinitionNode(
    ParserContext* pContext, 
    const YYLTYPE &location,
    int firstEnum) : ASTNode(pContext, location)
{
    _symIndex = -1;

    _enums.push_back(firstEnum);
}

void EnumDefinitionNode::VerifyNodeImpl()
{
    EnumTypeInfo* pNewType = new EnumTypeInfo(_symIndex, GetContext());
    GetContext()->GetTypeCollection()->AddEnumType(_symIndex, pNewType);

    for (size_t i = 0; i < _enums.size(); i++)
    {
        pNewType->AddMember(_enums[i]);
    }
}

