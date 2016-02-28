#pragma once

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(PSLCompilerContext* pContext, ASTNode* pTypeNode, int symIndex) : ASTNode(pContext)
    {
        AddNode(pTypeNode);
        _symIndex = symIndex;
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

    void PreProcessNodeImpl() override
    {
        // non-main functions have a prologue
        if (!IsEntryPoint())
        {
            printf("%s:\n", GetContext()->_symbols[_symIndex].c_str());
        }
    }

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

private:
    int _symIndex;
};
