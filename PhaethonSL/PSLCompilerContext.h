#pragma once

#include "RegisterCollection.h"
#include "VariableCollection.h"
#include "TypeCollection.h"
#include "../PhaethonObjWriter/ObjWriter.h"

class FunctionDeclaratorNode;

class PSLCompilerContext
{
public:
    PSLCompilerContext(FILE *pFile);
    ~PSLCompilerContext();
    int AddSymbol(const char* pszSymbol);
    void Parse();
    void SetEntryPoint(FunctionDeclaratorNode* pNode);

    void AddStructDef(ASTNode* pNode);
    void AddFuncDef(ASTNode* pNode);
    void AddGlobal(ASTNode* pNode);

    ObjWriter* GetWriter() { return _writer.get(); }

    void* pScanner;
    VariableCollection _varCollection;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;

private:
    std::vector<std::unique_ptr<ASTNode> > _rootNodes;
    std::unique_ptr<BinaryObjWriter> _writer;
    size_t _numStructs;
    size_t _numGlobals;

    // Verification stuff
    FunctionDeclaratorNode* _pEntryPoint;
};
