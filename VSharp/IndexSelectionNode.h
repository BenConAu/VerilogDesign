#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class IndexSelectionNode : public ExpressionNode
{
  public:
    IndexSelectionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pPostFix,
        ASTNode *pIndex);

    IndexSelectionNode(
        ParserContext *pContext,
        const YYLTYPE &location);
    
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "IndexSelectionNode"; }
    VariableInfo* IsVariableExpression() override;
};
