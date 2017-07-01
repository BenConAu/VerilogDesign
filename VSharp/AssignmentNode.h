#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"
#include "VSharp.tab.h"

class AssignmentNode : public ASTNode
{
public:
  AssignmentNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pLeft,
      ASTNode *pRight);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "AssignmentNode"; }

private:
  YYLTYPE _location;
};
