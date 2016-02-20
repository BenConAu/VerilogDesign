#pragma once

class ASTNode;

class PSLCompilerContext
{
public:
    int AddSymbol(const char* pszSymbol);
    void* pScanner;
};
