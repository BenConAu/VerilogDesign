#pragma once

class VSharpCompiler;
class ModuleDefinitionNode;

class SymbolInfo
{
  public:
    SymbolInfo(
        VSharpCompiler *pCompiler,      // The context that this symbol lives in
        ModuleDefinitionNode *pScope,   // The scope of the symbol
        int symIndex                    // The symbol index for the identifier for the symbol
        );

    virtual ~SymbolInfo() {}

    VSharpCompiler *GetCompiler() { return _pCompiler; }
    int GetSymbolIndex() const { return _symIndex; }
    const char *GetSymbol();
    ModuleDefinitionNode *GetScope() { return _pScope; }

  private:
    // The compiler context
    VSharpCompiler *_pCompiler;

    // Symbol index from lexer
    int _symIndex;

    // Scope symbol was declared in (null if global)
    ModuleDefinitionNode *_pScope;    
};
