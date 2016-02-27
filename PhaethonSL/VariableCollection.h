#pragma once

#include <map>
#include "VariableInfo.h"

class VariableDeclarationNode;
class ASTNode;
class PSLCompilerContext;

class VariableCollection
{
public:
    VariableCollection(PSLCompilerContext* pContext);
    void AddVariable(int symIndex, TypeInfo*);
    VariableInfo* GetInfo(int symIndex);

private:
    PSLCompilerContext* _pContext;
    std::map<int, std::unique_ptr<VariableInfo> > _variables;
};
