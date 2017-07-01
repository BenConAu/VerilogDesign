#include "ModuleDeclaratorNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "StatementListNode.h"
#include "ReturnNode.h"
#include "VariableInfo.h"

void ModuleDeclaratorNode::PreVerifyNodeImpl()
{
    // We need to add this here before the children look for it
    GenericTypeInfo *pGenType = nullptr;
    if (_genericIndex != -1)
    {
        /*pGenType = GetContext()->_typeCollection.AddGenericType(
            _genericIndex,
            this);*/
    }
}

void ModuleDeclaratorNode::VerifyNodeImpl()
{
    //printf("Verifying function declaration of %s\n", GetContext()->_symbols[_symIndex].c_str());

    TypeNode *pReturnTypeNode = dynamic_cast<TypeNode *>(GetChild(0));

    // Add function to collection
    GetContext()->_symbolTable.AddFunction(
        _symIndex,
        nullptr,
        pReturnTypeNode->GetTypeInfo());
}

void ModuleDeclaratorNode::PreProcessNodeImpl()
{
    //printf("PreProcessNodeImpl for %s\n", GetContext()->_symbols[_symIndex].c_str());

    // Allocate registers for locals
    /*for (int i = 0; i < _paramCount; i++)
    {
        FunctionParameterNode *pParam = dynamic_cast<FunctionParameterNode *>(GetChild(i));
    }

    // non-main functions have a prologue
    if (!IsEntryPoint())
    {
        GetContext()->OutputLabel(GetContext()->_symbols[_symIndex].c_str());
    }

    // Find variables that need preloading of registers
    std::vector<VariableInfo *> varList;
    GetContext()->_symbolTable.GetFunctionVariables(this, varList);

    for (size_t i = 0; i < varList.size(); i++)
    {
        if (varList[i]->GetFunctionInfo(this)._referenced)
        {
            // Allocate and preload the register
            RegIndex baseRegister = varList[i]->EnsureRegister(this, nullptr);

            // A result that represents the address of the struct
            ExpressionResult varConstant(Operand(varList[i], GetContext()));

            // It is a pointer or some other non-array thing that we can get
            GetContext()->OutputMovInstruction(
                Operand(baseRegister),
                varConstant);
        }
    }*/
}

void ModuleDeclaratorNode::PostProcessNodeImpl()
{
/*    if (IsEntryPoint())
    {
        GetContext()->OutputInstruction(OpCode::Exit);
    }*/
}
