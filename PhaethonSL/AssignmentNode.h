#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"

class AssignmentNode : public ExpressionNode
{
public:
    AssignmentNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight);
    void VerifyNodeImpl() override;
    void PostProcessNodeImpl() override;

protected:
    ExpressionResult CalcResultImpl() override;
};
