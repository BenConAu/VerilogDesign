#include "FieldSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "FunctionDeclaratorNode.h"
#include "PSLCompilerContext.h"

FieldSelectionNode::FieldSelectionNode(PSLCompilerContext *pContext, ASTNode *pExpr, bool fPointer, int symIndex) : ExpressionNode(pContext)
{
    AddNode(pExpr);

    _fieldSymIndex = symIndex;
    _fPointer = fPointer;
}

void FieldSelectionNode::VerifyNodeImpl()
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Should verify that the type exists
    TypeInfo *pTypeInfo = pLeft->GetTypeInfo();
    StructTypeInfo *pStructInfo;
    if (_fPointer)
    {
        PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(pTypeInfo);
        if (pPointerInfo == nullptr)
        {
            // Not using a pointer, bad for our health
            throw "Can only field select a pointer with arrow operator";
        }

        pStructInfo = dynamic_cast<StructTypeInfo*>(pPointerInfo->GetBaseType());
        if (pTypeInfo == nullptr)
        {
            // Not using a structure, bad for our health
            throw "Can only field select a pointer to a struct with arrow operator";
        }
    }
    else
    {
        pStructInfo = dynamic_cast<StructTypeInfo *>(pTypeInfo);
        if (pStructInfo == nullptr)
        {
            // Not using a structure, bad for our health
            throw "Can only field select a struct with dot operator";
        }
    }

    StructMember *pMember = pStructInfo->GetMember(_fieldSymIndex);

    // The type of this expression is the type of the member
    SetType(pMember->GetType());
}

ExpressionResult *FieldSelectionNode::CalculateResult()
{
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    if (pChildExpr != nullptr)
    {
        // Find the result of the child
        std::unique_ptr<ExpressionResult> childResult(pChildExpr->CalculateResult());

        // It needs to be something that we can select from
        if (childResult.get()->_operand.GetType() != OperandType::Constant && childResult.get()->_operand.GetType() != OperandType::Register)
        {
            printf("Type is %d\n", childResult.get()->_operand.GetType());
            throw "Can only field select a struct that has a this pointer in a register or a constant this pointer";
        }

        // Get the type of the child expression
        StructTypeInfo *pTypeInfo;
        if (!_fPointer)
        {
            pTypeInfo = dynamic_cast<StructTypeInfo *>(childResult.get()->_pTypeInfo);
        }
        else
        {
            PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(childResult.get()->_pTypeInfo);
            pTypeInfo = dynamic_cast<StructTypeInfo *>(pPointerInfo->GetBaseType());
        }

        // Since this is always a struct, the operand has a memory location in
        // it. This will now transform into an offset operation, which requires
        // that the path info be there so that we can get the register
        // that we associate with the path.
        if (childResult.get()->_pExprPath == nullptr)
        {
            throw "Need path info to field select";
        }

        // Find the path for the thing we are selecting from
        VariablePath *pPath = childResult.get()->_pExprPath;

        // Ensure the register - this will return the existing one if this is a pointer
        // or allocate one if this is a global.
        RegIndex index = pPath->EnsurePathRegister(GetTypedParent<FunctionDeclaratorNode>());

        // Create an offset operand using the index of the field
        Operand result(
            index,
            pTypeInfo,
            pTypeInfo->GetMember(_fieldSymIndex),
            GetContext());

        // Get the type of the member we are selecting
        StructMember *pMember = pTypeInfo->GetMember(_fieldSymIndex);

        // Find out the new path that we have for the expression
        VariablePath *pNewPath = GetContext()->_pathCollection.EnsurePath(pPath, pMember);

        return new ExpressionResult(pMember->GetType(), pNewPath, result);
    }
    else
    {
        throw "Can only field select identifiers";
    }
}
