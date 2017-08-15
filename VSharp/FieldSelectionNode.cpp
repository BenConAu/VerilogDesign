#include "FieldSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "IdentifierNode.h"

FieldSelectionNode::FieldSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pExpr,
    bool fPointer,
    int symIndex) : ExpressionNode(pContext, location)
{
    AddNode(pExpr);

    _fieldSymIndex = symIndex;
    _fPointer = fPointer;

    _pStructTypeInfo = nullptr;
}

void FieldSelectionNode::VerifyNodeImpl()
{/*
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    if (pLeft == nullptr)
    {
        GetContext()->ReportError(_location, "Can only field select expressions");
    }

    // Should verify that the type exists
    TypeInfo *pTypeInfo = pLeft->GetTypeInfo();
    if (_fPointer)
    {
        PointerTypeInfo *pPointerInfo = dynamic_cast<PointerTypeInfo *>(pTypeInfo);
        if (pPointerInfo == nullptr)
        {
            // Not using a pointer, bad for our health
            GetContext()->ReportError(_location, "Can only field select a pointer with arrow operator");
        }

        _pStructTypeInfo = dynamic_cast<StructTypeInfo *>(pPointerInfo->GetBaseType());
        if (_pStructTypeInfo == nullptr)
        {
            // Not using a structure, bad for our health
            GetContext()->ReportError(_location, "Can only field select a pointer to a struct with arrow operator");
        }
    }
    else
    {
        _pStructTypeInfo = dynamic_cast<StructTypeInfo *>(pTypeInfo);
        if (_pStructTypeInfo == nullptr)
        {
            // Not using a structure, bad for our health
            GetContext()->ReportError(_location, "Can only field select a struct with dot operator");
        }
    }

    // If the left part is a variable identifier, then mark it as needing
    // to be filled when the function starts off.
    IdentifierNode *pIdent = dynamic_cast<IdentifierNode *>(pLeft);
    if (pIdent != nullptr)
    {
        VariableInfo *pVarInfo = pIdent->GetVariableInfo();
        pVarInfo->ReferenceFrom(GetTypedParent<FunctionDeclaratorNode>());
    }

    StructMember *pMember = _pStructTypeInfo->GetMember(_fieldSymIndex);
    if (pMember == nullptr)
    {
        GetContext()->ReportError(_location, "Unknown member of struct");
    }

    if (pMember->GetType()->GetTypeClass() == TypeClass::Array)
    {
        // Accessing an array member returns a pointer
        ArrayTypeInfo *pArrayInfo = dynamic_cast<ArrayTypeInfo *>(pMember->GetType());
        SetType(GetContext()->_typeCollection.GetPointerType(pArrayInfo->GetBaseType()));
    }
    else
    {
        // The type of this expression is the type of the member
        SetType(pMember->GetType());
    }*/
}

ExpressionResult *FieldSelectionNode::CalculateResult()
{
/*    //printf("Begin FieldSelectionNode %p\n", this);

    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Get the appropriate scope
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // Find the result of the child
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    // Remember if we allocate a register, and make sure we have a register
    // which represents the base address of the struct that we are referencing
    RegisterCollection *pRegCollection = nullptr;
    RegIndex baseRegister;
    bool fSetBaseRegister = false;

    // Get the member of the struct that we are selecting
    StructMember *pMember = _pStructTypeInfo->GetMember(_fieldSymIndex);

    // We need a register to offset. If we have one already then great, otherwise
    // we need to do the work to ensure that we have one for the path that arrived
    // here.
    if (childResult->GetResultType() == ExpressionResultType::Constant)
    {
        // Did not expect that to happen, structs should never be constants
        throw "Unexpected constant expression as child of FieldExpressionNode";
    }
    else if (
        childResult->GetResultType() == ExpressionResultType::DerefRegisterOffset ||
        childResult->GetResultType() == ExpressionResultType::DerefRegisterIndex ||
        childResult->GetResultType() == ExpressionResultType::RegisterIndex)
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
        if (childResult->GetResultType() == ExpressionResultType::RegisterIndex)
        {
            // We need to have a pointer to offset, but we don't want to pull
            // what is at the address. We just want to calculate where it is.
            pScope->GetContext()->OutputInstruction(
                OpCode::LeaRRoR,
                Operand(baseRegister),
                *childResult.get());                
        }
        else
        {
            // It is a pointer or some other non-array thing that we can get
            pScope->GetContext()->OutputMovInstruction(
                Operand(baseRegister),
                *childResult.get());
        }
    }
    else
    {
        // It needs to be something that we can select from
        if (childResult->GetResultType() != ExpressionResultType::Register)
        {
            //printf("Type is %d\n", childResult->GetResultType());
            GetContext()->ReportError(_location, "This pointer needs to be in a register by now");
        }

        // We can assume this is the register operand we want
        baseRegister = childResult->GetRegIndex();
    }

    Operand result;
    if (pMember->GetType()->GetTypeClass() == TypeClass::Array)
    {
        //printf("Accessing array member\n");

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
            OpCode::AddRRC,
            result,
            Operand(baseRegister),
            Operand((int)_pStructTypeInfo->GetOffset(pMember->GetSymbolIndex())));
    }
    else
    {
        // Create an offset operand using the index of the field
        result = Operand(
            baseRegister,
            _pStructTypeInfo,
            pMember,
            GetContext());
    }

    //printf("End FieldSelectionNode %p\n", this);

    if (pRegCollection != nullptr)
    {
        return new ExpressionResult(result, pRegCollection);
    }
    else
    {
        return new ExpressionResult(result);
    }*/
    return nullptr;
}
