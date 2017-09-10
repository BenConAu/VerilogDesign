#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "FunctionDeclaratorNode.h"
#include "StaticTypeInfo.h"

IdentifierNode::IdentifierNode(PSLCompilerContext *pContext, const YYLTYPE &location, int symIndex) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _pVarInfo = nullptr;
    _pTypeInfo = nullptr;
}

IdentifierNode::IdentifierNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location, 
    int symIndex, 
    VariableInfo* pVarInfo,
    TypeInfo* pTypeInfo) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _pVarInfo = pVarInfo;
    _pTypeInfo = pTypeInfo;
}

ASTNode* IdentifierNode::DuplicateNodeImpl()
{
    //printf("Duplicating identifier %s\n", GetIdentifierName());

    // Are we in a function?
    FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    if (pFuncDecl != nullptr && pFuncDecl->IsParameter(_symIndex))
    {
        return pFuncDecl->DuplicateParameterIdentifier(_symIndex);
    }
    else
    {
        return new IdentifierNode(GetContext(), GetLocation(), _symIndex, _pVarInfo, _pTypeInfo);
    }
}

const char* IdentifierNode::GetIdentifierName()
{
    return GetContext()->_symbols[_symIndex].c_str();
}

void IdentifierNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pScope = GetTypedParent<ModuleDefinitionNode>();
    _pVarInfo = dynamic_cast<VariableInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, pScope));
    if (_pVarInfo == nullptr)
    {
        _pTypeInfo = GetContext()->_typeCollection.GetEnumType(_symIndex);
        if (_pTypeInfo == nullptr)
        {
            char message[256];
            sprintf(message, "Unknown variable or type %s", GetIdentifierName());
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
    if (_pVarInfo != nullptr)
    {
        ModuleDefinitionNode *pScope = GetTypedParent<ModuleDefinitionNode>();
        
        return _pVarInfo->CalculateResult(pScope);
    }
    else
    {
        return new ExpressionResult(dynamic_cast<StaticTypeInfo*>(GetTypeInfo()));
    }
}

VariableInfo *IdentifierNode::GetVariableInfo()
{
    return _pVarInfo;
}
