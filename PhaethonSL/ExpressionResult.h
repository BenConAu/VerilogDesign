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
    ExpressionResult(TypeInfo* pTypeInfo, RegisterCollection* pCollection);
    ExpressionResult(TypeInfo* pTypeInfo, Operand operand, RegisterCollection* pCollection);
    ExpressionResult(TypeInfo* pTypeInfo, Operand operand);
    ExpressionResult(VariableInfo* pVarInfo, Operand operand);

    ~ExpressionResult()
    {
        //printf("ExpressionResult destructor\n");
    }

    void SetType(TypeInfo *pNewInfo)
    {
        // The assumption is that the variable info is the same...
        _pTypeInfo = pNewInfo;
    }

    void AddOperand(const Operand& op, bool temp);

    OperandList &GetOperands() { return _operandList; }
    ExpressionResultType GetResultType() { return _operandList.GetResultType(); }

    void DebugPrint();

    // The type of the result that is stored in the operand
    TypeInfo* _pTypeInfo;

    // Optional variable info that might be relevant
    VariableInfo* _pVarInfo;

private:
    // The operand with the result of the expression
    OperandList _operandList;

    // If the operation had a temporary register it is stored here
    std::vector<std::unique_ptr<SmartRegister> > _tempRegisters;

    // The collection we are keeping registers in
    RegisterCollection* _pCollection;
};