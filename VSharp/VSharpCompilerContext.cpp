#include "VSharpCompilerContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"
#define YY_EXTRA_TYPE ParserContext *
#include "lex.h"

VSharpCompiler::VSharpCompiler() : _symbolTable(this)
{
    _symbolTable.AddBuiltin();    
}

OutputContext::OutputContext(const char* pszOutputFile, DebugContext* pDebugContext)
{
    _writers.push_back(std::unique_ptr<VerilogWriter>(new VerilogWriter(pszOutputFile)));
    _pDebugContext = pDebugContext;
}

ParserContext::ParserContext(const char *pszInputFile, VSharpCompiler* pCompiler)
{
	FILE *pFile = ::fopen(pszInputFile, "r");

    _pCompiler = pCompiler;
    _numStructs = 0;
    _numGlobals = 0;

    yylex_init(&pScanner);
    yyset_extra(this, pScanner);

    // set flex to read from file instead of defaulting to STDIN:
    yyrestart(pFile, pScanner);
}

ParserContext::~ParserContext()
{
    yylex_destroy(pScanner);
}

int ParserContext::AddSymbol(const char *pszSymbol)
{
    return _pCompiler->AddSymbol(pszSymbol);
}

int VSharpCompiler::AddSymbol(const char *pszSymbol)
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

void ParserContext::AddTypeDef(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    // Insert at end of struct list
    _rootNodes.insert(rootStart + _numStructs, std::unique_ptr<ASTNode>(pNode));

    // Seam moves along by 1
    _numStructs++;
}

void ParserContext::AddGlobal(ASTNode *pNode)
{
    auto rootStart = _rootNodes.begin();

    _rootNodes.insert(rootStart + _numStructs + _numGlobals, std::unique_ptr<ASTNode>(pNode));

    _numGlobals++;
}

void ParserContext::AddModuleDef(ASTNode *pNode)
{
    // Just tack onto the end
    _rootNodes.push_back(std::unique_ptr<ASTNode>(pNode));
}

void ParserContext::AddImport(ASTNode *pNode)
{
    _rootNodes.push_front(std::unique_ptr<ASTNode>(pNode));
}

void ParserContext::Parse()
{
    //printf("Doing Bison parse\n");

    // Parse through the input until there is no more:
    yyparse(this);

    //printf("Doing Verify pass\n");

    // Verify the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->VerifyNode(&_DebugContext);
    }
}

void ParserContext::Process(OutputContext* pContext)
{
    //printf("Doing Process pass\n");
    //DumpTree();

    // Process the tree
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->ProcessNode(pContext);
    }
}

void OutputContext::Finish()
{
    //printf("Doing Finish pass\n");

    // Code output is complete
    for (size_t i = 0; i < _writers.size(); i++)
    {
        _writers[i]->FinishCode();
    }
}

void ParserContext::UserAction(void *pVoidLocation, const char *pszText)
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

void OutputContext::OutputString(const char *pszLabel)
{
    for (int i = 0; i < _writers.size(); i++)
    {
        _writers[i]->OutputString(pszLabel);
    }
}

void OutputContext::OutputLine(
    const char* pszLine
    )
{
    BeginLine();
    OutputString(pszLine);
    EndLine();
}

void OutputContext::BeginLine()
{
    for (int i = 0; i < _outputIndent; i++)
    {
        OutputString("  ");
    }
}

void OutputContext::EndLine()
{
    OutputString("\n");
}

void ParserContext::DumpTree()
{
    printf("Dumping tree\n");
    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->DumpNode(&_DebugContext);
    }    
}

const std::string& VSharpCompiler::GetSymbolString(int symIndex) 
{
    return _symbols[symIndex];         
}

const std::string& ParserContext::GetSymbolString(int symIndex) 
{
    return _pCompiler->GetSymbolString(symIndex);         
}

TypeCollection* VSharpCompiler::GetTypeCollection() 
{
    return &_typeCollection;
}

TypeCollection* ParserContext::GetTypeCollection() 
{
    return _pCompiler->GetTypeCollection();
}

SymbolTable* VSharpCompiler::GetSymbolTable() 
{ 
    return &_symbolTable; 
}

SymbolTable* ParserContext::GetSymbolTable() 
{ 
    return _pCompiler->GetSymbolTable(); 
}
