#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(
        PSLCompilerContext* pContext, 
        ASTNode* pTypeNode, 
        int symIndex,
        int genericSym
        ) : 
            ASTNode(pContext),
            _regCollection(32)  // TODO: Shrink registers on function calls somehow
    {
        AddNode(pTypeNode);

        _symIndex = symIndex;
        _genericIndex = genericSym;
        _paramCount = 0;

        //printf("Creating function declarator node\n");
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

    void PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    void PreProcessNodeImpl() override;
    void PostProcessNodeImpl() override;
    const char* GetDebugName() override { return "FunctionDeclaratorNode"; }

    bool IsEntryPoint()
    {
        return (GetContext()->_symbols[_symIndex] == "main");
    }

    RegisterCollection* GetRegCollection() { return &_regCollection; }

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;

    // The register allocator for this function
    RegisterCollection _regCollection;

    // Param count
    int _paramCount;
};
