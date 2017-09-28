#include "FunctionCallParamNode.h"
#include "FunctionDeclaratorNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"
#include "FunctionCallNode.h"

FunctionCallParamNode::FunctionCallParamNode(ParserContext* pContext, const YYLTYPE &location, bool fOut, ASTNode* pExpr) : ExpressionNode(pContext, location)
{
    AddNode(pExpr);
    _fOut = fOut;
}

FunctionCallParamNode::FunctionCallParamNode(ParserContext* pContext, const YYLTYPE &location) : ExpressionNode(pContext, location)
{
    _fOut = false;
    _literal = pContext->GetLastString();
}

FunctionCallParamNode::FunctionCallParamNode(
    ParserContext* pContext, 
    const YYLTYPE &location,
    bool fOut,
    const std::string& literal
    ) : ExpressionNode(pContext, location)
{
    _fOut = fOut;
    _literal = literal;
}

ASTNode* FunctionCallParamNode::DuplicateNodeImpl(DuplicateType type)
{
    return new FunctionCallParamNode(GetContext(), GetLocation(), _fOut, _literal);
}

void FunctionCallParamNode::VerifyNodeImpl()
{
    if (_fOut)
    {
        ExpressionNode* pExpr = dynamic_cast<ExpressionNode*>(GetChild(0));

        // Needs to refer to an existing variable
        if (pExpr->IsVariableExpression() == nullptr)
        {
            GetContext()->ReportError(GetLocation(), "Invalid expression used as out param in function");
        }
    }
}

ExpressionResult *FunctionCallParamNode::CalculateResult()
{
    if (_literal.length() == 0)
    {
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(GetChild(0));
        
        return pChild->TakeResult();
    }
    else
    {
        return new ExpressionResult("\"" + _literal + "\"");
    }
}