#include "ModuleDeclaratorNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "VariableDeclarationNode.h"

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

    ListNode* pModuleChildList = GetTypedChild<ListNode>();

    // Sort so that declarations are always first
    size_t Insert = 0;
    for (size_t i = 0; i < pModuleChildList->GetChildCount(); i++)
    {
        VariableDeclarationNode* pDecl = dynamic_cast<VariableDeclarationNode*>(pModuleChildList->GetChild(i));
        if (pDecl != nullptr)
        {
            //printf("Swapping child to %d\n", (int)i);
            pModuleChildList->MoveChild(i, Insert);
            Insert++;
        }
    }
}

void ModuleDeclaratorNode::VerifyNodeImpl()
{
    // Add function to collection
    GetContext()->_symbolTable.AddModule(
        _symIndex,
        nullptr
        );
}

void ModuleDeclaratorNode::PreProcessNodeImpl()
{
    

    //GetContext()->OutputString("")
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
    char starter[100];

    ModuleInfo* pInfo = dynamic_cast<ModuleInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, nullptr));

    sprintf(starter, "module %s\nbegin\n", pInfo->GetSymbol());
    
    GetContext()->OutputString(starter);
}
