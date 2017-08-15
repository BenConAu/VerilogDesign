#include "GlomExpressionNode.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"

GlomExpressionNode::GlomExpressionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pExprList) : ExpressionNode(pContext, location)
{
    AddNode(pExprList);
}

void GlomExpressionNode::VerifyNodeImpl()
{
}

ExpressionResult *GlomExpressionNode::CalculateResult()
{
    // Get the child expression
/*    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
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

    // Create an operand with this register - it has a base register
    // with the size of the type being pointed to encoded in it.
    Operand resultOperand(
        resultIndex,
        pPointerInfo,
        GetContext());        

    // This will be the first part of the expression
    pResult->AddOperand(resultOperand, true);

    if (indexResult->GetResultType() != ExpressionResultType::Register)
    {
        //printf("IndexSelectionNode in not register\n");

        // If we don't have a register for the second operand then allocate it
        RegIndex indexReg = pScope->GetRegCollection()->AllocateRegister();
        Operand indexOperand(indexReg);

        // Move whatever we do have into that register
        GetContext()->OutputMovInstruction(
            indexOperand,
            *indexResult.get());

        // And that is our other operand
        pResult->AddOperand(indexOperand, true);
    }
    else
    {
        //printf("IndexSelectionNode in register\n");

        // Just reuse what we have
        pResult->AddOperand(indexResult->GetOperand(0), false);
    }

    //printf("IndexSelectionNode returning result: %s\n", pResult->DebugPrint().c_str());

    return pResult;*/
    return nullptr;
}
