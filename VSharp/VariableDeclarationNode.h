#pragma once

#include "ASTNode.h"
#include "PSLCompilerContext.h"
#include "VSharp.tab.h"

class VariableDeclarationNode : public ASTNode
{
public:
  VariableDeclarationNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pType,
      int symIndex,
      ASTNode *pInitExpr);

  void PreVerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "VariableDeclarationNode"; }

private:
  int _symIndex;
  YYLTYPE _location;
  bool _fGlobal;
};
