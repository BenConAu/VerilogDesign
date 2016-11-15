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

ExpressionResult* FieldSelectionNode::CalculateResult()
{
    ExpressionNode* pChildExpr = dynamic_cast<ExpressionNode*>(GetChild(0));
    if (pChildExpr != nullptr)
    {
        // Find the result of the child
        std::unique_ptr<ExpressionResult> childResult(pChildExpr->CalculateResult());

        // It needs to be something that we can select from
        if (childResult.get()->_operand._type != OperandType::Memory)
        {
            throw "Can only field select a memory struct";
        }

        // We have a variable in there somewhere
        VariableInfo* pVarInfo = childResult.get()->_operand._pVarInfo;
        StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
        if (pTypeInfo == nullptr)
        {
            throw "Can only field select a struct";
        }

        // It is a register already, so return that
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();
        RegIndex regIndex = pVarInfo->GetRegIndex(pScope);
        printf("mov r%d, %s\n", regIndex, childResult.get()->_operand.GetOperand(GetContext()).c_str());

        Operand result(regIndex, pVarInfo, pTypeInfo->GetMember(_fieldSymIndex));

        return new ExpressionResult(result);
    }
    else
    {
        throw "Can only field select identifiers";
    }
}
