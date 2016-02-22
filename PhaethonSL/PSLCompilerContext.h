#pragma once

#include "RegisterCollection.h"
#include "VariableCollection.h"
#include "TypeCollection.h"

class PSLCompilerContext
{
public:
    PSLCompilerContext(FILE *pFile);
    ~PSLCompilerContext();
    int AddSymbol(const char* pszSymbol);
    void AddExternalDeclaration(ASTNode* pNode);
    void Parse();
    void* pScanner;
    RegisterCollection _regCollection;
    VariableCollection _varCollection;
    TypeCollection _typeCollection;
    std::vector<std::unique_ptr<ASTNode> > _rootNodes;
};
