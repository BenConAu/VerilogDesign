#include "ImportStatementNode.h"
#include "ParserContext.h"

ImportStatementNode::ImportStatementNode(ParserContext* pContext, const YYLTYPE &location) : ASTNode(pContext, location)
{
    _literal = pContext->GetLastString();
}

void ImportStatementNode::VerifyNodeImpl()  
{
    _ImportedContext.reset(new ParserContext(_literal.c_str(), GetContext()->GetCompiler()));
    _ImportedContext->Parse();
}
