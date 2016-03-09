#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"

class AssignmentNode : public ExpressionNode
{
public:
    AssignmentNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight);
    void VerifyNodeImpl() override;
    void ProcessNode() override;

protected:
    RegIndex CalcResultLocationImpl() override;
};
