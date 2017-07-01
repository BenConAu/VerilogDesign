#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"

IdentifierNode::IdentifierNode(PSLCompilerContext *pContext, const YYLTYPE &location, int symIndex) : ExpressionNode(pContext)
{
    _symIndex = symIndex;
    _location = location;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Find the type of the expression
    VariableInfo *pInfo = GetVariableInfo();

    SetType(pInfo->GetTypeInfo());
}

ExpressionResult *IdentifierNode::CalculateResult()
{/*
    VariableInfo *pInfo = GetVariableInfo();
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    return pInfo->CalculateResult(pScope);*/
    return nullptr;
}

VariableInfo *IdentifierNode::GetVariableInfo()
{/*
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();
    VariableInfo *pInfo = dynamic_cast<VariableInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, pScope));
    if (pInfo == nullptr)
    {
        char message[256];
        sprintf(message, "Attempting info get of nonexistent var %s", GetContext()->_symbols[_symIndex].c_str());
        GetContext()->ReportError(_location, message);
    }

    return pInfo;*/
    return nullptr;
}
