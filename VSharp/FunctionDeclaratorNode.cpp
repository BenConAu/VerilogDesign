#include "FunctionDeclaratorNode.h"
#include "ModuleParameterNode.h"
#include "TypeNode.h"
#include "ListNode.h"
#include "TransitionNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "VariableDeclarationNode.h"
#include "StateDeclaratorNode.h"

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
    // Add function to module?58
    //GetContext()->_symbolTable.AddModule(
        //_symIndex,
        //nullptr
        //);
}

void FunctionDeclaratorNode::PreProcessNodeImpl()
{
}

void FunctionDeclaratorNode::ProcessNodeImpl()
{
}

void FunctionDeclaratorNode::PostProcessNodeImpl()
{
}
