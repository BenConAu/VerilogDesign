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
    int symIndex,
    int genericSym
    ) : ASTNode(pContext)
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
    GetContext()->_typeCollection.AddModuleType(_symIndex, pNewType);
}

bool ModuleDefinitionNode::PreProcessNodeImpl()
{
    // Spit out the preamble
    ModuleTypeInfo* pInfo = GetContext()->_typeCollection.GetModuleType(_symIndex);
    GetContext()->OutputLine("module %s(", GetContext()->_symbols[_symIndex].c_str());
    GetContext()->IncreaseIndent();

    GetContext()->OutputLine("reset,");

    bool first = true;

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        ModuleParameterNode* pParam = dynamic_cast<ModuleParameterNode*>(GetChild(i));
        if (pParam != nullptr)
        {
            const char* pszComma = (i != _paramList.size() - 1) ? "," : "";

            // Only the first can be the first
            first = false;

            GetContext()->OutputLine(
                "%s%s", 
                GetContext()->_symbolTable.GetInfo(pParam->GetSymbolIndex(), this)->GetSymbol(), 
                pszComma);
        }

    }

    GetContext()->OutputLine(");");

    // Define states so they are readable
    GetContext()->OutputLine("// State definitions");
    for (size_t i = 0; i < _stateList.size(); i++)
    {
        const char* pszStateName = (i == 0) ? "initial" : GetContext()->_symbolTable.GetInfo(_stateList[i]->GetIdentifier(), this)->GetSymbol();

        GetContext()->OutputLine(
            "`define __%s %d", 
            pszStateName,
            i);
    }

    // All modules have a reset and a clock
    GetContext()->OutputLine("// inputs / outputs");
    GetContext()->OutputLine("input wire reset;");

    return true;
}

void ModuleDefinitionNode::ProcessNodeImpl()
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
            GetChild(i)->ProcessNode();
        }
    }

    // We have a register that we store the current state in
    GetContext()->OutputLine("reg [7:0] fsmState = 0;");

    // Start the always block
    GetContext()->OutputLine("always @(posedge clk)");
    GetContext()->OutputLine("begin");
    GetContext()->IncreaseIndent();

    // Start the case statement
    GetContext()->OutputLine("case(fsmState)");
    GetContext()->IncreaseIndent();

    for (size_t i = 0; i < GetChildCount(); i++)
    {
        // Figure out what we have here
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        if (pState != nullptr)
        {
            GetChild(i)->ProcessNode();
        }
    }

    // End the case statement
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("endcase");

    // End the always statement
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}

void ModuleDefinitionNode::PostProcessNodeImpl()
{
    // End the module
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("endmodule");
}
