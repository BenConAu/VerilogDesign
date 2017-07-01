#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class SaveRegistersNode : public ASTNode
{
public:
  SaveRegistersNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location,
    ASTNode *pCompound);

  void VerifyNodeImpl() override;
  void ProcessNode() override;

  const char *GetDebugName() override { return "SaveRegistersNode"; }

private:
  YYLTYPE _location;
};
