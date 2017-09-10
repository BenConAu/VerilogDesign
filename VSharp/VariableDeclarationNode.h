#pragma once

#include "ASTNode.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"

class TypeNode;

class VariableDeclarationNode : public ASTNode
{
public:
  VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    const UIntConstant &arraySize,
    ASTNode *pInitExpr);

  VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr);

  void PreVerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "VariableDeclarationNode"; }
  TypeNode* GetTypeNode();

private:
  int _symIndex;
  int _arraySize;
  YYLTYPE _location;
};
