#pragma once

#include "RegisterCollection.h"

class PSLCompilerContext;
class ASTNode;
class TypeInfo;

class VariableInfo
{
public:
    VariableInfo(PSLCompilerContext* pContext, int symIndex, ASTNode* pNode, TypeInfo* pInfo);

    void Allocate();
    RegIndex GetRegIndex();
    TypeInfo* GetTypeInfo() { return _pType; }
    void NotifyNodeProcessed(ASTNode* pNode);

    PSLCompilerContext* _pContext;
    int symIndex;
    ASTNode* pDecl;
    ASTNode* pLastRef;
    RegIndex _regIndex;
    bool fLastProcessed;

private:
    TypeInfo* _pType;
};
