#pragma once

#include "ASTNode.h"
#include "TypeNode.h"

class FunctionParameterNode : public ASTNode
{
public:
    FunctionParameterNode(PSLCompilerContext* pContext, const YYLTYPE &location, ASTNode* pType, int symIndex, bool fOut) : ASTNode(pContext, location)
    {
        AddNode(pType);
        _symIndex = symIndex;
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionParameterNode"; }
    int GetSymbolIndex() const { return _symIndex; }
    bool IsOutParam() const { return _fOut; }
    TypeNode* GetTypeNode() { return dynamic_cast<TypeNode*>(GetChild(0)); }

private:
    int _symIndex;
    bool _fOut;
};
