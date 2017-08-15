#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class StructTypeInfo;

class FieldSelectionNode : public ExpressionNode
{
  public:
    FieldSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pExpr,
        bool fPointer,
        int symIndex);

    void VerifyNodeImpl() override;

    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "FieldSelectionNode"; }

  private:
    int _fieldSymIndex;
    bool _fPointer;

    // Stored during Verification
    StructTypeInfo *_pStructTypeInfo;
};
