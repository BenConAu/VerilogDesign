#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"
#include "TypeNode.h"
#include <stack>

class FunctionCallNode;

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(
        PSLCompilerContext* pContext,
        ASTNode* pRetType,
        int symIndex,
        int genericSym);

    void AddParameter(ASTNode* pNode)
    {
        AddNode(pNode);
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

    void SetCall(FunctionCallNode* pCall);

    TypeNode* GetReturnType() { return dynamic_cast<TypeNode*>(GetChild(0)); }
    ExpressionResult* GetResult() { return _lastResult.get(); }
    size_t GetParameterCount() const { return (GetChildCount() - 2); }
    
    void PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    void ProcessNodeImpl() override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }

    ExpressionResult* ResultFromSymbol(int symIndex);

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;

    // Arguments
    std::map<int, size_t> _passedArgs;

    // The call that we are currently expanding
    FunctionCallNode* _pCallNode;

    // The result from the last expansion
    std::unique_ptr<ExpressionResult> _lastResult;
};
