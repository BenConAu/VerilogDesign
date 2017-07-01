#pragma once

#include "PSLCompilerContext.h"
#include "OperatorNode.h"
#include "VSharp.tab.h"

class OffsetNode : public OperatorNode
{
  public:
    OffsetNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pType,
        ASTNode *pIdent,
        ASTNode *pExpr);

    void VerifyNodeImpl() override;
    const char *GetDebugName() override { return "OffsetNode"; }

  private:
    YYLTYPE _location;
};