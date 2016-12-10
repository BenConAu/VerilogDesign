#pragma once

class PSLCompilerContext;

class SymbolInfo
{
  public:
    SymbolInfo(
        PSLCompilerContext *pContext, // The context that this symbol lives in
        int symIndex                  // The symbol index for the identifier for the symbol
        );

    virtual ~SymbolInfo() {}

    PSLCompilerContext *GetContext() { return _pContext; }
    int GetSymbolIndex() const { return _symIndex; }
    const char *GetSymbol();

  private:
    PSLCompilerContext *_pContext;
    int _symIndex;
};
