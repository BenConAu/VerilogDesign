#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"

class TransitionNode : public ASTNode
{
  public:
    TransitionNode(
        PSLCompilerContext *pContext, 
        const YYLTYPE &location,
        int symIndex) : ASTNode(pContext, location)
    {
        _symIndex = symIndex;
    }

    void PostProcessNodeImpl(OutputContext* pContext) override;
    ASTNode* DuplicateNodeImpl() override;
    
    const char *GetDebugName() override { return "TransitionNode"; }

private:
    int _symIndex;
};