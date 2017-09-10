#pragma once

#include "ASTNode.h"

class StructSpecifierNode : public ASTNode
{
public:
    StructSpecifierNode(PSLCompilerContext* pContext, const YYLTYPE &location, ASTNode* pTypeNode);
    void SetName(int symIndex);
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "StructSpecifierNode"; }

private:
    int _symIndex;
};
