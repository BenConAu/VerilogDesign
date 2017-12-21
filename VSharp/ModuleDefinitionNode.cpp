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
#include "IdentifierNode.h"
#include "OutputContext.h"

ModuleDefinitionNode::ModuleDefinitionNode(
    ParserContext* pContext, 
    const YYLTYPE &location,
    int symIndex,
    ASTNode* pGenericList,
    FunctionExpandType ExpandType
    ) : ASTNode(pContext, location)
{
    AddNode(pGenericList);

    _symIndex = symIndex;
    _IsForward = false;
    _pAlwaysState = nullptr;
    _ExpandType = ExpandType;
}

ModuleType ModuleDefinitionNode::GetModuleType()
{
    //printf(
    //    "Determining module type for module %s with state list size %d and stage list size %d\n", 
    //    GetContext()->GetSymbolString(_symIndex).c_str(), 
    //    (int)_stateList.size(),
    //    (int)_stageList.size());

    //printf("First state is %p\n", _stateList[0]);
    
    if (_stateList.size() == 1 && _stateList[0] == nullptr)
    {
        if (_stageList.size() != 0)
        {
            return ModuleType::DefinedStages;
        }
        else
        {
            // No states and no stages, process like states
            return ModuleType::ExplicitStates;
        }
    }
    else
    {
        if (_stageList.size() == 0)
        {
            return ModuleType::ExplicitStates;
        }
    }

    return ModuleType::Error;
}

bool ModuleDefinitionNode::PreVerifyNodeImpl()
{
    // We need to add these here before the children look for it
    ListNode* pGenericArgList = dynamic_cast<ListNode*>(GetChild(0));
    if (pGenericArgList != nullptr)
    {
        for (size_t i = 0; i < pGenericArgList->GetChildCount(); i++)
        {
            IdentifierNode* pIdent = dynamic_cast<IdentifierNode*>(pGenericArgList->GetChild(i));
            GenericTypeInfo *pGenType = new GenericTypeInfo(pIdent->GetSymbolIndex(), this);
            GetContext()->GetTypeCollection()->AddGenericType(pIdent->GetSymbolIndex(), pGenType);
        }
    }

    ListNode* pModuleChildList = GetTypedChild<ListNode>();

    // No list of statements means forward definition
    if (pModuleChildList != nullptr)
    {
        // We are going to add all of the children of the list node to be
        // children of the module node, since in Verilog the states become
        // cases of a case statement and the member variables become
        // declarations right next to the parameters.
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
    }
    else
    {
        _IsForward = true;
    }

    return true;
}

void ModuleDefinitionNode::VerifyNodeImpl()
{
    // Add all of the states into a list - the initial state has
    // value zero, but all other states start at this number and
    // work their way up.
    _stateList.push_back(nullptr);
    
    for (size_t i = 0; i < GetChildCount(); i++)
    {
        StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
        if (pState != nullptr)
        {
            // Initial state is special
            if (pState->GetKnownState() == KnownStates::Initial)
            {
                _stateList[0] = pState;
            }
            else if (pState->GetKnownState() == KnownStates::Always)
            {
                _pAlwaysState = pState;
            }
            else
            {
                _stateList.push_back(pState);
            }
        }

        FunctionDeclaratorNode* pStage = dynamic_cast<FunctionDeclaratorNode*>(GetChild(i));
        if (pStage != nullptr)
        {
            if (pStage->GetFunctionType() == FunctionType::Stage)
            {
                _stageList.push_back(pStage);
            }
        }

        ModuleParameterNode* pParam = dynamic_cast<ModuleParameterNode*>(GetChild(i));
        if (pParam != nullptr)
        {
            _paramList.push_back(pParam);
        }
    }

    if (!_IsForward)
    {
        // You can have stages or states but not both
        if (GetModuleType() == ModuleType::Error)
        {
            GetContext()->ReportError(GetLocation(), "Cannot have both stages and states");
        }
    }

    // If there is a forward declare then overwrite it
    ModuleTypeInfo* pExisting = GetContext()->GetTypeCollection()->GetModuleType(_symIndex);
    if (pExisting != nullptr)
    {
        if (pExisting->IsForward())
        {
            // TODO: Make sure forward declare matches
        }
        else
        {
            GetContext()->ReportError(GetLocation(), "Cannot multiply define modules");
        }
    }

    ModuleTypeInfo* pNewType = new ModuleTypeInfo(_symIndex, this);
    GetContext()->GetTypeCollection()->SetModuleType(_symIndex, pNewType);
}

