#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"
#include "ModuleDeclaratorNode.h"
#include "FunctionCallNode.h"

FunctionDeclaratorNode::FunctionDeclaratorNode(
    PSLCompilerContext* pContext,
    ASTNode* pRetType,
    int symIndex,
    int genericSym
    ) : ASTNode(pContext)
{
    AddNode(pRetType);

    _symIndex = symIndex;
    _genericIndex = genericSym;
    _pCallNode = nullptr;
}

void FunctionDeclaratorNode::PreVerifyNodeImpl()
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

void FunctionDeclaratorNode::VerifyNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // First child is return type, last is statement list
    for (size_t i = 1; i < GetChildCount() - 1; i++)
    {
        FunctionParameterNode* pParam = dynamic_cast<FunctionParameterNode*>(GetChild(i));
        int symIndex = pParam->GetSymbolIndex();

        _passedArgs.emplace(std::make_pair(symIndex, i - 1));
    }
    
    // Add function to module
    GetContext()->_symbolTable.AddFunction(
        this,
        _symIndex,
        nullptr
        );
}

ExpressionResult* FunctionDeclaratorNode::ResultFromSymbol(int symIndex)
{
    //printf("Result from symbol\n");

    // Which parameter did this refer to?
    size_t pIndex = _passedArgs[symIndex];

    // What was passed for that in the current call?
    ExpressionNode* pParamExpr = _pCallNode->GetParameter(pIndex);

    return pParamExpr->CalculateResult();
}

void FunctionDeclaratorNode::ProcessNodeImpl()
{
    if (_pCallNode != nullptr)
    {
        //printf("Processing a function while expanding it\n");

        // Since somebody is expanding a function, actually do the processing
        ASTNode::ProcessNodeImpl();

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
}

void FunctionDeclaratorNode::SetCall(FunctionCallNode* pCall) 
{ 
    if (pCall != nullptr && _pCallNode != nullptr)
    {
        throw "Recursion not allowed with function calls";
    }

    _pCallNode = pCall; 
}
