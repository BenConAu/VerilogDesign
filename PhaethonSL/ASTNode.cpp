#include "ASTNode.h"
#include "PSLCompilerContext.h"

void ASTNode::VerifyNode()
{
    //    _pContext->PrintIndent();
    //    printf("Begin verifying %s node %p\n", GetDebugName(), this);
    _pContext->_indent++;

    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->VerifyNode();
        }
    }

    VerifyNodeImpl();

    _pContext->_indent--;
    //    _pContext->PrintIndent();
    //    printf("End verifying %s node %p\n", GetDebugName(), this);
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
    //printf("Processing node %p\n", this);

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
