#include "Operand.h"
#include "PSLCompilerContext.h"
#include "StructTypeInfo.h"
#include <sstream>

Operand::Operand()
{
    _objArg._argType = OperandType::None;
    _objArg._value = 0xef;
}

Operand::Operand(RegIndex index)
{
    _objArg._argType = OperandType::Register;
    _objArg._value = index;
}

Operand::Operand(int constant)
{
    _objArg._argType = OperandType::Constant;
    _objArg._value = constant;
}

Operand::Operand(
    VariableInfo* pVarInfo, 
    PSLCompilerContext* pContext
    )
{
    // Fill in the actual byte position
    _objArg._argType = OperandType::DerefConstant;
    _objArg._value = pVarInfo->GetMemLocation();

    // Fill in symbolic information
    _objArg._memberName = pContext->_symbols[pVarInfo->GetSymbolIndex()];
}

Operand::Operand(
    RegIndex regIndex, 
    VariableInfo* pVarInfo, 
    StructMember* pTypeMember, 
    PSLCompilerContext* pContext
    )
{
    _objArg._argType = OperandType::DerefRegisterOffset;
    _objArg._value = regIndex;

    // Need to be given a struct
    StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());

    // Fill in the actual byte offset
    _objArg._offset = pTypeInfo->GetOffset(pTypeMember->GetSymbolIndex());

    // Fill in symbolic information
    _objArg._typeName = pContext->_symbols[pTypeInfo->GetSymbolIndex()];
    _objArg._memberName = pContext->_symbols[pTypeMember->GetSymbolIndex()];
}

bool Operand::IsNone() const
{
    return (GetType() == OperandType::None);
}

RegIndex Operand::GetRegIndex() const
{
    switch (GetType())
    {
        case OperandType::None:
        case OperandType::Constant:
        case OperandType::DerefConstant:
            throw "Attempt to retrieve register index from non-register operand";

        default:
            // For register arguments, the value is the index of the register
            return _objArg._value;
    }
}