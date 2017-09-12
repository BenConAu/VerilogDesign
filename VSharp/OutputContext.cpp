#include "OutputContext.h"
#include "VSharpCompilerContext.h"
#include "ASTTree.h"

OutputContext::OutputContext(const char* pszOutputFile, DebugContext* pDebugContext)
{
    _writers.push_back(std::unique_ptr<VerilogWriter>(new VerilogWriter(pszOutputFile)));
    _pDebugContext = pDebugContext;
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
