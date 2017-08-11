#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"

class TransitionNode : public ASTNode
{
  public:
    TransitionNode(
        PSLCompilerContext *pContext,
        int symIndex) : ASTNode(pContext)
    {
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
    }

    void PreProcessNodeImpl() override;

    const char *GetDebugName() override { return "TransitionNode"; }

private:
    int _symIndex;
};