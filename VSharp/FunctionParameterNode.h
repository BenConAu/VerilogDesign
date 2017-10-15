#pragma once

#include "ASTNode.h"
#include "TypeNode.h"

class FunctionParameterNode : public ASTNode
{
public:
    FunctionParameterNode(ParserContext* pContext, const YYLTYPE &location, ASTNode* pType, int symIndex, bool fOut) : ASTNode(pContext, location)
    {
        AddNode(pType);
        _symIndex = symIndex;
        _fOut = fOut;
    }

    FunctionParameterNode(ParserContext* pContext, const YYLTYPE &location, int symIndex, bool fOut) : ASTNode(pContext, location)
    {
        _symIndex = symIndex;
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionParameterNode"; }
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
    
    int GetSymbolIndex() const { return _symIndex; }
    bool IsOutParam() const { return _fOut; }
    TypeNode* GetTypeNode() { return dynamic_cast<TypeNode*>(GetChild(0)); }

private:
    int _symIndex;
    bool _fOut;
};
