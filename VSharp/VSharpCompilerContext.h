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

class PSLCompilerContext
{
  public:
    PSLCompilerContext(
        const char *pszInput);

    ~PSLCompilerContext();
    void UserAction(void *pLocation, const char *pszText);
    int AddSymbol(const char *pszSymbol);
    void Parse();
    void SetEntryPoint(FunctionDeclaratorNode *pNode);

    void AddTypeDef(ASTNode *pNode);
    void AddModuleDef(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);
    void AddImport(ASTNode *pNode);

    void OutputString(
        const char* pszString);

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

    void IncreaseIndent() { _outputIndent++; }
    void DecreaseIndent() { _outputIndent--; }

    int _indent = 0;
    void *pScanner;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;

    void PrintIndent()
    {
        for (int i = 0; i < _indent; i++)
        {
            printf("  ");
        }
    }

    void ReportError(const YYLTYPE &location, const char *pError)
    {
        char errorText[256];
        sprintf(errorText, "Line %d: %s", location.first_line, pError);
        throw std::string(errorText);
    }

    void StartString() { _currentString = ""; }
    void AppendString(char* pszText) { _currentString.push_back(pszText[0]); }
    const std::string GetLastString() { return _currentString; }

    void DumpTree();

  private:
    std::deque<std::unique_ptr<ASTNode>> _rootNodes;
    std::vector<std::unique_ptr<VerilogWriter>> _writers;
    size_t _numStructs;
    size_t _numGlobals;
    int _outputIndent = 0;

    // Verification stuff
    FunctionDeclaratorNode *_pEntryPoint;

    // Current string
    std::string _currentString;
};
