#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"

IdentifierNode::IdentifierNode(PSLCompilerContext* pContext, int symIndex) : ExpressionNode(pContext)
{
    _symIndex = symIndex;
}

void IdentifierNode::VerifyNodeImpl()
{
    // Find the type of the expression
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);

    SetType(pInfo->GetTypeInfo());
}

void IdentifierNode::PreProcessNodeImpl()
{
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);

    // If the variable is memory then we need to put in a register
    if (pInfo->GetLocationType() == LocationType::Memory)
    {
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();
        RegIndex regIndex = pInfo->GetRegIndex(pScope);

        if (pInfo->GetTypeInfo()->IsBasic())
        {
            // Basic types by value
            printf("mov r%d, %s\n", regIndex, GetContext()->_symbols[_symIndex].c_str());
        }
        else
        {
            // Structs by reference
            printf("mov r%d, &%s\n", regIndex, GetContext()->_symbols[_symIndex].c_str());
        }
    }
}

void IdentifierNode::ProcessWrite(RegIndex valueIndex)
{
    // If we are reading, then set up the register if need be
    if (GetExpressionType() == ExpressionType::Write)
    {
        VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);
        FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();

        // If the variable is memory then we need to put it back from the register
        if (pInfo->GetLocationType() == LocationType::Memory)
        {
            if (pInfo->GetTypeInfo()->IsBasic())
            {
                // Basic types by value
                printf("mov %s, r%d\n", GetContext()->_symbols[_symIndex].c_str(), valueIndex);
            }
            else
            {
                printf("mov &%s, r%d\n", GetContext()->_symbols[_symIndex].c_str(), valueIndex);
            }
        }
        else
        {
            RegIndex regIndex = pInfo->GetRegIndex(pScope);

            printf("mov r%d, r%d\n", regIndex, valueIndex);
        }
    }
}

RegIndex IdentifierNode::CalcResultLocationImpl()
{
    VariableInfo* pInfo = GetContext()->_varCollection.GetInfo(_symIndex);
    FunctionDeclaratorNode* pScope = GetTypedParent<FunctionDeclaratorNode>();
    return pInfo->GetRegIndex(pScope);
}
