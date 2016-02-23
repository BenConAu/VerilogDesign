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
    void AddVariable(int symIndex, VariableDeclarationNode* pNode, TypeInfo*);
    void AddReference(int symIndex, ASTNode* pNode);
    void ProcessReference(int symIndex, ASTNode *pNode);
    bool IsLastReference(int symIndex, ASTNode* pNode);
    VariableInfo* GetInfo(int symIndex);

private:
    PSLCompilerContext* _pContext;
    std::map<int, std::unique_ptr<VariableInfo> > _variables;
};
