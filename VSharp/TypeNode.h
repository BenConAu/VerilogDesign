#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "PSL.tab.h"

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
    
    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "TypeNode"; }

private:
    TypeClass _typeClass;
    int _typeOrSymbol;
    YYLTYPE _location;

    TypeInfo* _pTypeInfo;
};
