#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "FunctionDeclaratorNode.h"

IdentifierNode::IdentifierNode(PSLCompilerContext *pContext, const YYLTYPE &location, int symIndex) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Find the type of the expression
    VariableInfo *pInfo = GetVariableInfo();

    SetType(pInfo->GetTypeInfo());
}

ExpressionResult *IdentifierNode::CalculateResult()
{
    // Are we in a function?
    FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    if (pFuncDecl != nullptr)
    {
        // The function knows how to make the actual result that we want - 
        // pass the symbol index that was used to define the function and ask it
        // to make the result.
        return pFuncDecl->ResultFromSymbol(_symIndex);
    }
    else
    {
        VariableInfo *pInfo = GetVariableInfo();
        ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();

        return pInfo->CalculateResult(pScope);
    }
}

VariableInfo *IdentifierNode::GetVariableInfo()
{
    ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();
    VariableInfo *pInfo = dynamic_cast<VariableInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, pScope));
    if (pInfo == nullptr)
    {
        char message[256];
        sprintf(message, "Attempting info get of nonexistent var %s", GetContext()->_symbols[_symIndex].c_str());
        GetContext()->ReportError(GetLocation(), message);
    }

    return pInfo;
}
