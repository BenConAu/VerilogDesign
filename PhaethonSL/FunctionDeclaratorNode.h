#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(
        PSLCompilerContext* pContext, 
        ASTNode* pTypeNode, 
        int symIndex
        ) : 
            ASTNode(pContext),
            _regCollection(32)  // TODO: Shrink registers on function calls somehow
    {
        AddNode(pTypeNode);

        _symIndex = symIndex;
        _paramCount = 0;
    }

    void AddParameter(ASTNode* pNode)
    {
        AddNode(pNode);

        _paramCount++;
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

    void VerifyNodeImpl() override
    {
        if (IsEntryPoint())
        {
            GetContext()->SetEntryPoint(this);
        }

        // TODO: Make sure function name is unique
    }

    void PreProcessNodeImpl() override;

    void PostProcessNodeImpl() override
    {
        if (!IsEntryPoint())
        {
            printf("rret\n");
        }
    }

    bool IsEntryPoint()
    {
        return (GetContext()->_symbols[_symIndex] == "main");
    }

    RegisterCollection* GetRegCollection() { return &_regCollection; }

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The register allocator for this function
    RegisterCollection _regCollection;

    // Param count
    int _paramCount;
};
