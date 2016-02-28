#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, int symIndex);
    void VerifyNodeImpl() override;
    void PreProcessNodeImpl() override;

protected:
    RegIndex CalcResultRegisterImpl() override;

private:
    int _symIndex;
};
