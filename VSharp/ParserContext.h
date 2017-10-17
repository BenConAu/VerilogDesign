#pragma once

#include "SymbolTable.h"
#include "TypeCollection.h"
#include "ASTNode.h"
#include "UIntConstant.h"
#include "VSharp.tab.h"
#include "ExpressionResult.h"
#include "VerilogWriter.h"
#include "DebugContext.h"
#include <stack>
#include <deque>

class FunctionDeclaratorNode;
class FunctionCallNode;
class VSharpCompiler;
class OutputContext;

class ParserContext
{
public:
    ParserContext(const char *pszInputFile, VSharpCompiler* pCompiler);
    ~ParserContext();

    void *pScanner;
    
public:
    void Parse();    
    void Process(OutputContext* pContext);
    
    // Called from parser
    void AddTypeDef(ASTNode *pNode);
    void AddModuleDef(ASTNode *pNode);
    void AddFunction(ASTNode *pNode);
    void AddGlobal(ASTNode *pNode);
    void AddImport(ASTNode *pNode);    
    void UserAction(void *pLocation, const char *pszText);
    void StartString() { _currentString = ""; }
    void AppendString(char* pszText) { _currentString.push_back(pszText[0]); }
    
    void ReportError(const YYLTYPE &location, const char *pError)
    {
        char errorText[256];
        sprintf(errorText, "File: %s | Line %d: %s", _currentFile.c_str(), location.first_line, pError);
        throw std::string(errorText);
    }

    template<typename... PT> 
    void ReportError(
        const YYLTYPE &location,
        const char* pszLine,
        PT... params
        )
    {
        char line[512];
        sprintf(line, pszLine, params...);
        ReportError(location, line);
    }    

    VSharpCompiler* GetCompiler() { return _pCompiler; }
    TypeCollection* GetTypeCollection();
    SymbolTable* GetSymbolTable();
    DebugContext* GetDebugContext();
    int AddSymbol(const char *pszSymbol);    
    
    // Called from nodes
    const std::string GetLastString() { return _currentString; }
    const std::string& GetSymbolString(int symIndex);
    const std::string& GetCurrentFile() { return _currentFile; }
    
    // Debugging
    void DumpTree();
            
private:
    // The compiler that the context lives in
    VSharpCompiler* _pCompiler;

    // Current string
    std::string _currentString;

    // The file that we are parsing
    std::string _currentFile;

    std::deque<std::unique_ptr<ASTNode>> _rootNodes;
    size_t _numStructs;
    size_t _numGlobals;
};
