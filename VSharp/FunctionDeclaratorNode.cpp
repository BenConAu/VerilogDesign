#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"
#include "ModuleDefinitionNode.h"
#include "FunctionCallNode.h"
#include "IdentifierNode.h"

FunctionDeclaratorNode::FunctionDeclaratorNode(
    ParserContext* pContext,
    const YYLTYPE &location,
    ASTNode* pRetType,
    int symIndex,
    ASTNode* pGenericExpr
    ) : ASTNode(pContext, location)
{
    AddNode(pRetType);
    AddNode(pGenericExpr);

    _FunctionType = FunctionType::Standard;
    _symIndex = symIndex;
    _pCallNode = nullptr;
    _pStatementNode = nullptr;
    _pStageInput = nullptr;
}

FunctionDeclaratorNode::FunctionDeclaratorNode(
    ParserContext* pContext,
    const YYLTYPE &location,
    int symIndex
    ) : ASTNode(pContext, location)
{
    _FunctionType = FunctionType::Standard;
    _symIndex = symIndex;
    _pCallNode = nullptr;
    _pStatementNode = nullptr;
    _pStageInput = nullptr;
}

ASTNode* FunctionDeclaratorNode::DuplicateNodeImpl(DuplicateType type)
{
    return new FunctionDeclaratorNode(GetContext(), GetLocation(), _symIndex);
}

bool FunctionDeclaratorNode::PreVerifyNodeImpl()
{
    if (GetChild(0) != nullptr)
    {
        if (GetChild(1) != nullptr)
        {
            IdentifierNode* pIdentifierNode = dynamic_cast<IdentifierNode*>(GetChild(1));
            if (pIdentifierNode != nullptr)
            {
                // The "Generic" version of the function is declared with an identifier
                _FunctionType = FunctionType::GenericIdentifier;
    
                // Add variable to collection
                VariableInfo* pVarInfo = GetContext()->GetSymbolTable()->AddVariable(
                    this,
                    pIdentifierNode->GetSymbolIndex(),
                    VariableLocationType::Generic,
                    TypeModifier::None,
                    GetContext()->GetTypeCollection()->GetRegisterType(32));
    
                if (pVarInfo == nullptr)
                {
                    GetContext()->ReportError(GetLocation(), "Duplicate generic parameter %s", GetContext()->GetSymbolString(pIdentifierNode->GetSymbolIndex()).c_str());
                }
                
                // Add the generic version of the function
                GetContext()->GetSymbolTable()->AddFunction(
                    this,
                    _symIndex,
                    nullptr
                    );                    
    
                // Don't try verifying templated functions, it is just madness. We will verify the template
                // expanded version later on.
                return false;
            }
            else
            {
                ConstantNode* pConstantNode = dynamic_cast<ConstantNode*>(GetChild(1));
                if (pConstantNode != nullptr)
                {
                    _FunctionType = FunctionType::GenericConstant;
                }
                else
                {
                    GetContext()->ReportError(GetLocation(), "Invalid expression for generic argument for function");
                }
    
                UIntConstant Value;
                pConstantNode->ConstEvaluate(&Value);
    
                GetContext()->GetSymbolTable()->AddFunction(
                    this,
                    _symIndex,
                    &Value
                    );
            }
        }
        else
        {
            GetContext()->GetSymbolTable()->AddFunction(
                this,
                _symIndex,
                nullptr
                );
        }
    }
    else
    {
        _FunctionType = FunctionType::Stage;
    }

    return true;
}

void FunctionDeclaratorNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // First child is return type, last is statement list
    for (size_t i = 0; i < GetParameterCount(); i++)
    {
        int symIndex = GetParameter(i)->GetSymbolIndex();

        _passedArgs.emplace(std::make_pair(symIndex, i));
    }
}

bool FunctionDeclaratorNode::IsParameter(int symIndex)
{
    if (_passedArgs.count(symIndex) == 0)
    {
        // We don't know what this is
        return false;
    }

    return true;
}

bool FunctionDeclaratorNode::IsGenericParameter(int symIndex)
{
    if (_FunctionType == FunctionType::GenericIdentifier)
    {
        std::vector<VariableInfo*> Symbols;
        GetContext()->GetSymbolTable()->GetSymbols(symIndex, this, Symbols);

        if (Symbols.size() != 0 && Symbols[0]->GetLocationType() == VariableLocationType::Generic)
        {
            return true;
        }
    }

    return false;
}

