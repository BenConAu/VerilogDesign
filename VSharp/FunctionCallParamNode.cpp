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

    FunctionCallNode* pCall = GetTypedParent<FunctionCallNode>();
    FunctionDeclaratorNode* pDeclNode = pCall->GetDeclarator();
    
    // TODO: Make a mapping from the variable here to the one in the function definition
}

ExpressionResult *FunctionCallParamNode::CalculateResult()
{
    return dynamic_cast<ExpressionNode*>(GetChild(0))->CalculateResult();
}