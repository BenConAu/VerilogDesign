#include "FieldSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "FunctionDeclaratorNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

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

    if (pMember->GetType()->GetTypeClass() == TypeClass::Array)
    {
        // Accessing an array member returns a pointer
        ArrayTypeInfo* pArrayInfo = dynamic_cast<ArrayTypeInfo*>(pMember->GetType());
        SetType(GetContext()->_typeCollection.GetPointerType(pArrayInfo->GetBaseType()));
    }
    else
    {
        // The type of this expression is the type of the member
        SetType(pMember->GetType());
    }
}

ExpressionResult *FieldSelectionNode::CalculateResult()
{
    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Get the appropriate scope
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // Find the result of the child
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    // Get the structure type out of the child expression
    StructTypeInfo *pTypeInfo;
    if (!_fPointer)
    {
        // The expression of the child has to represent a struct
        pTypeInfo = dynamic_cast<StructTypeInfo *>(childResult->_pTypeInfo);
    }
    else
    {
        // The expression of the child has to represent a pointer to a struct
        PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(childResult->_pTypeInfo);
        pTypeInfo = dynamic_cast<StructTypeInfo *>(pPointerInfo->GetBaseType());
    }

    //    printf("Field select child operand type = %d\n", childOperand.GetType());

    // Remember if we allocate a register, and make sure we have a register
    // which represents the base address of the struct that we are referencing
    RegisterCollection *pRegCollection = nullptr;
    RegIndex baseRegister;
    bool fSetBaseRegister = false;

    // We need a register to offset. If we have one already then great, otherwise
    // we need to do the work to ensure that we have one for the path that arrived
    // here.
    if (childResult->GetOperandType() == OperandType::Constant)
    {
        //printf("Need to upgrade operand from constant\n");

        // Since the operand has a memory location in it, we figure that we must
        // have VariableInfo for when it was loaded. This will now transform into
        // an offset operation, which requires that the variable info be there so
        // that we can get the register that we associate with the path.
        VariableInfo *pInfo = childResult->_pVarInfo;
        if (pInfo == nullptr)
        {
            throw "Need variable info to field select";
        }

        // If we have a constant, then we need to make it into a register
        baseRegister = pInfo->EnsureRegister(pScope);
        fSetBaseRegister = true;
    }
    else if (
        childResult->GetOperandType() == OperandType::DerefRegisterOffset ||
        childResult->GetOperandType() == OperandType::DerefRegisterIndex)
    {
        //printf("Need to upgrade operand from offset operand\n");

        // Get register for our result
        pRegCollection = pScope->GetRegCollection();
        baseRegister = pRegCollection->AllocateRegister();
        fSetBaseRegister = true;
    }

    // See if the operand that came in requires us to load up the register
    if (fSetBaseRegister)
    {
        // Spit out the code to load said register
        pScope->GetContext()->OutputMovInstruction(
            Operand(baseRegister),
            childResult->GetOperands());
    }
    else
    {
        // It needs to be something that we can select from
        if (childResult->GetOperandType() != OperandType::Register)
        {
            printf("Type is %d\n", childResult->GetOperandType());
            throw "This pointer needs to be in a register by now";
        }

        // We can assume this is the register operand we want
        baseRegister = childResult->GetOperands()[0].GetRegIndex();
    }

    // Get the member of the struct that we are selecting
    StructMember *pMember = pTypeInfo->GetMember(_fieldSymIndex);

    Operand result;
    if (pMember->GetType()->GetTypeClass() == TypeClass::Array)
    {
        // If we have not allocated a register, then the register
        // is the one mapped to the struct. We need to allocate one
        // now because we don't want to fiddle with that register.
        RegIndex resultRegister = baseRegister;
        if (pRegCollection == nullptr)
        {
            pRegCollection = pScope->GetRegCollection();        
            resultRegister = pRegCollection->AllocateRegister();
        }

        // This operation will basically just offset the register
        // which has the address in it to create the pointer to
        // the start of the member.
        result = Operand(resultRegister);

        // Spit out the code to add to said register
        pScope->GetContext()->OutputInstruction(
            OpCodes::AddRRC,
            result,
            Operand(baseRegister),
            Operand((int)pTypeInfo->GetOffset(pMember->GetSymbolIndex())));
    }
    else
    {
        // Create an offset operand using the index of the field
        result = Operand(
            baseRegister,
            pTypeInfo,
            pMember,
            GetContext());
    }

    if (pRegCollection != nullptr)
    {
        return new ExpressionResult(pMember->GetType(), result, pRegCollection);
    }
    else
    {
        return new ExpressionResult(pMember->GetType(), result);
    }
}
