#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

class ModuleDeclaratorNode : public ASTNode
{
public:
    ModuleDeclaratorNode(
        PSLCompilerContext* pContext, 
        int symIndex,
        int genericSym
        ) : 
            ASTNode(pContext)
    {
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

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;

    // Param count
    int _paramCount;
};
