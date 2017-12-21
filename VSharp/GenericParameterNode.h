#pragma once

#include "ASTNode.h"
#include "TypeNode.h"

class GenericParameterNode : public ASTNode
{
public:
    GenericParameterNode(ParserContext* pContext, const YYLTYPE &location, ASTNode* pType, int symIndex) : ASTNode(pContext, location)
    {
        AddNode(pType);
        _symIndex = symIndex;
        _fTypename = (pType == nullptr);
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "GenericParameterNode"; }
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
    
    int GetSymbolIndex() const;
    const char* GetSymbol();
    bool IsTypename() const;
    TypeNode* GetTypeNode();
    TypeInfo* GetTypeInfo();

private:
    int _symIndex;
    bool _fTypename;
};
