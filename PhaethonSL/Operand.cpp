#include "Operand.h"
#include "PSLCompilerContext.h"
#include <sstream>

Operand::Operand()
{
    _objArg._argType = OperandType::None;
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
    _objArg._argType = OperandType::DerefConstant;

    _offsetInfo._memberName = pContext->_symbols[pVarInfo->GetSymbolIndex()];
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

    StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
    _offsetInfo._typeName = pContext->_symbols[pTypeInfo->GetSymbolIndex()];
    _offsetInfo._memberName = pContext->_symbols[pTypeMember->GetSymbolIndex()];
}

bool Operand::IsNone() const
{
    return (GetType() == OperandType::None);
}

// Create an assembly language operand representing the expression result
std::string Operand::GetOpString() const
{
    std::stringstream result;

    switch (GetType())
    {
        case OperandType::Constant:
            // PASM just uses the constant simply
            result << _objArg._value;
            break;

        case OperandType::Register:
            // Return the register syntax
            result << "r" << (unsigned int)GetRegIndex();
            break;

        case OperandType::DerefConstant:
            // The assembler uses C-like syntax for getting addresses of things
            result << "&" << _offsetInfo._memberName;
            break;

        case OperandType::DerefRegisterOffset:
            result << "r" << (unsigned int)GetRegIndex() << "->" << _offsetInfo._typeName << "::" << _offsetInfo._memberName;
            break;

        default:
            throw "Unknown result type";
    }

    return result.str();
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