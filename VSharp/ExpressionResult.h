#pragma once

#include <string>
#include <vector>
#include <memory>

class StaticTypeInfo;
class FunctionCallNode;

struct FieldSelectResult
{
    FieldSelectResult(const char* r, unsigned int i1, unsigned int i2)
    {
        _structResult = r;
        _i1 = i1;
        _i2 = i2;
    }

    std::string _structResult;
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
    ExpressionResult(const std::string& str, bool constantValue);
    ExpressionResult(FieldSelectResult* pRes);

    std::string DebugPrint();

    const std::string& GetString() const;
    FunctionCallNode* GetConstructorNode() { return _pConstructorCall; }
    bool IsConstant() const { return _IsConstant; }
    bool GetConstantValue() const { return _ConstantValue; }
    FieldSelectResult* GetFieldSelect() { return _FieldSelect.get(); }

private:
    std::string _result;
    StaticTypeInfo* _pStaticInfo;
    FunctionCallNode* _pConstructorCall;
    std::unique_ptr<FieldSelectResult> _FieldSelect;
    bool _IsConstant;
    bool _ConstantValue;
};