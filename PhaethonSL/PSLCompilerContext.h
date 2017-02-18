#pragma once

#include "RegisterCollection.h"
#include "SymbolTable.h"
#include "TypeCollection.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "Operand.h"
#include "ASTNode.h"
#include "PSL.tab.h"
#include "ExpressionResult.h"

class FunctionDeclaratorNode;

class PSLCompilerContext
{
  public:
    PSLCompilerContext(
        FILE *pFile,
        const char *pszAsmName,
        const char *pszObjName,
        const char *pszBinName);

    ~PSLCompilerContext();
    void UserAction(void *pLocation, const char *pszText);
    int AddSymbol(const char *pszSymbol);
    void Parse();
    void SetEntryPoint(FunctionDeclaratorNode *pNode);

    void AddStructDef(ASTNode *pNode);
    void AddFuncDef(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);

    void OutputInstruction(
        OpCode opCode,
        const ExpressionResult &a1 = ExpressionResult(),
        const ExpressionResult &a2 = ExpressionResult(),
        const ExpressionResult &a3 = ExpressionResult());

    void OutputMovInstruction(
        const ExpressionResult &a1,
        const ExpressionResult &a2);

    void OutputLabel(
        const char *pszLabel);

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
    std::vector<std::unique_ptr<ObjWriter>> _writers;
    size_t _numStructs;
    size_t _numGlobals;

    // Verification stuff
    FunctionDeclaratorNode *_pEntryPoint;
};
