#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class IndexSelectionNode : public ExpressionNode
{
  public:
    IndexSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pPostFix,
        ASTNode *pIndex);

    IndexSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location);
    
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;
    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "IndexSelectionNode"; }
};
