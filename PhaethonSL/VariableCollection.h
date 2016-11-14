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
    
    void AddVariable(
        int symIndex, 
        FunctionDeclaratorNode* pScope, 
        TypeInfo* pTypeInfo, 
        RegIndex* pRegIndex
        );
    
    VariableInfo* GetInfo(int symIndex);

private:
    PSLCompilerContext* _pContext;
    std::map<int, std::unique_ptr<VariableInfo> > _variables;
};
