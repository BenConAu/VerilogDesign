#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class DriveListDefinitionNode : public ASTNode
{
public:
  DriveListDefinitionNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pList);

  void VerifyNodeImpl() override;
  bool PreProcessNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "DriveListDefinitionNode"; }

private:
  YYLTYPE _location;
};
