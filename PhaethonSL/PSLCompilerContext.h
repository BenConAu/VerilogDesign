#pragma once

#include "RegisterCollection.h"
#include "VariableCollection.h"
#include "TypeCollection.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "Operand.h"

class FunctionDeclaratorNode;

class PSLCompilerContext
{
  public:
    PSLCompilerContext(
        FILE *pFile,
        const char *pszAsmName,
        const char *pszObjName);

    ~PSLCompilerContext();
    int AddSymbol(const char *pszSymbol);
    void Parse();
    void SetEntryPoint(FunctionDeclaratorNode *pNode);

    void AddStructDef(ASTNode *pNode);
    void AddFuncDef(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);

    void OutputInstruction(
        OpCodes::Enum opCode,
        const Operand &a1 = Operand(),
        const Operand &a2 = Operand(),
        const Operand &a3 = Operand());

    void OutputMovInstruction(
        const Operand &a1,
        const Operand &a2);

    void OutputLabel(
        const char *pszLabel);

    void *pScanner;
    VariableCollection _varCollection;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;

  private:
    std::vector<std::unique_ptr<ASTNode>> _rootNodes;
    std::vector<std::unique_ptr<ObjWriter>> _writers;
    size_t _numStructs;
    size_t _numGlobals;

    // Verification stuff
    FunctionDeclaratorNode *_pEntryPoint;
};
