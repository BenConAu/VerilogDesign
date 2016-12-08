#include "VariablePath.h"
#include "FunctionDeclaratorNode.h"
#include <sstream>

const char* VariablePath::DebugPrint()
{
    std::stringstream sstream;

    sstream << _pVarInfo->GetSymbol();
    
    for (size_t i = 0; i < _memberPath.size(); i++)
    {
        sstream << " " << _memberPath[i]->GetSymbolIndex();
    }

    static std::string str = sstream.str();
    return str.c_str();
}