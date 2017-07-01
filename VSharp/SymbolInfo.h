#pragma once

class PSLCompilerContext;
class ModuleDeclaratorNode;

class SymbolInfo
{
  public:
    SymbolInfo(
        PSLCompilerContext *pContext,   // The context that this symbol lives in
        ModuleDeclaratorNode *pScope, // The scope of the symbol
        int symIndex                    // The symbol index for the identifier for the symbol
        );

    virtual ~SymbolInfo() {}

    PSLCompilerContext *GetContext() { return _pContext; }
    int GetSymbolIndex() const { return _symIndex; }
    const char *GetSymbol();
    ModuleDeclaratorNode *GetScope() { return _pScope; }

  private:
    // The compiler context
    PSLCompilerContext *_pContext;

    // Symbol index from lexer
    int _symIndex;

    // Scope symbol was declared in (null if global)
    ModuleDeclaratorNode *_pScope;    
};