ASTNode* FunctionDeclaratorNode::DuplicateParameterIdentifier(int symIndex)
{
    //printf("Result from symbol\n");

    if (!IsParameter(symIndex))
    {
        throw "Non-paramter symbol index given";
    }

    // Which parameter did this refer to?
    size_t pIndex = _passedArgs[symIndex];

    // What was passed for that in the current call?
    FunctionCallParamNode* pParamNode = _pCallNode->GetParameter(pIndex);

    // Duplicate that instead of the parameter
    return pParamNode->DuplicateNode(DuplicateType::ExpandFunction);
}

ASTNode* FunctionDeclaratorNode::DuplicateGenericParameterIdentifier(int symIndex)
{
    if (!IsGenericParameter(symIndex))
    {
        throw "Non-paramter symbol index given";
    }

    UIntConstant* pGenericValue = _pCallNode->GetGenericValue();
    if (pGenericValue == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Internal compiler error - no generic value");
    }

    return new ConstantNode(GetContext(), GetLocation(), *pGenericValue);
}

ASTNode* FunctionDeclaratorNode::ExpandFunction(IdentifierNode* pStageInput, StatementNode* pStatement)
{
    //DumpNode(GetContext()->GetDebugContext());

    // Remember the call that we are expanding, but don't allow recursion
    if (_pStageInput != nullptr)
    {
        throw "Recursion not allowed with function calls";
    }

    _pStageInput = pStageInput;
    _pStatementNode = pStatement;

    // Get the statement list for the function
    ListNode* pListNode = dynamic_cast<ListNode*>(GetChild(GetChildCount() - 1));

    // Duplicate the list with appropriate replacements
    ASTNode* pExpanded = pListNode->DuplicateNode(DuplicateType::ExpandStageInput);

    _pStageInput = nullptr;
    _pStatementNode = nullptr;

    return pExpanded;
}

ASTNode* FunctionDeclaratorNode::ExpandFunction(FunctionCallNode* pCall, StatementNode* pStatement)
{
    // Remember the call that we are expanding, but don't allow recursion
    if (_pCallNode != nullptr)
    {
        throw "Recursion not allowed with function calls";
    }

    _pCallNode = pCall;
    _pStatementNode = pStatement;

    // Get the statement list for the function
    ListNode* pListNode = dynamic_cast<ListNode*>(GetChild(GetChildCount() - 1));

    // Duplicate the list with appropriate replacements
    ASTNode* pExpanded = pListNode->DuplicateNode(DuplicateType::ExpandFunction);

    _pCallNode = nullptr;
    _pStatementNode = nullptr;

    return pExpanded;
}

ASTNode* FunctionDeclaratorNode::ExpandFunction(FunctionCallNode* pCall, UIntConstant Value)
{
    // Remember the call that we are expanding, but don't allow recursion
    if (_pCallNode != nullptr)
    {
        throw "Recursion not allowed with function calls";
    }

    _pCallNode = pCall;
    _genericValue = Value;

    // Duplicate the list with appropriate replacements
    ASTNode* pExpanded = DuplicateNode(DuplicateType::ExpandGeneric);

    _pCallNode = nullptr;

    return pExpanded;
}

void FunctionDeclaratorNode::ProcessNodeImpl(OutputContext* pContext)
{
    if (_pCallNode != nullptr)
    {
        //printf("Processing a function while expanding it\n");

        // Since somebody is expanding a function, actually do the processing
        ASTNode::ProcessNodeImpl(pContext);

        ListNode* pListNode = dynamic_cast<ListNode*>(GetChild(GetChildCount() - 1));
        if (pListNode == nullptr)
        {
            // We only have a single child that is an expression. Get the result
            // from it and save it for the function call to use.
            ExpressionNode* pExpr = dynamic_cast<ExpressionNode*>(GetChild(GetChildCount() - 1));

            _lastResult.reset(pExpr->TakeResult());
        }
        else
        {
            _lastResult.reset();
        }
    }
    else
    {
        if (_FunctionType == FunctionType::Stage)
        {
            // Process the function and start expanding it out
            ASTNode::ProcessNodeImpl(pContext);
        }
    }
}
