#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"
#include "PSL.tab.h"

OpCodes::Enum OpCodeFromToken(int token);

class EmitNode : public ASTNode
{
  public:
    EmitNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        int opCodeToken,
        ASTNode *pExpr1,
        ASTNode *pExpr2);

    void VerifyNodeImpl() override;

    void PostProcessNodeImpl() override;

    const char *GetDebugName() override { return "EmitNode"; }

  private:
    int _opCodeToken;
    YYLTYPE _location;
};