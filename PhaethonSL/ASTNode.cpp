#include "ASTNode.h"
#include "PSLCompilerContext.h"

void ASTNode::VerifyNode()
{
    _pContext->PrintIndent();
    printf("Begin verifying %s node %p\n", GetDebugName(), this);
    _pContext->_indent++;

    PreVerifyNodeImpl();

    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->VerifyNode();
        }
    }

    VerifyNodeImpl();

    _pContext->_indent--;
    _pContext->PrintIndent();
    printf("End verifying %s node %p\n", GetDebugName(), this);
}

void ASTNode::AddNode(ASTNode *pNode)
{
    _children.push_back(std::unique_ptr<ASTNode>(pNode));

    if (pNode != nullptr)
    {
        pNode->_pParent = this;
    }
}

void ASTNode::ProcessNode()
{
    //_pContext->PrintIndent();
    //printf("Begin processing %s node %p\n", GetDebugName(), this);
    _pContext->_indent++;

    // Processing before children are done
    PreProcessNodeImpl();

    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->ProcessNode();
        }
    }

    // Processing after children are done
    PostProcessNodeImpl();

    _pContext->_indent--;
    //_pContext->PrintIndent();
    //printf("End processing %s node %p\n", GetDebugName(), this);
}

int ASTNode::GetChildIndex(ASTNode *pNode)
{
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i].get() == pNode)
        {
            return i;
        }
    }

    throw "Invalid child given for index query";
}
