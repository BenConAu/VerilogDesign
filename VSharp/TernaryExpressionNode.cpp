#include "TernaryExpressionNode.h"
#include "ParserContext.h"

TernaryExpressionNode::TernaryExpressionNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pTest,
    ASTNode *pTrue,
    ASTNode *pFalse) : ExpressionNode(pContext, location)
{
    AddNode(pTest);
    AddNode(pTrue);
    AddNode(pFalse);
}

TernaryExpressionNode::TernaryExpressionNode(
    ParserContext *pContext,
    const YYLTYPE &location) : ExpressionNode(pContext, location)
{
}

ASTNode* TernaryExpressionNode::DuplicateNodeImpl()
{
    return new TernaryExpressionNode(GetContext(), GetLocation());
}

void TernaryExpressionNode::VerifyNodeImpl()
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(0));
    RegisterTypeInfo *pTestType = dynamic_cast<RegisterTypeInfo *>(pTest->GetTypeInfo());
    if (pTestType == nullptr || pTestType->GetBitLength() != 1)
    {
        char result[1024];
        sprintf(
            result, 
            "Ternary expression needs boolean but has %s", 
            pTest->GetTypeInfo()->GetTypeName().c_str());

        GetContext()->ReportError(GetLocation(), result);
    }

    ExpressionNode *pTrue = dynamic_cast<ExpressionNode *>(GetChild(1));
    ExpressionNode *pFalse = dynamic_cast<ExpressionNode *>(GetChild(2));
    
    if (!pTrue->GetTypeInfo()->EqualType(pFalse->GetTypeInfo()))
    {
        GetContext()->ReportError(GetLocation(), "Ternary expression needs both sides to return same type");
    }

    SetType(pTrue->GetTypeInfo());
}

ExpressionResult *TernaryExpressionNode::CalculateResult()
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pTrue = dynamic_cast<ExpressionNode *>(GetChild(1));
    ExpressionNode *pFalse = dynamic_cast<ExpressionNode *>(GetChild(2));
    
    std::unique_ptr<ExpressionResult> testResult(pTest->TakeResult());
    std::unique_ptr<ExpressionResult> trueResult(pTrue->TakeResult());
    std::unique_ptr<ExpressionResult> falseResult(pFalse->TakeResult());
    
    char result[1024];
    sprintf(
        result, 
        "%s ? %s : %s", 
        testResult->GetString().c_str(),
        trueResult->GetString().c_str(),
        falseResult->GetString().c_str());

    return new ExpressionResult(result);
}

bool TernaryExpressionNode::IsLValue()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    // Bit selecting a valid L value will give an L value
    return pExpr->IsLValue();
}  
