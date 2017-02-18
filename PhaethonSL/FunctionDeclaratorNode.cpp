#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"
#include "TypeNode.h"
#include "StatementListNode.h"
#include "ReturnNode.h"

void FunctionDeclaratorNode::PreVerifyNodeImpl()
{
    // We need to add this here before the children look for it
    GenericTypeInfo *pGenType = nullptr;
    if (_genericIndex != -1)
    {
        pGenType = GetContext()->_typeCollection.AddGenericType(
            _genericIndex,
            this);
    }

    //for (size_t i = 0; i < GetChildCount(); i++)
    //{
    //  printf("FuncDecl child %d is %s\n", (int)i, GetChild(i)->GetDebugName());
    //}

    // Add a return node to the end of the function if it does not have one
    if (!IsEntryPoint())
    {
        StatementListNode *pStatementList = dynamic_cast<StatementListNode *>(GetChild(GetChildCount() - 1));
        ReturnNode *pReturnNode = nullptr;
        if (pStatementList->GetChildCount() != 0)
        {
            pReturnNode = dynamic_cast<ReturnNode *>(pStatementList->GetChild(pStatementList->GetChildCount() - 1));
        }

        if (pReturnNode == nullptr)
        {
            pStatementList->AddNode(new ReturnNode(GetContext(), nullptr));
        }
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
    GetContext()->_symbolTable.AddFunction(
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
        GetContext()->OutputInstruction(OpCode::Stall);
    }
}
