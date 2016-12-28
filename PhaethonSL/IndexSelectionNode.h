#pragma once

#include "ExpressionNode.h"
#include "PSL.tab.h"

class IndexSelectionNode : public ExpressionNode
{
  public:
    IndexSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pPostFix,
        ASTNode *pIndex);

    void VerifyNodeImpl() override;

    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "IndexSelectionNode"; }

  private:
    YYLTYPE _location;
    int _fieldSymIndex;
    bool _fPointer;
};
