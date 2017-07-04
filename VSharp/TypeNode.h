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
        PSLCompilerContext *pContext, 
        const YYLTYPE &location,
        ASTNode* pNode);
    
    TypeNode(
        PSLCompilerContext *pContext, 
        const YYLTYPE &location,
        int bitLength);

    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }

private:
    TypeClass _typeClass;
    int _extra;
    YYLTYPE _location;

    TypeInfo* _pTypeInfo;
};
