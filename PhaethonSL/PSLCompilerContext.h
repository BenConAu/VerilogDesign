#pragma once

#include "RegisterCollection.h"
#include "VariableCollection.h"
#include "TypeCollection.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "Operand.h"
#include "ASTNode.h"
#include "PSL.tab.h"

class FunctionDeclaratorNode;
class ExpressionResult;

class OperandList : public std::vector<Operand>
{
  public:
    OperandList(Operand o) : std::vector<Operand>(1, o)
    {
    }

    OperandList()
    {
    }
};

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
        OpCodes::Enum opCode,
        const OperandList &a1 = OperandList(),
        const OperandList &a2 = OperandList(),
        const OperandList &a3 = OperandList());

    void OutputMovInstruction(
        const OperandList &a1,
        const OperandList &a2);

    void OutputLabel(
        const char *pszLabel);

    void *pScanner;
    VariableCollection _varCollection;
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
