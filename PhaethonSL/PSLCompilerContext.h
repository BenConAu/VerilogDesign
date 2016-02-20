#pragma once

class PSLCompilerContext
{
public:
    PSLCompilerContext();
    ~PSLCompilerContext();
    int AddSymbol(const char* pszSymbol);
    void* pScanner;
};
