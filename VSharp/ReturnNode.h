#pragma once

#include "VSharpCompilerContext.h"

class ReturnNode : public ASTNode
{
  public:
    ReturnNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location, 
      ASTNode *pChild) : ASTNode(pContext, location)
    {
        AddNode(pChild);
    }

    ASTNode* DuplicateNode() override;
    const char* GetDebugName() override { return "ReturnNode"; }
};
