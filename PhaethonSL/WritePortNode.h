#pragma once

#include "ConstantNode.h"
#include "ASTNode.h"
#include "PSL.tab.h"

class WritePortNode : public ASTNode
{
public:
  WritePortNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pPort,
      ASTNode *pData);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "WritePortNode"; }

private:
  YYLTYPE _location;
};
