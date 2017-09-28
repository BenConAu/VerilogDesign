#pragma once

#include <string>
#include <vector>
#include <memory>
#include "UIntConstant.h"

class StaticTypeInfo;
class FunctionCallNode;

// A BitSelectResult represents selecting bits from another expression
struct BitSelectResult
{
    BitSelectResult(const char* r, unsigned int i1, unsigned int i2)
    {
        _baseResult = r;
        _i1 = i1;
        _i2 = i2;
    }

    std::string _baseResult;
    unsigned int _i1;
    unsigned int _i2;
};

// An ExpressionResult stores everything needed when an expression finishes and
// includes anything that will be freed when the result is no longer needed.
//
// This implies that every expression needs to store what it outputs into
// this form. 
struct ExpressionResult
{
    ExpressionResult(const std::string& str);
    ExpressionResult(StaticTypeInfo* pInfo);
    ExpressionResult(const std::string& str, FunctionCallNode* pNode);
    ExpressionResult(BitSelectResult* pRes);
    ExpressionResult(const UIntConstant &ConstUInt);

    std::string DebugPrint();

    const std::string& GetString() const;
    FunctionCallNode* GetConstructorNode() { return _pConstructorCall; }
    bool IsConstant() const { return _IsConstant; }
    bool GetConstantValue() const { return _ConstantValue; }
    BitSelectResult* GetBitSelection() { return _BitSelect.get(); }

private:
    std::string _result;
    StaticTypeInfo* _pStaticInfo;
    FunctionCallNode* _pConstructorCall;
    std::unique_ptr<BitSelectResult> _BitSelect;
    bool _IsConstant;
    bool _ConstantValue;
};