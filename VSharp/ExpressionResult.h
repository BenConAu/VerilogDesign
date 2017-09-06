#pragma once

#include <string>
#include <vector>
#include <memory>

class StaticTypeInfo;
class FunctionCallNode;

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

    std::string DebugPrint();

    const std::string& GetString() const;
    FunctionCallNode* GetConstructorNode() { return _pConstructorCall; }

private:
    std::string _result;
    StaticTypeInfo* _pStaticInfo;
    FunctionCallNode* _pConstructorCall;
};