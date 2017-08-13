#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class BitSelectionNode : public ExpressionNode
{
  public:
    BitSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pPostFix,
        int i1,
        int i2);

    void VerifyNodeImpl() override;

    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "BitSelectionNode"; }

  private:
    YYLTYPE _location;
    int _i1;
    int _i2;
};
