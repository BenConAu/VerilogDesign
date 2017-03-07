#pragma once

#include <string>
#include <vector>
#include <memory>
#include "VariableLocation.h"
#include "SmartRegister.h"
#include "Operand.h"

enum class ExpressionResultType
{
    None = 0,            // Used for error conditions and the such or unintialized types
    Constant,            // The operand is a constant
    Register,            // The operand is a register
    RegisterIndex,       // The operand has a location with an index offset
    DerefConstant,       // The operand is a memory location at the given constant location
    DerefRegisterOffset, // Just like above, but with a constant offset
    DerefRegisterIndex,  // Just like above, but with an index offset
};

ExpressionResultType ConvertType(OperandType type);

class TypeInfo;

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
//
// This implies that every expression needs to store what it outputs into
// this form. 
struct ExpressionResult
{
    ExpressionResult(RegisterCollection* pCollection = nullptr);
    ExpressionResult(const Operand &operand, RegisterCollection* pCollection);
    ExpressionResult(const Operand &operand);

    ~ExpressionResult()
    {
        for (size_t i = _tempRegisters.size(); i > 0 ; i--)
        {
            _tempRegisters[i - 1].reset(nullptr);
        }
        //printf("ExpressionResult destructor\n");
    }

    void AddOperand(const Operand& op, bool temp);

    std::string DebugPrint();
    size_t GetOperandCount() const;
    ExpressionResultType GetResultType() const;
    RegIndex GetRegIndex();
    const Operand& GetOperand(size_t index) const { return _operandList[index]; }

private:
    // The aggregate type of the operands (how to interpret them)
    mutable ExpressionResultType _type;

    // If the operation had a temporary register it is stored here
    std::vector<std::unique_ptr<SmartRegister> > _tempRegisters;

    // The collection we are keeping registers in
    RegisterCollection* _pCollection;

    // The operands
    std::vector<Operand> _operandList;    
};