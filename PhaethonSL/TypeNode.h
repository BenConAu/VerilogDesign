#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"

class TypeNode : public ASTNode
{
public:
    TypeNode(PSLCompilerContext* pContext, TypeClass typeClass, int type);
    TypeNode(PSLCompilerContext *pContext, ASTNode* pNode);
    
    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }

private:
    TypeClass _typeClass;
    TypeNode* _pBaseTypeNode;
    int _typeOrSymbol;

    TypeInfo* _pTypeInfo;
};
