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
    // Add module to collection
    GetContext()->_symbolTable.AddModule(
        _symIndex,
        nullptr
        );
}

void ModuleDeclaratorNode::PreProcessNodeImpl()
{
    // Spit out the preamble
    ModuleInfo* pInfo = dynamic_cast<ModuleInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, nullptr));
    GetContext()->OutputLine("module %s", pInfo->GetSymbol());
    GetContext()->OutputLine("begin");
    GetContext()->IncreaseIndent();
}

void ModuleDeclaratorNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
