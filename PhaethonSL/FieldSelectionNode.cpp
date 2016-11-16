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

        // Get the type of the child expression
        StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(childResult.get()->_pTypeInfo);
        if (pTypeInfo == nullptr)
        {
            throw "Can only field select a struct";
        }

        // Since this is always a struct, the operand has a memory location in
        // it. This will now transform into an offset operation, which requires
        // that the variable info be there so that we can get the register
        // that we associate with the struct pointer.
        if (childResult.get()->_pVarInfo == nullptr)
        {
            throw "Need variable info to field select";
        }

        // We need the scope to ensure register
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();

        // It is a register already, so return that
        VariableInfo* pVarInfo = childResult.get()->_pVarInfo;
        Operand result(
            pVarInfo->EnsureVariableRegister(pScope), 
            pVarInfo, 
            pTypeInfo->GetMember(_fieldSymIndex), 
            GetContext()
            );

        // Get the type of the member we are selecting
        StructMember* pMember = pTypeInfo->GetMember(_fieldSymIndex);

        return new ExpressionResult(pMember->GetType(), result);
    }
    else
    {
        throw "Can only field select identifiers";
    }
}
