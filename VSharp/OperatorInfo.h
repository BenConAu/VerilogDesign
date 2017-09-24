#pragma once

enum class Operator
{
    Multiply,
    Divide,
    Add,
    Subtract,
    ShiftLeft,
    ShiftRight,
    Equal,
    NotEqual,
    LessThan,
    GreaterThan,
    LessThanEqual,
    GreaterThanEqual,
    Negate,
    LogicalAnd,
    LogicalOr,
    BitwiseXor,
    BitwiseOr,
    LogicalNot,
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
