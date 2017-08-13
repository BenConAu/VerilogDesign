#include "BitSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"

BitSelectionNode::BitSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPostFix,
    int i1,
    int i2) : ExpressionNode(pContext)
{
    AddNode(pPostFix);

    _location = location;
    _i1 = i1;
    _i2 = i2;
}

void BitSelectionNode::VerifyNodeImpl()
{
    // TODO: Range check
}

ExpressionResult *BitSelectionNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    std::unique_ptr<ExpressionResult> exprResult(pExpr->TakeResult());

    char result[1024];
    sprintf(
        result, 
        "%s[%d:%d]", 
        exprResult->GetString().c_str(),
        _i1,
        _i2);

    return new ExpressionResult(result);
}
