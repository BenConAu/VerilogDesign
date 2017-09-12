#pragma once

#include "SymbolTable.h"
#include "TypeCollection.h"
#include "ASTNode.h"
#include "UIntConstant.h"
#include "VSharp.tab.h"
#include "ExpressionResult.h"
#include "VerilogWriter.h"
#include <stack>
#include <deque>

class FunctionDeclaratorNode;
class FunctionCallNode;
class VSharpCompiler;

class DebugContext
{
public:
    int _indent = 0;
    
    void PrintIndent()
    {
        for (int i = 0; i < _indent; i++)
        {
            printf("  ");
        }
    }    
};

class OutputContext
{
public:
    OutputContext(const char* pszOutputFile, DebugContext* pDebugContext);

    void OutputLine(
        const char* pszLine
        );

    template<typename... PT> 
    void OutputLine(
        const char* pszLine,
        PT... params
        )
    {
        char line[512];
        sprintf(line, pszLine, params...);
        OutputLine(line);
    }

    void BeginLine();
    void EndLine();

    void OutputString(const char* pszString);

    void IncreaseIndent() { _outputIndent++; }
    void DecreaseIndent() { _outputIndent--; }

    void Finish();

    // Debug
    DebugContext* GetDebugContext() { return _pDebugContext; }

private:
    int _outputIndent = 0;
    
    std::vector<std::unique_ptr<VerilogWriter>> _writers;

    DebugContext* _pDebugContext;
};

class PSLCompilerContext
{
public:
    PSLCompilerContext(const char *pszInputFile, VSharpCompiler* pCompiler);
    ~PSLCompilerContext();

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
    
    void ImportContext(PSLCompilerContext* pChildContext);

  private:
    PSLCompilerContext* _pParent;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;
};
