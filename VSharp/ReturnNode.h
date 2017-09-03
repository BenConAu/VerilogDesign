#pragma once

#include "VSharpCompilerContext.h"

class ReturnNode : public ASTNode
{
  public:
    ReturnNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location, 
      ASTNode *pChild) : ASTNode(pContext)
    {
        AddNode(pChild);

        _location = location;
    }

    ASTNode* DuplicateNodeImpl() override;
    const char* GetDebugName() override { return "ReturnNode"; }
    
  private:
    YYLTYPE _location;
};
