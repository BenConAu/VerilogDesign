#pragma once

#include "SymbolTable.h"
#include "TypeCollection.h"
#include "ASTNode.h"
#include "UIntConstant.h"
#include "VSharp.tab.h"
#include "ExpressionResult.h"
#include "VerilogWriter.h"
#include "DebugContext.h"
#include <stack>
#include <deque>

class FunctionDeclaratorNode;
class FunctionCallNode;
class VSharpCompiler;
class OutputContext;

class ParserContext
{
public:
    ParserContext(const char *pszInputFile, VSharpCompiler* pCompiler);
    ~ParserContext();

    void *pScanner;
    
public:
    void Parse();    
    void Process(OutputContext* pContext);
    
    // Called from parser
    void AddTypeDef(ASTNode *pNode);
    void AddModuleDef(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);
    void AddImport(ASTNode *pNode);    
    void UserAction(void *pLocation, const char *pszText);
    void StartString() { _currentString = ""; }
    void AppendString(char* pszText) { _currentString.push_back(pszText[0]); }
    
    void ReportError(const YYLTYPE &location, const char *pError)
    {
        char errorText[256];
        sprintf(errorText, "Line %d: %s", location.first_line, pError);
        throw std::string(errorText);
    }

    VSharpCompiler* GetCompiler();
    TypeCollection* GetTypeCollection();
    SymbolTable* GetSymbolTable();
    DebugContext* GetDebugContext() { return &_DebugContext; }
    int AddSymbol(const char *pszSymbol);    
    
    // Called from nodes
    const std::string GetLastString() { return _currentString; }
    const std::string& GetSymbolString(int symIndex);

    // Debugging
    void DumpTree();
            
private:
    // The compiler that the context lives in
    VSharpCompiler* _pCompiler;

    // Current string
    std::string _currentString;

    std::deque<std::unique_ptr<ASTNode>> _rootNodes;
    size_t _numStructs;
    size_t _numGlobals;

    // For debugging
    DebugContext _DebugContext;
};

class VSharpCompiler
{
  public:
    VSharpCompiler();

    int AddSymbol(const char *pszSymbol);    
    TypeCollection* GetTypeCollection();
    SymbolTable* GetSymbolTable();
    const std::string& GetSymbolString(int symIndex);
    
    void ImportContext(ParserContext* pChildContext);

  private:
    ParserContext* _pParent;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;
};
