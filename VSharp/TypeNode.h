#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "TypeModifier.h"
#include "VSharp.tab.h"

class TypeNode : public ASTNode
{
public:
    TypeNode(
        ParserContext* pContext, 
        const YYLTYPE &location,
        TypeClass typeClass, 
        int type);

    TypeNode(
        ParserContext* pContext, 
        const YYLTYPE &location,
        TypeClass typeClass);
        
    TypeNode(
        ParserContext *pContext, 
        const YYLTYPE &location,
        ASTNode* pExpr);

    TypeNode(
        ParserContext *pContext, 
        const YYLTYPE &location,
        TypeClass typeClass,
        TypeModifier TypeModifier,
        int extra,
        TypeInfo* pTypeInfo);
                
    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;

    TypeModifier GetModifier() const { return _TypeModifier; }
    void SetModifier(TypeModifier modifier);
    TypeClass GetTypeClass() const { return _typeClass; }

private:
    TypeClass _typeClass;
    TypeModifier _TypeModifier;
    int _extra;

    TypeInfo* _pTypeInfo;
};
