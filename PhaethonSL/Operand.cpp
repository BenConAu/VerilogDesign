#include "Operand.h"
#include "PSLCompilerContext.h"
#include <sstream>

Operand::Operand()
{
    _type = OperandType::None;
}

Operand::Operand(RegIndex index)
{
    _type = OperandType::Register;
    _regIndex = index;
}

Operand::Operand(int constant)
{
    _type = OperandType::Constant;
    _constant = constant;
}

Operand::Operand(
    VariableInfo* pVarInfo, 
    PSLCompilerContext* pContext
    )
{
    _type = OperandType::Memory;

    _offsetInfo._memberName = pContext->_symbols[pVarInfo->GetSymbolIndex()];
}

Operand::Operand(
    RegIndex regIndex, 
    VariableInfo* pVarInfo, 
    StructMember* pTypeMember, 
    PSLCompilerContext* pContext
    )
{
    _type = OperandType::MemoryOffset;
    _offsetInfo._regIndex = regIndex;

    StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
    _offsetInfo._typeName = pContext->_symbols[pTypeInfo->GetSymbolIndex()];
    _offsetInfo._memberName = pContext->_symbols[pTypeMember->GetSymbolIndex()];
}

bool Operand::IsNone() const
{
    return (_type == OperandType::None);
}

// Create an assembly language operand representing the expression result
std::string Operand::GetOperand() const
{
    std::stringstream result;

    switch (_type)
    {
        case OperandType::Constant:
            // PASM just uses the constant simply
            result << _constant;
            break;

        case OperandType::Register:
            // Return the register syntax
            result << "r" << (unsigned int)_regIndex;
            break;

        case OperandType::Memory:
            // The assembler uses C-like syntax for getting addresses of things
            result << "&" << _offsetInfo._memberName;
            break;

        case OperandType::MemoryOffset:
            result << "r" << (unsigned int)_offsetInfo._regIndex << "->" << _offsetInfo._typeName << "::" << _offsetInfo._memberName;
            break;

        default:
            throw "Unknown result type";
    }

    return result.str();
}

