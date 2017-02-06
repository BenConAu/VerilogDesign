#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

OpCodes::Enum OpCodeFromToken(int token);

class EmitNode : public ASTNode
{
  public:
    EmitNode(
        PSLCompilerContext *pContext,
        int opCodeToken,
        ASTNode *pExpr);

    void VerifyNodeImpl() override;

    void PostProcessNodeImpl() override;

    const char *GetDebugName() override { return "EmitNode"; }

  private:
    int _opCodeToken;
};