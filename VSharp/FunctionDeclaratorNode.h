#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

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
    void PreProcessNodeImpl() override;
    void ProcessNodeImpl() override;
    void PostProcessNodeImpl() override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;
};
