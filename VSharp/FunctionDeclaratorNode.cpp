#include "FunctionDeclaratorNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"
#include "ModuleDeclaratorNode.h"
#include "FunctionCallNode.h"

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

    for (size_t i = 1; i < GetChildCount(); i++)
    {
        ModuleParameterNode* pParam = dynamic_cast<ModuleParameterNode*>(GetChild(i - 1));
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
    // Which parameter did this refer to?
    size_t pIndex = _passedArgs[symIndex];

    // What was passed for that in the current call?
    ExpressionNode* pParamExpr = GetContext()->GetCurrentFunction()->GetParameter(pIndex);

    return pParamExpr->CalculateResult();
}

void FunctionDeclaratorNode::ProcessNodeImpl()
{
    if (GetContext()->GetCurrentFunction() != nullptr)
    {
        // Since somebody is expanding a function, actually do the processing
        ASTNode::ProcessNodeImpl();
    }
}
