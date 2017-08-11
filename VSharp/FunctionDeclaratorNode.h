#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"
#include <stack>

class FunctionCallNode;

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(
        PSLCompilerContext* pContext, 
        int symIndex,
        int genericSym
        ) : 
            ASTNode(pContext)
    {
        _symIndex = symIndex;
        _genericIndex = genericSym;
    }

    void AddParameter(ASTNode* pNode)
    {
        AddNode(pNode);
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

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
};
