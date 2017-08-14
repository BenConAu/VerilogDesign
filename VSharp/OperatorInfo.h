#pragma once

enum class Operator
{
    Multiply,
    Add,
    Subtract,
    ShiftLeft,
    ShiftRight,
    Equal,
    NotEqual,
    LessThan,
    GreaterThan,
    Negate,
    LogicalAnd,
};

enum class ResultTypeMethod
{
    Both, // Type of arguments
    Bool, // Returns bool
};

struct OperatorInfo
{
    Operator _operator;
    const char* _pszVerilog;
    ResultTypeMethod _resultType;
};
