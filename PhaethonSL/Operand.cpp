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

Operand::Operand(VariableInfo* pInfo)
{
    _type = OperandType::Memory;
    _pVarInfo = pInfo;
}

Operand::Operand(RegIndex regIndex, VariableInfo* pVarInfo, StructMember* pTypeMember)
{
    _type = OperandType::MemoryOffset;
    _offsetInfo._regIndex = regIndex;
    _offsetInfo._pVarInfo = pVarInfo;
    _offsetInfo._pTypeMember = pTypeMember;
}

bool Operand::IsNone() const
{
    return (_type == OperandType::None);
}

// Create an assembly language operand representing the expression result
std::string Operand::GetOperand(PSLCompilerContext* pContext) const
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
            result << "&" << pContext->_symbols[_pVarInfo->GetSymbolIndex()];
            break;

        case OperandType::MemoryOffset:
        {
            StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(_offsetInfo._pVarInfo->GetTypeInfo());
            std::string typeName = pContext->_symbols[pTypeInfo->GetSymbolIndex()];
            std::string memberName = pContext->_symbols[_offsetInfo._pTypeMember->GetSymbolIndex()];

            result << "r" << (unsigned int)_offsetInfo._regIndex << "->" << typeName << "::" << memberName;
        }
        break;

        default:
            throw "Unknown result type";
    }

    return result.str();
}

