#pragma once

#include <string>
#include <vector>
#include "VariableLocation.h"
#include "SmartRegister.h"
#include "Operand.h"
#include "PSLCompilerContext.h"

class TypeInfo;

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
//
// This implies that every expression needs to store what it outputs into
// this form. 
struct ExpressionResult
{
    ExpressionResult(RegisterCollection* pCollection);
    ExpressionResult(Operand operand, RegisterCollection* pCollection);
    ExpressionResult(Operand operand);

    ~ExpressionResult()
    {
        //printf("ExpressionResult destructor\n");
    }

    void AddOperand(const Operand& op, bool temp);

    OperandList &GetOperands() { return _operandList; }
    ExpressionResultType GetResultType() { return _operandList.GetResultType(); }

    void DebugPrint();

private:
    // The operand with the result of the expression
    OperandList _operandList;

    // If the operation had a temporary register it is stored here
    std::vector<std::unique_ptr<SmartRegister> > _tempRegisters;

    // The collection we are keeping registers in
    RegisterCollection* _pCollection;
};