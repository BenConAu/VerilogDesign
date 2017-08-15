#include "IndexSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"

IndexSelectionNode::IndexSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPostFix,
    ASTNode *pIndex) : ExpressionNode(pContext, location)
{
    AddNode(pPostFix);
    AddNode(pIndex);
}

void IndexSelectionNode::VerifyNodeImpl()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    if (pExpr == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Can only index select expressions");
    }
    else
    {
        // Should verify that the type exists
        TypeInfo *pTypeInfo = pExpr->GetTypeInfo();
        RegisterTypeInfo *pRegInfo = dynamic_cast<RegisterTypeInfo*>(pTypeInfo);

        if (pRegInfo == nullptr)
        {
            ArrayTypeInfo *pArrayInfo = dynamic_cast<ArrayTypeInfo*>(pTypeInfo);
            if (pArrayInfo == nullptr)
            {
                GetContext()->ReportError(GetLocation(), "Can only index select registers or arrays");                
            }
            else
            {
                SetType(pArrayInfo->GetBaseType());
            }
        }
        else
        {
            // Index a register and you get a single bit
            SetType(GetContext()->_typeCollection.GetRegisterType(1));
        }
    }
}

ExpressionResult *IndexSelectionNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pIndex = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> exprResult(pExpr->TakeResult());
    std::unique_ptr<ExpressionResult> indexResult(pIndex->TakeResult());
    
    char result[1024];
    sprintf(
        result, 
        "%s[%s]", 
        exprResult->GetString().c_str(),
        indexResult->GetString().c_str());

    return new ExpressionResult(result);
}
