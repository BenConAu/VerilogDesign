#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "FunctionDeclaratorNode.h"
#include "StaticTypeInfo.h"

IdentifierNode::IdentifierNode(PSLCompilerContext *pContext, const YYLTYPE &location, int symIndex) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _pVarInfo = nullptr;
    _pTypeInfo = nullptr;
}

void IdentifierNode::VerifyNodeImpl()
{
    ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();
    _pVarInfo = dynamic_cast<VariableInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, pScope));
    if (_pVarInfo == nullptr)
    {
        _pTypeInfo = GetContext()->_typeCollection.GetEnumType(_symIndex);
        if (_pTypeInfo == nullptr)
        {
            char message[256];
            sprintf(message, "Unknown variable or type %s", GetContext()->_symbols[_symIndex].c_str());
            GetContext()->ReportError(GetLocation(), message);    
        }
        else
        {
            // HACK should store this somewhere else
            SetType(new StaticTypeInfo(_pTypeInfo));
        }
    }
    else
    {
        SetType(_pVarInfo->GetTypeInfo());
    }
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
        if (_pVarInfo != nullptr)
        {
            ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();
            
            return _pVarInfo->CalculateResult(pScope);
        }
        else
        {
            return new ExpressionResult(dynamic_cast<StaticTypeInfo*>(GetTypeInfo()));
        }
    }
}

VariableInfo *IdentifierNode::GetVariableInfo()
{
    return _pVarInfo;
}
