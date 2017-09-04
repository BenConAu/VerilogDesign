#include "FunctionCallParamNode.h"
#include "FunctionDeclaratorNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"
#include "FunctionCallNode.h"

ASTNode* FunctionCallParamNode::DuplicateNodeImpl()
{
    return new FunctionCallParamNode(GetContext(), GetLocation(), _fOut, _literal);
}

void FunctionCallParamNode::VerifyNodeImpl()
{
    if (_fOut)
    {
        IdentifierNode* pIdent = dynamic_cast<IdentifierNode*>(GetChild(0));

        // Needs to refer to an existing variable
        if (pIdent == nullptr)
        {
            throw "Unknown identifier used as out param in function";
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