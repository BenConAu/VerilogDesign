#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "FunctionDeclaratorNode.h"
#include "StaticTypeInfo.h"

IdentifierNode::IdentifierNode(ParserContext *pContext, const YYLTYPE &location, int symIndex) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _pVarInfo = nullptr;
    _pTypeInfo = nullptr;
}

IdentifierNode::IdentifierNode(
    ParserContext *pContext, 
    const YYLTYPE &location, 
    int symIndex, 
    VariableInfo* pVarInfo,
    TypeInfo* pTypeInfo) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _pVarInfo = pVarInfo;
    _pTypeInfo = pTypeInfo;
}

ASTNode* IdentifierNode::DuplicateNodeImpl(DuplicateType type)
{
    //printf("Duplicating identifier %s\n", GetIdentifierName());

    // Are we in a function?
    FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    if (pFuncDecl != nullptr)
    {
        if (type == DuplicateType::ExpandFunction && pFuncDecl->IsParameter(_symIndex))
        {
            // This was an identifier passed into the function, replace it
            return pFuncDecl->DuplicateParameterIdentifier(_symIndex);            
        }
        else if (type == DuplicateType::ExpandGeneric && pFuncDecl->IsGenericParameter(_symIndex))
        {
            // This was a generic identifier passed into the function, replace it
            return pFuncDecl->DuplicateGenericParameterIdentifier(_symIndex);
        }
    }

    // If no function replacement shenanigans are going on, then duplicate the identifier
    return new IdentifierNode(GetContext(), GetLocation(), _symIndex, _pVarInfo, _pTypeInfo);
}

const char* IdentifierNode::GetIdentifierName()
{
    return GetContext()->GetSymbolString(_symIndex).c_str();
}

void IdentifierNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    std::vector<VariableInfo*> Symbols;
    GetContext()->GetSymbolTable()->GetSymbols(_symIndex, pModule, Symbols);

    if (Symbols.size() == 0)
    {
        _pTypeInfo = GetContext()->GetTypeCollection()->GetEnumType(_symIndex);
        if (_pTypeInfo == nullptr)
        {
            // Check function scope for generic identifiers
            FunctionDeclaratorNode *pFuncScope = GetTypedParent<FunctionDeclaratorNode>();
            GetContext()->GetSymbolTable()->GetSymbols(_symIndex, pFuncScope, Symbols);

            if (Symbols.size() == 0)
            {
                char message[256];
                sprintf(message, "Unknown variable, type or generic param %s", GetIdentifierName());
                GetContext()->ReportError(GetLocation(), message);        
            }

            _pVarInfo = Symbols[0];

            SetType(_pVarInfo->GetTypeInfo());
        }
        else
        {
            // HACK should store this somewhere else
            SetType(new StaticTypeInfo(_pTypeInfo));
        }
    }
    else
    {
        _pVarInfo = Symbols[0];

        SetType(_pVarInfo->GetTypeInfo());
    }
}

ExpressionResult *IdentifierNode::CalculateResult()
{
    if (_pVarInfo != nullptr)
    {
        return _pVarInfo->CalculateResult();
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

VariableInfo* IdentifierNode::IsVariableExpression()
{
    return _pVarInfo;
}

bool IdentifierNode::ConstEvaluate(UIntConstant* pVal)
{
    // Need to be defined as const
    if (_pVarInfo != nullptr && _pVarInfo->GetModifier() == TypeModifier::Const)
    {
        (*pVal) = _pVarInfo->GetInitialValue();
        return true;
    }

    return false;
}
