#include "ASTNode.h"
#include "VSharpCompilerContext.h"

void ASTNode::VerifyNode()
{
    //_pContext->PrintIndent();
    //printf("Begin verifying %s node %p\n", GetDebugName(), this);
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
    //_pContext->PrintIndent();
    //printf("End verifying %s node %p\n", GetDebugName(), this);
}

void ASTNode::AddNode(ASTNode *pNode)
{
    _children.push_back(std::unique_ptr<ASTNode>(pNode));

    if (pNode != nullptr)
    {
        pNode->_pParent = this;
    }
}

void ASTNode::ProcessNodeImpl()
{
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->ProcessNode();
        }
    }
}

void ASTNode::ProcessNode()
{
    //_pContext->PrintIndent();
    //printf("Begin processing %s node %p\n", GetDebugName(), this);
    _pContext->_indent++;

    // Processing before children are done
    PreProcessNodeImpl();

    // Actual processing
    ProcessNodeImpl();

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

void ASTNode::MoveChild(size_t from, size_t to)
{
    ASTNode* pRemoved = ExtractChild(from);
    InsertChild(to, pRemoved);
}

ASTNode* ASTNode::ExtractChild(size_t index)
{
    ASTNode* pRemoved = _children[index].release();
    _children.erase(_children.begin() + index);
    return pRemoved;
}

void ASTNode::InsertChild(size_t index, ASTNode* pChild)
{
    _children.emplace(_children.begin() + index, pChild);
    pChild->_pParent = this;
}