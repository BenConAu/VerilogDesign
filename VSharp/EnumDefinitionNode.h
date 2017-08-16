#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class PSLCompilerContext;
class TypeInfo;

// Indicates a member of a struct
class EnumDefinitionNode : public ASTNode
{
public:
    EnumDefinitionNode(
        PSLCompilerContext* pContext,
        const YYLTYPE &location,
        int firstEnum);

    void SetIdentifier(int symIndex) { _symIndex = symIndex; }
    void AddEnum(int symIndex) { _enums.push_back(symIndex); }
    int GetSymbolIndex() { return _symIndex; }
    void PreProcessNodeImpl() override;
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "EnumDefinitionNode"; }

private:
    int _symIndex;
    std::vector<int> _enums;
};
