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
};

enum class ResultTypeMethod
{
    Both, // Type of arguments
    Bool, // Returns bool
};

struct OperatorInfo
{
    Operator _operator;
    OpCode _opCodeWord;
    OpCode _opCodeFloat;
    ResultTypeMethod _resultType;
};
