#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, int symIndex);
    void VerifyNodeImpl() override;
    void PreProcessNodeImpl() override;
    void ProcessWrite(RegIndex valueIndex) override;
    int GetSymbolIndex() const { return _symIndex; }

protected:
    RegIndex CalcResultLocationImpl() override;

private:
    int _symIndex;
};
