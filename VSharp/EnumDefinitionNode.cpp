#include "EnumDefinitionNode.h"
#include "TypeCollection.h"
#include "StructSpecifierNode.h"
#include "TypeNode.h"
#include "ParserContext.h"

EnumDefinitionNode::EnumDefinitionNode(
    ParserContext* pContext, 
    const YYLTYPE &location,
    EnumItem firstEnum) : ASTNode(pContext, location)
{
    _symIndex = -1;

    _enums.push_back(firstEnum);
}

void EnumDefinitionNode::VerifyNodeImpl()
{
    if (GetContext()->GetTypeCollection()->GetEnumType(_symIndex) != nullptr)
    {
        GetContext()->ReportError(
            GetLocation(), 
            "Dude somebody took that name %s, cannot make an enum with it", 
            GetContext()->GetSymbolString(_symIndex).c_str());
    }

    EnumTypeInfo* pNewType = new EnumTypeInfo(_symIndex, GetContext());
    GetContext()->GetTypeCollection()->AddEnumType(_symIndex, pNewType);

    for (size_t i = 0; i < _enums.size(); i++)
    {
        pNewType->AddMember(_enums[i]);
    }
}

