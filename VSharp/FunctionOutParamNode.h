#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class FunctionOutParamNode : public ASTNode
{
public:
    FunctionOutParamNode(PSLCompilerContext* pContext, const YYLTYPE &location, int symIndex) : ASTNode(pContext)
    {
        _symIndex = symIndex;
        _location = location;
    }

    void VerifyNodeImpl() override;
    void PreProcessNodeImpl() override;
    const char* GetDebugName() override { return "FunctionOutParamNode"; }
    int GetSymbolIndex() const { return _symIndex; }

private:
    YYLTYPE _location;
    int _symIndex;
};
