#pragma once

#include "ASTNode.h"

class TransitionNode : public ASTNode
{
  public:
    TransitionNode(
        ParserContext *pContext, 
        const YYLTYPE &location,
        int symIndex) : ASTNode(pContext, location)
    {
        _symIndex = symIndex;
    }

    void PostProcessNodeImpl(OutputContext* pContext) override;
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;
    
    const char *GetDebugName() override { return "TransitionNode"; }

private:
    int _symIndex;
};