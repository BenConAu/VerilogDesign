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
    
    void PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    void ProcessNodeImpl(OutputContext* pOutputContext) override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }
    const char* GetFunctionName() { return GetContext()->GetSymbolString(_symIndex).c_str(); }

    bool IsParameter(int symIndex);
    bool IsGenericParameter(int symIndex);
    ASTNode* DuplicateParameterIdentifier(int symIndex);
    ASTNode* DuplicateGenericParameterIdentifier(int symIndex);
    ASTNode* ExpandFunction(FunctionCallNode* pCall, StatementNode* pStatement);
    StatementNode* GetStatementNode() { return _pStatementNode; }
    FunctionCallNode* GetCallNode() { return _pCallNode; }
    
private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    GenericType _GenericType;
    
    // Arguments
    std::map<int, size_t> _passedArgs;

    // The call that we are currently expanding and the expression that spawned it
    FunctionCallNode* _pCallNode;
    StatementNode* _pStatementNode;

    // The result from the last expansion
    std::unique_ptr<ExpressionResult> _lastResult;
};
