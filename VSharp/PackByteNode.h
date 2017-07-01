#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class PackByteNode : public ASTNode
{
public:
  PackByteNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pDest,
      ASTNode *pSrc,
      ASTNode *pIndex);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "PackByteNode"; }

private:
  YYLTYPE _location;
};
