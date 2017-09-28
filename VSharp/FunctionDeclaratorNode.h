#pragma once

#include "ParserContext.h"
#include "ASTNode.h"
#include "TypeNode.h"
#include "FunctionParameterNode.h"
#include "FunctionInfo.h"
#include <stack>

class FunctionCallNode;
class StatementNode;
class FunctionParameterNode;

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(
        ParserContext* pContext,
        const YYLTYPE &location,
        ASTNode* pRetType,
        int symIndex,
        ASTNode* pGenericExpr);

    FunctionDeclaratorNode(
        ParserContext* pContext,
        const YYLTYPE &location,
        int symIndex);

    void AddParameter(ASTNode* pNode)
    {
        if (pNode == nullptr)
        {
            throw "Parameters cannot be null";
        }
        
        AddNode(pNode);
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

    TypeNode* GetReturnType() { return dynamic_cast<TypeNode*>(GetChild(0)); }
    ExpressionResult* GetResult() { return _lastResult.get(); }
    size_t GetParameterCount() const { return (GetChildCount() - 3); }
    FunctionParameterNode* GetParameter(size_t index) { return dynamic_cast<FunctionParameterNode*>(GetChild(index + 2)); }
    
    bool PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    void ProcessNodeImpl(OutputContext* pOutputContext) override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }
    const char* GetFunctionName() { return GetContext()->GetSymbolString(_symIndex).c_str(); }
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;
    
    bool IsParameter(int symIndex);
    bool IsGenericParameter(int symIndex);
    ASTNode* DuplicateParameterIdentifier(int symIndex);
    ASTNode* DuplicateGenericParameterIdentifier(int symIndex);
    ASTNode* ExpandFunction(FunctionCallNode* pCall, StatementNode* pStatement);
    ASTNode* ExpandFunction(FunctionCallNode* pCall, UIntConstant Value);
    StatementNode* GetStatementNode() { return _pStatementNode; }
    FunctionCallNode* GetCallNode() { return _pCallNode; }
    GenericType GetGenericType() const { return _GenericType; }
    
private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    GenericType _GenericType;
    
    // Arguments
    std::map<int, size_t> _passedArgs;

    // The call that we are currently expanding
    FunctionCallNode* _pCallNode;

    // The expression that the function was in (for function expansion)
    StatementNode* _pStatementNode;

    // The constant value that we are speciating for (for generic expansion)
    UIntConstant _genericValue;

    // The result from the last expansion
    std::unique_ptr<ExpressionResult> _lastResult;
};
