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

class OutputContext
{
public:
    OutputContext(const char* pszOutputFile, DebugContext* pDebugContext);

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

    void OutputString(const char* pszString);

    void IncreaseIndent() { _outputIndent++; }
    void DecreaseIndent() { _outputIndent--; }

    void Finish();

    // Debug
    DebugContext* GetDebugContext() { return _pDebugContext; }

private:
    int _outputIndent = 0;
    
    std::vector<std::unique_ptr<VerilogWriter>> _writers;

    DebugContext* _pDebugContext;
};
