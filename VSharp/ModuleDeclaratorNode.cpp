#include "ModuleDeclaratorNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"

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

    // We are going to add all of the children of the list node to be
    // children of the module node, since in Verilog the states become
    // cases of a case statement and the member variables become
    // declarations right next to the parameters.
    ListNode* pModuleChildList = GetTypedChild<ListNode>();
    size_t ListIndex = GetChildCount() - 1;

    // Add the declarations first after the parameters
    MoveListChildren<VariableDeclarationNode>(pModuleChildList, GetChildCount());

    // Then add the states after that
    MoveListChildren<StateDeclaratorNode>(pModuleChildList, GetChildCount());

    if (pModuleChildList->GetChildCount() != 0)
    {
        printf("List is %d long\n", (int)pModuleChildList->GetChildCount());

        throw "Internal compiler error, unexpected children left in module";
    }

    // No longer need the list
    delete ExtractChild(ListIndex);
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

void ModuleDeclaratorNode::ProcessNodeImpl()
{
    bool fVariablesDone = false;

    // Get all of the parameters first
    for (size_t i = 0; i < GetChildCount(); i++)
    {
        // Figure out what we have here
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        //printf("Processing state %p\n", pState);

        if (pState != nullptr && !fVariablesDone)
        {
            // Before we do states we have a preamble
            fVariablesDone = true;

            GetContext()->OutputLine("always @(posedge clk)");
            GetContext()->OutputLine("begin");
            GetContext()->IncreaseIndent();
        }

        GetChild(i)->ProcessNode();
    }

    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}

void ModuleDeclaratorNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
