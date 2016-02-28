#pragma once

#include "RegisterCollection.h"

class PSLCompilerContext;
class ASTNode;
class TypeInfo;

class VariableInfo
{
public:
    VariableInfo(PSLCompilerContext* pContext, int symIndex, bool fGlobal, TypeInfo* pInfo);

    RegIndex GetRegIndex();
    TypeInfo* GetTypeInfo() { return _pType; }

    PSLCompilerContext* _pContext;
    int _symIndex;
    RegIndex _regIndex;

private:
    TypeInfo* _pType;
    bool _fGlobal;
};
