#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"
#include "TypeNode.h"

void FunctionDeclaratorNode::PreVerifyNodeImpl()
{
    // We need to add this here before the children look for it
    GenericTypeInfo* pGenType = nullptr;
    if (_genericIndex != -1)
    {
        pGenType = GetContext()->_typeCollection.AddGenericType(
            _genericIndex,
            this
            );
    }
}

void FunctionDeclaratorNode::VerifyNodeImpl()
{
    //printf("Verifying function declaration of %s\n", GetContext()->_symbols[_symIndex].c_str());

    if (IsEntryPoint())
    {
        GetContext()->SetEntryPoint(this);
    }

    TypeNode *pReturnTypeNode = dynamic_cast<TypeNode *>(GetChild(0));

    // Add function to collection
    GetContext()->_varCollection.AddFunction(
        _symIndex,
        (_genericIndex != -1) ? GetContext()->_typeCollection.GetGenericType(_genericIndex, this) : nullptr,
        pReturnTypeNode->GetTypeInfo());
}

void FunctionDeclaratorNode::PreProcessNodeImpl()
{
    //printf("PreProcessNodeImpl for %s\n", GetContext()->_symbols[_symIndex].c_str());

    // Allocate registers for locals
    for (int i = 0; i < _paramCount; i++)
    {
        FunctionParameterNode *pParam = dynamic_cast<FunctionParameterNode *>(GetChild(i));
    }

    // non-main functions have a prologue
    if (!IsEntryPoint())
    {
        GetContext()->OutputLabel(GetContext()->_symbols[_symIndex].c_str());
    }
}

void FunctionDeclaratorNode::PostProcessNodeImpl()
{
    if (IsEntryPoint())
    {
        GetContext()->OutputInstruction(OpCodes::Stall);
    }
    else
    {
        GetContext()->OutputInstruction(OpCodes::RRet);
    }
}
