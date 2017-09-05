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

    void PostProcessNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;
    
    const char *GetDebugName() override { return "TransitionNode"; }

private:
    int _symIndex;
};