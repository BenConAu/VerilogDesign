#pragma once

#include <string>
#include "VariableLocation.h"
#include "SmartRegister.h"
#include "Operand.h"

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
struct ExpressionResult
{
    ExpressionResult(Operand operand, RegisterCollection* pCollection);
    ExpressionResult(Operand);

    // The operand with the result of the expression
    Operand _operand;

    // If the operation had a temporary register it is stored here
    SmartRegister _tempRegister;
};