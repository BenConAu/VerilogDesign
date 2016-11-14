#include "ExpressionResult.h"
#include "PSLCompilerContext.h"
#include <sstream>

ExpressionResult::ExpressionResult()
{
    _type = ResultType::None;
}

ExpressionResult::ExpressionResult(RegIndex index)
{
    _type = ResultType::Register;
    _regIndex = index;
}

ExpressionResult::ExpressionResult(int constant)
{
    _type = ResultType::Constant;
    _constant = constant;
}

ExpressionResult::ExpressionResult(VariableInfo* pInfo)
{
    _type = ResultType::Memory;
    _pVarInfo = pInfo;
}

ExpressionResult::ExpressionResult(RegIndex regIndex, VariableInfo* pVarInfo, StructMember* pTypeMember)
{
    _type = ResultType::MemoryOffset;
    _offsetInfo._regIndex = regIndex;
    _offsetInfo._pVarInfo = pVarInfo;
    _offsetInfo._pTypeMember = pTypeMember;
}

bool ExpressionResult::IsNone() const
{
    return (_type == ResultType::None);
}

// Create an assembly language operand representing the expression result
std::string ExpressionResult::GetOperand(PSLCompilerContext* pContext) const
{
    std::stringstream result;

    switch (_type)
    {
        case ResultType::Constant:
            // PASM just uses the constant simply
            result << _constant;
            break;

        case ResultType::Register:
            // Return the register syntax
            result << "r" << (unsigned int)_regIndex;
            break;

        case ResultType::Memory:
            // The assembler uses C-like syntax for getting addresses of things
            result << "&" << pContext->_symbols[_pVarInfo->GetSymbolIndex()];
            break;

        case ResultType::MemoryOffset:
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
