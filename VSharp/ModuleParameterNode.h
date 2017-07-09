#pragma once

#include "ASTNode.h"

class ModuleParameterNode : public ASTNode
{
public:
    ModuleParameterNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex, bool fOut) : ASTNode(pContext)
    {
        AddNode(pType);
        _symIndex = symIndex;
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    void PreProcessNodeImpl() override;
    const char* GetDebugName() override { return "ModuleParameterNode"; }
    int GetSymbolIndex() const { return _symIndex; }

private:
    int _symIndex;
    bool _fOut;
};
