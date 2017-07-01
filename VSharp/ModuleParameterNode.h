#pragma once

#include "ASTNode.h"

class ModuleParameterNode : public ASTNode
{
public:
    ModuleParameterNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex) : ASTNode(pContext)
    {
        AddNode(pType);
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "ModuleParameterNode"; }

private:
    int _symIndex;
};
