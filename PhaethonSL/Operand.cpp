#include "Operand.h"
#include "PSLCompilerContext.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include <sstream>

// Default operand constructor makes a 'none' operand and puts
// a dummy value that we can see in the obj file to make things
// somewhat predictable.
Operand::Operand()
{
    _pVarInfo = nullptr;
}

// A regster operand stores the register index.
Operand::Operand(RegIndex index)
{
    _objArg._argType = OperandType::Register;
    _objArg._value = index;
    _objArg._offset = -1;
    _objArg._fMemoryLocation = false;
    
    _pVarInfo = nullptr;
}

// Constant operand stores a constant
Operand::Operand(int constant)
{
    _objArg._argType = OperandType::Constant;
    _objArg._value = constant;
    _objArg._offset = -1;
    _objArg._fMemoryLocation = false;
    
    _pVarInfo = nullptr;
}

// An operand that loads an address of a variable
// into a register so that it can be used later
Operand::Operand(
    VariableInfo *pVarInfo,
    PSLCompilerContext *pContext)
{
    // Fill in the actual byte position
    _objArg._argType = OperandType::Constant;
    _objArg._value = pVarInfo->GetMemLocation();
    _objArg._offset = -1;
    _pVarInfo = pVarInfo;

    // Fill in symbolic information
    _objArg._memberName = pContext->_symbols[pVarInfo->GetSymbolIndex()];
    _objArg._fMemoryLocation = true;
}

// An operand that loads a known constant into a register
// so that it can be used later
Operand::Operand(
    KnownConstants constant)
{
    // Fill in the actual byte position
    _objArg._argType = OperandType::Constant;
    _objArg._value = VariableInfo::GetDataSegmentEnd();
    _objArg._offset = -1;

    // This is a memory location, because it is pointing to memory
    _objArg._memberName = "__datasegmentend";
    _objArg._fMemoryLocation = true;

    _pVarInfo = nullptr;
}

// An offset operand comes from a register (already allocated) and
// a structure variable with member.
Operand::Operand(
    RegIndex regIndex,
    StructTypeInfo *pTypeInfo,
    StructMember *pTypeMember,
    PSLCompilerContext *pContext)
{
    // Non-pointer values are obtained through a deref with offset
    _objArg._argType = OperandType::DerefRegisterOffset;
    _objArg._value = regIndex;

    // Fill in the actual byte offset
    _objArg._offset = pTypeInfo->GetOffset(pTypeMember->GetSymbolIndex());

    // Fill in symbolic information
    _objArg._typeName = pContext->_symbols[pTypeInfo->GetSymbolIndex()];
    _objArg._memberName = pContext->_symbols[pTypeMember->GetSymbolIndex()];

    _objArg._fMemoryLocation = false;
    _pVarInfo = nullptr;    
}

// An offset operand comes from a register (already allocated) and
// a structure variable with member.
Operand::Operand(
    RegIndex regIndex,
    PointerTypeInfo *pTypeInfo,
    PSLCompilerContext *pContext)
{
    if (pTypeInfo->GetBaseType()->GetTypeClass() == TypeClass::Struct)
    {
        // We cannot dereference a struct so we take out the deref
        _objArg._argType = OperandType::RegisterOffset;
    }
    else
    {
        _objArg._argType = OperandType::DerefRegisterOffset;
    }

    _objArg._value = regIndex;

    // The offset stores the size of each item
    TypeInfo *pBaseType = pTypeInfo->GetBaseType();
    _objArg._offset = pBaseType->GetSize();

    // Fill in symbolic information
    _objArg._typeName = pTypeInfo->GetBaseType()->GetTypeName();

    _objArg._fMemoryLocation = false;
    _pVarInfo = nullptr;    
}

Operand::Operand(
    const std::string &label)
{
    // Fill in the actual byte position
    _objArg._argType = OperandType::Constant;
    _objArg._value = -1;
    _objArg._offset = -1;
    _objArg._label = label;

    _pVarInfo = nullptr;    
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

std::string Operand::DebugPrint()
{
    return _objArg.DebugPrint();
}

const ObjArgument &Operand::GetObjArgument() const
{
    return _objArg;
}
