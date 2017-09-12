#pragma once

#include "StatementNode.h"

class ExpressionStatementNode : public StatementNode
{
public:
    ExpressionStatementNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location, 
        ASTNode* pExpr);

    ExpressionStatementNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location);
    
    const char* GetDebugName() override { return "ExpressionStatementNode"; }
    ASTNode* DuplicateNodeImpl() override;
    void PostProcessNodeImpl(OutputContext* pContext) override;
};