bool ModuleDefinitionNode::PreProcessNodeImpl(OutputContext* pContext)
{
    if (!_IsForward)
    {
        // Spit out the preamble
        ModuleTypeInfo* pInfo = GetContext()->GetTypeCollection()->GetModuleType(_symIndex);
        pContext->OutputLine("module %s(", GetContext()->GetSymbolString(_symIndex).c_str());
        pContext->IncreaseIndent();

    //    GetContext()->OutputLine("reset,");

        bool first = true;

        for (size_t i = 0; i < GetParameterCount(); i++)
        {
            ModuleParameterNode* pParam = GetParameter(i);
            const char* pszComma = (i != GetParameterCount() - 1) ? "," : "";

            // Only the first can be the first
            first = false;

            pContext->OutputLine(
                "%s%s", 
                GetContext()->GetSymbolString(pParam->GetSymbolIndex()).c_str(), 
                pszComma);
        }

        pContext->OutputLine(");");

        if (GetModuleType() == ModuleType::ExplicitStates)
        {
            // Define states so they are readable
            pContext->OutputLine("// State definitions");
            for (size_t i = 0; i < _stateList.size(); i++)
            {
                const char* pszStateName = (i == 0) ? "initial" : GetContext()->GetSymbolString(_stateList[i]->GetIdentifier()).c_str();

                pContext->OutputLine(
                    "`define __%s %d", 
                    pszStateName,
                    i);
            }
        }

        // All modules have a reset and a clock
        pContext->OutputLine("// inputs / outputs");
        pContext->OutputLine("input wire reset;");
    }

    return true;
}

void ModuleDefinitionNode::ProcessNodeImpl(OutputContext* pContext)
{
    if (!_IsForward)
    {
        bool fParamsDone = false;
        bool fVariablesDone = false;

        // Do all non-state and non-stage things first
        for (size_t i = 1; i < GetChildCount(); i++)
        {
            // Figure out what we have here
            StateDeclaratorNode* pState = dynamic_cast<StateDeclaratorNode*>(GetChild(i));
            FunctionDeclaratorNode* pStage = dynamic_cast<FunctionDeclaratorNode*>(GetChild(i));

            if (pState == nullptr && (pStage == nullptr || pStage->GetFunctionType() != FunctionType::Stage))
            {
                GetChild(i)->ProcessNode(pContext);
            }
        }

        if (GetModuleType() == ModuleType::ExplicitStates)
        {
            // We have a register that we store the current state in
            pContext->OutputLine("reg [7:0] fsmState = 0;");
        
            // Start the always block
            pContext->OutputLine("always @(posedge clk)");
            pContext->OutputLine("begin");
            pContext->IncreaseIndent();
    
            // State case statement only if we have more than 1
            // state in the list, or if we have an initial state
            if (_stateList.size() > 1 || _stateList[0] != nullptr)
            {
                // Start the case statement
                pContext->OutputLine("case(fsmState)");
                pContext->IncreaseIndent();
    
                for (size_t i = 0; i < _stateList.size(); i++)
                {
                    if (_stateList[i] != nullptr)
                    {
                        _stateList[i]->ProcessNode(pContext);                
                    }
                }
    
                // End the case statement
                pContext->DecreaseIndent();
                pContext->OutputLine("endcase");
            }
    
            // If we have an always state, put it here
            if (_pAlwaysState != nullptr)
            {
                _pAlwaysState->ProcessNode(pContext);
            }
    
            // End the always statement
            pContext->DecreaseIndent();
            pContext->OutputLine("end");    
        }
        else
        {
            if (_ExpandType == FunctionExpandType::StageNonblocking)
            {
                // Expand all of the stages out like we do with functions - no
                // intermediate registers or blocking assignments. This is probably
                // not useful in many cases.

                // Start the always block
                pContext->OutputLine("always @(posedge clk)");
                pContext->OutputLine("begin");
                pContext->IncreaseIndent();
        
                _stageList[_stageList.size() - 1]->ProcessNode(pContext);

                // End the always statement
                pContext->DecreaseIndent();
                pContext->OutputLine("end");
            }
            else if (_ExpandType == FunctionExpandType::StageBlocking)
            {
                // Expand each of the stages out one by one, and assign to the
                // intermediate registers when the assignments are done.

                // We need to declare registers for the intermediate values
                for (size_t i = 0; i < _stageList.size(); i++)
                {
                    FunctionDeclaratorNode* pStage = _stageList[i];

                    for (size_t j = 0; j < pStage->GetParameterCount(); j++)
                    {
                        FunctionParameterNode* pParam = pStage->GetParameter(j);

                        // We only spit out the out parameters - they should all be declared only once
                        if (pParam->IsOutParam())
                        {
                            pContext->OutputLine(
                                "reg[%d:0] %s;",
                                pParam->GetTypeInfo()->GetBitLength() - 1, 
                                pParam->GetSymbol());               
                        }
                    }
                }

                // Start the always block
                pContext->OutputLine("always @(posedge clk)");
                pContext->OutputLine("begin");
                pContext->IncreaseIndent();
        
                for (size_t i = 0; i < _stageList.size(); i++)
                {
                    _stageList[i]->ProcessNode(pContext);
                }

                // End the always statement
                pContext->DecreaseIndent();
                pContext->OutputLine("end");
            }
        }
    }
}

void ModuleDefinitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    if (!_IsForward)
    {
        // End the module
        pContext->DecreaseIndent();
        pContext->OutputLine("endmodule");
    }
}

size_t ModuleDefinitionNode::GetStageIndex(FunctionDeclaratorNode* pStage)
{
    for (size_t i = 0; i < _stageList.size(); i++)
    {
        if (_stageList[i] == pStage)
        {
            return i;
        }
    }

    throw "Unknown stage passed to GetStageIndex";
}

FunctionDeclaratorNode* ModuleDefinitionNode::GetStage(size_t index)
{
    return _stageList[index];
}

