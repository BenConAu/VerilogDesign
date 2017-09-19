#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class ParserContext;
class TypeInfo;

class EnumDefinitionNode : public ASTNode
{
public:
    EnumDefinitionNode(
        ParserContext* pContext,
        const YYLTYPE &location,
        EnumItem firstEnum);

    void SetIdentifier(int symIndex) { _symIndex = symIndex; }
    void AddEnum(EnumItem item) { _enums.push_back(item); }
    int GetSymbolIndex() { return _symIndex; }
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "EnumDefinitionNode"; }

private:
    int _symIndex;
    std::vector<EnumItem> _enums;
};
