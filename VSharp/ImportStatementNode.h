#pragma once

#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"

class ImportStatementNode : public ASTNode
{
public:
    ImportStatementNode(PSLCompilerContext* pContext, const YYLTYPE &location) : ASTNode(pContext, location)
    {
        _literal = pContext->GetLastString();
    }

    void VerifyNodeImpl() override {}
    const char* GetDebugName() override { return "ImportStatementNode"; }

private:
    std::string _literal;
};
