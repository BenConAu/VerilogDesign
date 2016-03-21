#include "FieldSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "FunctionDeclaratorNode.h"
#include "PSLCompilerContext.h"

FieldSelectionNode::FieldSelectionNode(PSLCompilerContext* pContext, ASTNode* pExpr, int symIndex) : ExpressionNode(pContext)
{
    AddNode(pExpr);

    _fieldSymIndex = symIndex;
}

void FieldSelectionNode::VerifyNodeImpl()
{
    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

    // Should verify that the type exists
    TypeInfo* pExpressionInfo = pLeft->GetType();

    if (pExpressionInfo->IsBasic())
    {
        throw "Cannot field select a basic type";
    }

    StructTypeInfo* pStructInfo = dynamic_cast<StructTypeInfo*>(pExpressionInfo);
    StructMember* pMember = pStructInfo->GetMember(_fieldSymIndex);

    // The type of this expression is the type of the member
    SetType(pMember->GetType());
}

ExpressionResult FieldSelectionNode::CalcResultImpl()
{
    ExpressionNode* pChildExpr = dynamic_cast<ExpressionNode*>(GetChild(0));
    if (pChildExpr != nullptr)
    {
        // Find the result of the child
        ExpressionResult childResult = pChildExpr->GetResult();

        // It needs to be something that we can select from
        if (childResult._type != ResultType::Memory)
        {
            throw "Can only field select a memory struct";
        }

        // We have a variable in there somewhere
        VariableInfo* pVarInfo = childResult._pVarInfo;
        StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
        if (pTypeInfo == nullptr)
        {
            throw "Can only field select a struct";
        }

        // It is a register already, so return that
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();
        RegIndex regIndex = pVarInfo->GetRegIndex(pScope);
        printf("mov r%d, %s\n", regIndex, childResult.GetOperand(GetContext()).c_str());

        ExpressionResult result(regIndex, pVarInfo, pTypeInfo->GetMember(_fieldSymIndex));

        return result;
    }
    else
    {
        throw "Can only field select identifiers";
    }
}