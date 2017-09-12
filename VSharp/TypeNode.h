#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
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
        const UIntConstant &bitLength);

    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }
    void SetModifier(int modifier);
    TypeClass GetTypeClass() const { return _typeClass; }
    bool IsWire() const { return _IsWire; }

private:
    TypeClass _typeClass;
    int _extra;
    bool _IsWire;

    TypeInfo* _pTypeInfo;
};
