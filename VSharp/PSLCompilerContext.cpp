#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext *
#include "lex.h"

PSLCompilerContext::PSLCompilerContext(
    const char *pszInputFile
    ) : _symbolTable(this)
{
	FILE *pFile = ::fopen(pszInputFile, "r");

    _pEntryPoint = nullptr;
    _numStructs = 0;
    _numGlobals = 0;

    _symbolTable.AddBuiltin();

    std::string base = pszInputFile;
    base = base.substr(0, base.length() - 3);

    _writers.push_back(std::unique_ptr<VerilogWriter>(new VerilogWriter((base + ".sv").c_str())));

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

void PSLCompilerContext::AddModuleDef(ASTNode *pNode)
{
    // Just tack onto the end
    _rootNodes.push_back(std::unique_ptr<ASTNode>(pNode));
}

void PSLCompilerContext::Parse()
{
    //printf("Doing Bison parse\n");

    // Parse through the input until there is no more:
    yyparse(this);

    //printf("Doing Verify pass\n");

    // Verify the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->VerifyNode();
    }

    //printf("Doing Process pass\n");

    // Before processing, reorder things so that the entry point is before
    // all of the other functions. It needs to have the code first, because
    // it is an entry point after all.
    for (size_t i = _numStructs + _numGlobals + 1; i < _rootNodes.size(); i++)
    {
        // Add after most recent function node unless it is main
        ModuleDeclaratorNode *pModuleNode = dynamic_cast<ModuleDeclaratorNode *>(_rootNodes[i].get());

        if (pModuleNode->IsEntryPoint())
        {
            //printf("Moving entry point\n");
            std::unique_ptr<ASTNode> temp = std::move(_rootNodes[i]);
            _rootNodes[i] = std::move(_rootNodes[_numStructs + _numGlobals]);
            _rootNodes[_numStructs + _numGlobals] = std::move(temp);
        }
    }

    // Process the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->ProcessNode();
    }

    //printf("Doing Finish pass\n");

    // Code output is complete
    for (size_t i = 0; i < _writers.size(); i++)
    {
        _writers[i]->FinishCode();
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

void PSLCompilerContext::UserAction(void *pVoidLocation, const char *pszText)
{
    YYLTYPE *pLocation = (YYLTYPE *)pVoidLocation;

    pLocation->first_line = pLocation->last_line;
    pLocation->first_column = pLocation->last_column;
    for (int i = 0; pszText[i] != '\0'; i++)
    {
        if (pszText[i] == '\n')
        {
            pLocation->last_line++;
            pLocation->last_column = 0;
        }
        else
        {
            pLocation->last_column++;
        }
    }
}

void PSLCompilerContext::OutputString(const char *pszLabel)
{
    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputString(pszLabel);
    }
}

