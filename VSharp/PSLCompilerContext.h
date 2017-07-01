#pragma once

#include "RegisterCollection.h"
#include "SymbolTable.h"
#include "TypeCollection.h"
#include "Operand.h"
#include "ASTNode.h"
#include "PSL.tab.h"
#include "ExpressionResult.h"
#include "VerilogWriter.h"

class FunctionDeclaratorNode;

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

    void AddStructDef(ASTNode *pNode);
    void AddFuncDef(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);

    void OutputString(
        const char* pszString);

    void *pScanner;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;
    int _indent = 0;
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

  private:
    std::vector<std::unique_ptr<ASTNode>> _rootNodes;
    std::vector<std::unique_ptr<VerilogWriter>> _writers;
    size_t _numStructs;
    size_t _numGlobals;

    // Verification stuff
    FunctionDeclaratorNode *_pEntryPoint;
};
