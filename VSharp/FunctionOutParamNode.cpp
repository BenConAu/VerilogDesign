#include "FunctionOutParamNode.h"
#include "FunctionDeclaratorNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

void FunctionOutParamNode::VerifyNodeImpl()
{
    IdentifierNode* pIdent = dynamic_cast<IdentifierNode*>(GetChild(0));

    // Needs to refer to an existing variable
    if (pIdent == nullptr)
    {
        throw "Unknown identifier used as out param in function";
    }

    // TODO: Make a mapping from the variable here to the one in the function definition
}

ExpressionResult *FunctionOutParamNode::CalculateResult()
{
    return dynamic_cast<ExpressionNode*>(GetChild(0))->CalculateResult();
}