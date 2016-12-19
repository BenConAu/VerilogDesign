#pragma once

#include "ASTNode.h"
#include "PSLCompilerContext.h"

class VariableDeclarationNode : public ASTNode
{
  public:
    VariableDeclarationNode(
        PSLCompilerContext *pContext,
        ASTNode *pType,
        int symIndex,
        ASTNode *pInitExpr);

    void PreVerifyNodeImpl() override;
    void PostProcessNodeImpl() override;
    const char *GetDebugName() override { return "VariableDeclarationNode"; }

  private:
    int _symIndex;
    bool _fGlobal;
};
