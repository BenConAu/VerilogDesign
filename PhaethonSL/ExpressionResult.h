#pragma once

#include <string>
#include "VariableLocation.h"
#include "SmartRegister.h"
#include "Operand.h"

class TypeInfo;
class VariablePath;

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
//
// This implies that every expression needs to store what it outputs into
// this form. 
struct ExpressionResult
{
    ExpressionResult(TypeInfo* pTypeInfo, Operand operand, RegisterCollection* pCollection);
    ExpressionResult(TypeInfo* pTypeInfo, Operand operand);
    ExpressionResult(TypeInfo* pTypeInfo, VariableInfo* pVarInfo, Operand operand);

    void DebugPrint();

    // The type of the result that is stored in the operand
    TypeInfo* _pTypeInfo;

    // Optional variable info that might be relevant
    VariableInfo* _pVarInfo;

    // The operand with the result of the expression
    Operand _operand;

    // If the operation had a temporary register it is stored here
    SmartRegister _tempRegister;
};