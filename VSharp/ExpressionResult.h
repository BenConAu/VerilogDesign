#pragma once

#include <string>
#include <vector>
#include <memory>
#include "VariableLocation.h"
#include "SmartRegister.h"

class TypeInfo;

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
//
// This implies that every expression needs to store what it outputs into
// this form. 
struct ExpressionResult
{
    ExpressionResult(const std::string& str);

    std::string DebugPrint();

private:
    std::string _result;
};