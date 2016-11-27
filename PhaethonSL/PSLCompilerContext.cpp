#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext *
#include "lex.h"
#include "../PhaethonObjWriter/AsmObjWriter.h"

PSLCompilerContext::PSLCompilerContext(FILE *pFile, const char* pszOutName) : _varCollection(this)
{
    _pEntryPoint = nullptr;
    _numStructs = 0;
    _numGlobals = 0;

    _varCollection.AddBuiltin();
    _writers.push_back(std::unique_ptr<ObjWriter>(new AsmObjWriter(pszOutName)));

    yylex_init(&pScanner);
    yyset_extra(this, pScanner);

    // set flex to read from file instead of defaulting to STDIN:
    yyrestart(pFile, pScanner);
}

PSLCompilerContext::~PSLCompilerContext()
{
    yylex_destroy(pScanner);
}

int PSLCompilerContext::AddSymbol(const char *pszSymbol)
{
    //    printf("Adding symbol\n");
    for (size_t i = 0; i < _symbols.size(); i++)
    {
        if (_symbols[i].compare(pszSymbol) == 0)
        {
            return i;
        }
    }

    _symbols.push_back(pszSymbol);
    return (_symbols.size() - 1);
}

void PSLCompilerContext::AddStructDef(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    // Insert at end of struct list
    _rootNodes.insert(rootStart + _numStructs, std::unique_ptr<ASTNode>(pNode));

    // Seam moves along by 1
    _numStructs++;
}

void PSLCompilerContext::AddGlobal(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    _rootNodes.insert(rootStart + _numStructs + _numGlobals, std::unique_ptr<ASTNode>(pNode));

    _numGlobals++;
}

void PSLCompilerContext::AddFuncDef(ASTNode *pNode)
{
    // Add after most recent function node unless it is main
    FunctionDeclaratorNode *pFuncNode = dynamic_cast<FunctionDeclaratorNode *>(pNode);

    if (!pFuncNode->IsEntryPoint())
    {
        // Just tack onto the end
        _rootNodes.push_back(std::unique_ptr<ASTNode>(pNode));
    }
    else
    {
        // Put after the structs
        auto rootStart = _rootNodes.begin();

        // Insert at seam
        _rootNodes.insert(rootStart + _numStructs + _numGlobals, std::unique_ptr<ASTNode>(pNode));
    }
}

void PSLCompilerContext::Parse()
{
    // Parse through the input until there is no more:
    yyparse(this);

    // Verify the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->VerifyNode();
    }

    // Process the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->ProcessNode();
    }
}

void PSLCompilerContext::SetEntryPoint(FunctionDeclaratorNode *pEntryPoint)
{
    if (_pEntryPoint != nullptr)
    {
        throw "Cannot have two entry points";
    }

    _pEntryPoint = pEntryPoint;
}

void PSLCompilerContext::OutputInstruction(
    OpCodes::Enum opCode,
    const Operand &a1,
    const Operand &a2,
    const Operand &a3
    )
{
    ObjArgument args[] = {
        a1.GetObjArgument(),
        a2.GetObjArgument(),
        a3.GetObjArgument()
    };

    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputInstruction(opCode, args);
    }
}

void PSLCompilerContext::OutputLabel(const char* pszLabel)
{
    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputLabel(pszLabel);
    }
}