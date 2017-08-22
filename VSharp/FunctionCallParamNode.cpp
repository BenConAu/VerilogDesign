#include "FunctionCallParamNode.h"
#include "FunctionDeclaratorNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"
#include "FunctionCallNode.h"

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
        return dynamic_cast<ExpressionNode*>(GetChild(0))->CalculateResult();        
    }
    else
    {
        return new ExpressionResult("\"" + _literal + "\"");
    }
}