#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"
#include "TypeNode.h"
#include <stack>

class FunctionCallNode;
class AssignmentNode;

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

    TypeNode* GetReturnType() { return dynamic_cast<TypeNode*>(GetChild(0)); }
    ExpressionResult* GetResult() { return _lastResult.get(); }
    size_t GetParameterCount() const { return (GetChildCount() - 2); }
    
    void PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    void ProcessNodeImpl() override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }
    const char* GetFunctionName() { return GetContext()->_symbols[_symIndex].c_str(); }

    ASTNode* DuplicateIdentifier(int symIndex);
    ASTNode* ExpandFunction(FunctionCallNode* pCall, AssignmentNode* pAssignment);
    AssignmentNode* GetAssignmentNode() { return _pAssignmentNode; }
    FunctionCallNode* GetCallNode() { return _pCallNode; }
    
private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;

    // Arguments
    std::map<int, size_t> _passedArgs;

    // The call that we are currently expanding and the expression that spawned it
    FunctionCallNode* _pCallNode;
    AssignmentNode* _pAssignmentNode;

    // The result from the last expansion
    std::unique_ptr<ExpressionResult> _lastResult;
};
