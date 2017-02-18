#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"
#include "PSL.tab.h"

class EmitNode : public ASTNode
{
  public:
    EmitNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        OpCode opCode,
        ASTNode *pExpr1,
        ASTNode *pExpr2);

    void VerifyNodeImpl() override;

    void PostProcessNodeImpl() override;

    const char *GetDebugName() override { return "EmitNode"; }

  private:
    OpCode _opCode;
    YYLTYPE _location;
};