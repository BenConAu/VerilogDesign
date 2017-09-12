#include "ModuleDefinitionNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleTypeInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"
#include "FunctionDeclaratorNode.h"

ModuleDefinitionNode::ModuleDefinitionNode(
    PSLCompilerContext* pContext, 
    const YYLTYPE &location,
    int symIndex,
    int genericSym
    ) : ASTNode(pContext, location)
{
    _symIndex = symIndex;
    _genericIndex = genericSym;
}

void ModuleDefinitionNode::PreVerifyNodeImpl()
{
    // We need to add this here before the children look for it
    GenericTypeInfo *pGenType = nullptr;
    if (_genericIndex != -1)
    {
        /*pGenType = GetContext()->GetTypeCollection()->AddGenericType(
            _genericIndex,
            this);*/
    }

    // We are going to add all of the children of the list node to be
    // children of the module node, since in Verilog the states become
    // cases of a case statement and the member variables become
    // declarations right next to the parameters.
    ListNode* pModuleChildList = GetTypedChild<ListNode>();
    size_t ListIndex = GetChildCount() - 1;

    // Variable declarations moved to be before all other things so that
    // the variable information can be added before any states or functions
    // try to get at it.
    MoveListChildren<VariableDeclarationNode>(pModuleChildList, GetChildCount());
    MoveListChildren<ASTNode>(pModuleChildList, GetChildCount());

    if (pModuleChildList->GetChildCount() != 0)
    {
        printf("List is %d long\n", (int)pModuleChildList->GetChildCount());

        throw "Internal compiler error, unexpected children left in module";
    }

    // No longer need the list
    delete ExtractChild(ListIndex);

    // Add all of the states into a list - the initial state has
    // value zero, but all other states start at this number and
    // work their way up.
    _stateList.resize(1);

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        if (pState != nullptr)
        {
            // Initial state is special
            if (pState->GetIdentifier() == -1)
            {
                _stateList[0] = pState;
            }
            else
            {
                _stateList.push_back(pState);
            }
        }

        ModuleParameterNode* pParam = dynamic_cast<ModuleParameterNode*>(GetChild(i));
        if (pParam != nullptr)
        {
            _paramList.push_back(pParam);
        }
    }
}

void ModuleDefinitionNode::VerifyNodeImpl()
{
    ModuleTypeInfo* pNewType = new ModuleTypeInfo(_symIndex, this);
    GetContext()->GetTypeCollection()->AddModuleType(_symIndex, pNewType);
}

bool ModuleDefinitionNode::PreProcessNodeImpl(OutputContext* pContext)
{
    // Spit out the preamble
    ModuleTypeInfo* pInfo = GetContext()->GetTypeCollection()->GetModuleType(_symIndex);
    pContext->OutputLine("module %s(", GetContext()->GetSymbolString(_symIndex).c_str());
    pContext->IncreaseIndent();

//    GetContext()->OutputLine("reset,");

    bool first = true;

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        ModuleParameterNode* pParam = dynamic_cast<ModuleParameterNode*>(GetChild(i));
        if (pParam != nullptr)
        {
            const char* pszComma = (i != _paramList.size() - 1) ? "," : "";

            // Only the first can be the first
            first = false;

            pContext->OutputLine(
                "%s%s", 
                GetContext()->GetSymbolTable()->GetInfo(pParam->GetSymbolIndex(), this)->GetSymbol(), 
                pszComma);
        }

    }

    pContext->OutputLine(");");

    // Define states so they are readable
    pContext->OutputLine("// State definitions");
    for (size_t i = 0; i < _stateList.size(); i++)
    {
        const char* pszStateName = (i == 0) ? "initial" : GetContext()->GetSymbolTable()->GetInfo(_stateList[i]->GetIdentifier(), this)->GetSymbol();

        pContext->OutputLine(
            "`define __%s %d", 
            pszStateName,
            i);
    }

    // All modules have a reset and a clock
    pContext->OutputLine("// inputs / outputs");
    pContext->OutputLine("input wire reset;");

    return true;
}

void ModuleDefinitionNode::ProcessNodeImpl(OutputContext* pContext)
{
    bool fParamsDone = false;
    bool fVariablesDone = false;

    // Do all non-state things first
    for (size_t i = 0; i < GetChildCount(); i++)
    {
        // Figure out what we have here
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        if (pState == nullptr)
        {
            GetChild(i)->ProcessNode(pContext);
        }
    }

    // We have a register that we store the current state in
    pContext->OutputLine("reg [7:0] fsmState = 0;");

    // Start the always block
    pContext->OutputLine("always @(posedge clk)");
    pContext->OutputLine("begin");
    pContext->IncreaseIndent();

    // Start the case statement
    pContext->OutputLine("case(fsmState)");
    pContext->IncreaseIndent();

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        // Figure out what we have here
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        if (pState != nullptr)
        {
            GetChild(i)->ProcessNode(pContext);
        }
    }

    // End the case statement
    pContext->DecreaseIndent();
    pContext->OutputLine("endcase");

    // End the always statement
    pContext->DecreaseIndent();
    pContext->OutputLine("end");
}

void ModuleDefinitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // End the module
    pContext->DecreaseIndent();
    pContext->OutputLine("endmodule");
}
