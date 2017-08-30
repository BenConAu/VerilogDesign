#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class StaticTypeInfo;
class StructTypeInfo;

class FieldSelectionNode : public ExpressionNode
{
  public:
    FieldSelectionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pExpr,
        int symIndex);

    void VerifyNodeImpl() override;

    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "FieldSelectionNode"; }

  private:
    int _fieldSymIndex;

    // Stored during Verification
    StaticTypeInfo *_pStaticTypeInfo;
    StructTypeInfo *_pStructTypeInfo;
};
