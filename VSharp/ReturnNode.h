#pragma once

#include "ASTNode.h"

class ReturnNode : public ASTNode
{
  public:
    ReturnNode(
      ParserContext *pContext, 
      const YYLTYPE &location, 
      ASTNode *pChild) : ASTNode(pContext, location)
    {
        AddNode(pChild);
    }

    ASTNode* DuplicateNode() override;
    const char* GetDebugName() override { return "ReturnNode"; }
};
