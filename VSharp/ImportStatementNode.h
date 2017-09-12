#pragma once

#include "ExpressionNode.h"
#include "ParserContext.h"

class ImportStatementNode : public ASTNode
{
public:
    ImportStatementNode(ParserContext* pContext, const YYLTYPE &location);

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "ImportStatementNode"; }

private:
    std::string _literal;
    std::unique_ptr<ParserContext> _ImportedContext;
};
