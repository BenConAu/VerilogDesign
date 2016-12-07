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
    if (pLeft == nullptr)
    {
        throw "Can only field select expressions";
    }

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

        pStructInfo = dynamic_cast<StructTypeInfo *>(pPointerInfo->GetBaseType());
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
    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Find the result of the child
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->CalculateResult());

    // Get the structure type out of the child expression
    StructTypeInfo *pTypeInfo;
    if (!_fPointer)
    {
        // The expression of the child has to represent a struct
        pTypeInfo = dynamic_cast<StructTypeInfo *>(childResult.get()->_pTypeInfo);
    }
    else
    {
        // The expression of the child has to represent a pointer to a struct
        PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(childResult.get()->_pTypeInfo);
        pTypeInfo = dynamic_cast<StructTypeInfo *>(pPointerInfo->GetBaseType());
    }

    // Since this is always a struct, the operand has a memory location in
    // it. This will now transform into an offset operation, which requires
    // that the path info be there so that we can get the register
    // that we associate with the path.
    VariablePath *pPath = childResult->_pExprPath;
    if (pPath == nullptr)
    {
        throw "Need path info to field select";
    }

    // We will base our operation on the child operand
    Operand childOperand = childResult->_operand;

    // We need a register to offset. If we have one already then great, otherwise
    // we need to do the work to ensure that we have one for the path that arrived
    // here.
    if (childResult->_operand.GetType() == OperandType::Constant)
    {
        // Get the appropriate scope
        FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

        // If we have a constant, then we need to make it into a register
        RegIndex pathIndex = pPath->EnsurePathRegister(pScope);

        // An operand that represents the variable
        Operand varOperand(pPath->GetVariableInfo(), pScope->GetContext());
        Operand regOperand(pathIndex);

        // Spit out the code to load said register
        pScope->GetContext()->OutputMovInstruction(
            regOperand,
            varOperand);

        // This is what we consider the child operand now
        childOperand = regOperand;
    }

    // It needs to be something that we can select from
    if (childOperand.GetType() != OperandType::Register)
    {
        printf("Type is %d\n", childOperand.GetType());
        throw "This pointer needs to be in a register by now";
    }

    // Get the member of the struct that we are selecting
    StructMember *pMember = pTypeInfo->GetMember(_fieldSymIndex);

    // Create an offset operand using the index of the field
    Operand result(
        childOperand.GetRegIndex(),
        pTypeInfo,
        pMember,
        GetContext());

    // Find out the new path that we have for the expression
    VariablePath *pNewPath = GetContext()->_pathCollection.EnsurePath(pPath, pMember);

    return new ExpressionResult(pMember->GetType(), pNewPath, result);
}
