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
    void AddBuiltin();
    
    VariableInfo* AddVariable(
        int symIndex, 
        FunctionDeclaratorNode* pScope, 
        TypeInfo* pTypeInfo
        );
    
    VariableInfo* GetInfo(int symIndex);

private:
    PSLCompilerContext* _pContext;
    std::map<int, std::unique_ptr<VariableInfo> > _variables;
};
