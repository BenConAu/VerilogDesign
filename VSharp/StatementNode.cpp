#include "StatementNode.h"
#include "VSharpCompilerContext.h"
#include "FunctionCallNode.h"

StatementNode::StatementNode(PSLCompilerContext* pContext, const YYLTYPE &location) : ASTNode(pContext)
{
    _location = location;
    _fProcessed = false;
}

void StatementNode::DumpNodeImpl()
{
    printf(
        "%s node %p :\t%s\n", 
        GetDebugName(),
        this,
        _fProcessed ? "Processed" : "Unprocessed"
    );    
}

bool StatementNode::PreProcessNodeImpl()
{
    // We expand functions during pre-process so that we don't process until expansion is complete
    FunctionCallNode* pFunctionCallNode = GetFirstFunctionCall();
    if (pFunctionCallNode != nullptr)
    {
        // Create the tree that will replace the expression
        ASTNode* pReplacement = pFunctionCallNode->ExpandFunction(this);

        printf("Created replacement node for function call\n");
        pReplacement->DumpNode();

        // Insert the node after this one
        GetParent()->InsertChild(GetParent()->GetChildIndex(this) + 1, pReplacement);

        printf("Attached replacement node\n");
        GetParent()->DumpNode();
        
        // Mark this node as replaced so that it won't do anything further
        return false;
    }

    _fProcessed = true;

    return true;
}

void StatementNode::SetCallReplacement(FunctionCallNode* pCallNode, ASTNode* pReplacement)
{
    if (pCallNode != nullptr && _pCallNode != nullptr)
    {
        throw "Statement node should only be expanding with a single replacement at a time";
    }

    _pCallNode = pCallNode;
    _pReplacement = pReplacement;
}

FunctionCallNode* StatementNode::GetFunctionCall(ASTNode* pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    // Do we have a child that is a function call?
    FunctionCallNode* pCallNode = dynamic_cast<FunctionCallNode*>(pNode);
    if (pCallNode != nullptr)
    {
        return pCallNode;
    }

    for (size_t i = 0; i < pNode->GetChildCount(); i++)
    {
        // Do we have a child that is a function call?
        pCallNode = GetFunctionCall(pNode->GetChild(i));
        if (pCallNode != nullptr)
        {
            return pCallNode;
        }
    }

    //printf("GetFunctionCall failed on all children and this node is not a function call\n");
    return nullptr;
}

FunctionCallNode* StatementNode::GetFirstFunctionCall()
{
    return GetFunctionCall(this);
}