#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class StaticTypeInfo;
class StructTypeInfo;

class FieldSelectionNode : public ExpressionNode
{
  public:
    FieldSelectionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pExpr,
        int symIndex);

    FieldSelectionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        int symIndex,
        StaticTypeInfo *pStaticTypeInfo,
        StructTypeInfo *pStructTypeInfo);
              
    void VerifyNodeImpl() override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "FieldSelectionNode"; }
    ASTNode* DuplicateNodeImpl() override;
    bool IsLValue() override;    
    
  private:
    int _fieldSymIndex;

    // Stored during Verification
    StaticTypeInfo *_pStaticTypeInfo;
    StructTypeInfo *_pStructTypeInfo;
};
