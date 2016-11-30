#pragma once

#include "ASTNode.h"

class TypeInfo;

enum class TypeClass
{
    Basic,
    Struct,
    Pointer,
};

class TypeNode : public ASTNode
{
public:
    TypeNode(PSLCompilerContext* pContext, TypeClass typeClass, int type);
    TypeNode(PSLCompilerContext *pContext, ASTNode* pNode);
    
    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;

private:
    TypeClass _typeClass;
    TypeNode* _pBaseTypeNode;
    int _typeOrSymbol;

    TypeInfo* _pTypeInfo;
};
