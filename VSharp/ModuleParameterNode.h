#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class ModuleParameterNode : public ASTNode
{
public:
    ModuleParameterNode(
        PSLCompilerContext* pContext,
        const YYLTYPE &location,
        ASTNode* pType, 
        int symIndex, 
        bool fOut) : ASTNode(pContext)
    {
        AddNode(pType);
        _location = location;
        _symIndex = symIndex;
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    void PostProcessNodeImpl() override;
    const char* GetDebugName() override { return "ModuleParameterNode"; }
    int GetSymbolIndex() const { return _symIndex; }

private:
    YYLTYPE _location;
    int _symIndex;
    bool _fOut;
};
