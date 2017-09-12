#pragma once

#include "SymbolTable.h"
#include "TypeCollection.h"
#include "ASTNode.h"
#include "UIntConstant.h"
#include "VSharp.tab.h"
#include "ExpressionResult.h"
#include "VerilogWriter.h"
#include <stack>
#include <deque>

class FunctionDeclaratorNode;
class FunctionCallNode;
class VSharpCompiler;

class DebugContext
{
public:
    int _indent = 0;
    
    void PrintIndent()
    {
        for (int i = 0; i < _indent; i++)
        {
            printf("  ");
        }
    }    
};
