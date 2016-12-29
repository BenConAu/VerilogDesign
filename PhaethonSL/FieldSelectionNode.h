#pragma once

#include "ExpressionNode.h"

class StructTypeInfo;

class FieldSelectionNode : public ExpressionNode
{
public:
    FieldSelectionNode(PSLCompilerContext* pContext, ASTNode* pExpr, bool fPointer, int symIndex);

    void VerifyNodeImpl() override;

    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "FieldSelectionNode"; }

private:
    int _fieldSymIndex;
    bool _fPointer;

    // Stored during Verification
    StructTypeInfo* _pStructTypeInfo;
};
