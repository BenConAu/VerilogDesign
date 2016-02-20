#pragma once

#include "RegisterCollection.h"
#include "VariableCollection.h"

class PSLCompilerContext
{
public:
    PSLCompilerContext();
    ~PSLCompilerContext();
    int AddSymbol(const char* pszSymbol);
    void* pScanner;
    RegisterCollection _regCollection;
    VariableCollection _varCollection;
};
