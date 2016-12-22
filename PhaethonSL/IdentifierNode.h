#pragma once

#include "ExpressionNode.h"
#include "PSL.tab.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, const YYLTYPE& location, int symIndex);
    void VerifyNodeImpl() override;
    int GetSymbolIndex() const { return _symIndex; }
    VariableInfo* GetVariableInfo();
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "IdentifierNode"; }

private:
    int _symIndex;
    YYLTYPE _location;
};
