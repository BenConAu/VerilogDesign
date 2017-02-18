#include "IndexSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "FunctionDeclaratorNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

IndexSelectionNode::IndexSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPostFix,
    ASTNode *pIndex) : ExpressionNode(pContext)
{
    AddNode(pPostFix);
    AddNode(pIndex);

    _location = location;
}

void IndexSelectionNode::VerifyNodeImpl()
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    if (pLeft == nullptr)
    {
        GetContext()->ReportError(_location, "Can only index select expressions");
    }

    // Should verify that the type exists
    TypeInfo *pTypeInfo = pLeft->GetTypeInfo();
    //printf("Type in index select verify is %s\n", pTypeInfo->DebugPrint().c_str());
    PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(pTypeInfo);
    if (pPointerInfo == nullptr)
    {
        // Not using a pointer, bad for our health
        GetContext()->ReportError(_location, "Can only index select a pointer");
    }

    ExpressionNode *pIndex = dynamic_cast<ExpressionNode *>(GetChild(1));
    if (pIndex == nullptr)
    {
        GetContext()->ReportError(_location, "Can only index with an expression");
    }

    TypeInfo *pIndexTypeInfo = pIndex->GetTypeInfo();
    BasicTypeInfo *pBasicInfo = dynamic_cast<BasicTypeInfo *>(pIndexTypeInfo);
    if (pBasicInfo == nullptr)
    {
        GetContext()->ReportError(_location, "Can only index with a basic type");
    }

    if (pBasicInfo->GetTypeToken() != WORD_TOKEN)
    {
        GetContext()->ReportError(_location, "Can only index with a word");
    }

    // The type of this expression is the type of the pointer
    SetType(pPointerInfo->GetBaseType());
}

ExpressionResult *IndexSelectionNode::CalculateResult()
{
    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pIndexExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    // Get the appropriate scope
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // Find the result of the child
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());
    std::unique_ptr<ExpressionResult> indexResult(pIndexExpr->TakeResult());

    // Get the type out of the child expression
    TypeInfo *pTypeInfo = pChildExpr->GetTypeInfo();
    PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(pTypeInfo);

    // Make the result object so we can build on it
    ExpressionResult *pResult = new ExpressionResult(pScope->GetRegCollection());

    // Allocate a register for the first operand
    //printf("Allocating a register for IndexSelectionNode\n");
    RegIndex resultIndex = pScope->GetRegCollection()->AllocateRegister();

    // Fill the register with the address
    GetContext()->OutputMovInstruction(
        Operand(resultIndex),
        *childResult.get());

    // Create an operand with this register
    Operand resultOperand(
        resultIndex,
        pPointerInfo,
        GetContext());        

    pResult->AddOperand(resultOperand, true);

    if (indexResult->GetResultType() != ExpressionResultType::Register)
    {
        // If we don't have a register for the second operand then allocate it
        //printf("Allocating a second register for IndexSelectionNode\n");
        RegIndex sizeReg = pScope->GetRegCollection()->AllocateRegister();
        Operand sizeOperand(sizeReg);

        // Move whatever we do have into that register
        GetContext()->OutputMovInstruction(
            sizeOperand,
            *indexResult.get());

        // And that is our other operand
        pResult->AddOperand(sizeOperand, true);
    }
    else
    {
        // Just reuse what we have
        pResult->AddOperand(indexResult->GetOperand(0), false);
    }

    return pResult;
}
