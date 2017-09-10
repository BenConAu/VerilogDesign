#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "VSharp.tab.h"

class TypeNode : public ASTNode
{
public:
    TypeNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location,
        TypeClass typeClass, 
        int type);

    TypeNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location,
        TypeClass typeClass);
        
    TypeNode(
        PSLCompilerContext *pContext, 
        const YYLTYPE &location,
        const UIntConstant &bitLength);

    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }
    void SetModifier(int modifier);
    TypeClass GetTypeClass() const { return _typeClass; }

private:
    TypeClass _typeClass;
    int _extra;
    YYLTYPE _location;
    bool _IsWire;

    TypeInfo* _pTypeInfo;
};
