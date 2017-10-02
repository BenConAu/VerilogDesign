#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
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

    // Are we in a function that 
    FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    if (pFuncDecl != nullptr)
    {
        if (type == DuplicateType::ExpandFunction && pFuncDecl->GetDuplicateType() == type && pFuncDecl->IsParameter(_symIndex))
        {
            // This was an identifier passed into the function, replace it
            return pFuncDecl->DuplicateParameterIdentifier(_symIndex);            
        }
        else if (type == DuplicateType::ExpandGeneric && pFuncDecl->GetDuplicateType() == type && pFuncDecl->IsGenericParameter(_symIndex))
        {
            // This was a generic identifier passed into the function, replace it
            return pFuncDecl->DuplicateGenericParameterIdentifier(_symIndex);
        }
        else if (type == DuplicateType::ExpandStageNonblocking)
        {
            // Referring to the input of a stage has the same effect as calling
            // the stage that produces this input as a function. So the logic here mirrors
            // that of a function call when called for duplication.

            // First find the statement that initiated the duplication in the first place  - 
            // it might not be the first one up the tree.
            StatementNode* pStatementNode = GetTypedParent<StatementNode>(); 
            while (pStatementNode != nullptr && pStatementNode->GetIdentifierNode() == nullptr)
            {
                pStatementNode = pStatementNode->GetTypedParent<StatementNode>();
            }

            // Now make sure that it is the same identifier if we found a statement
            if (pStatementNode != nullptr && this == pStatementNode->GetIdentifierNode())
            {
                // Replace the call with the expression we were given from the return statement
                return pStatementNode->GetReplacementNode()->DuplicateNode(type);
            }
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
