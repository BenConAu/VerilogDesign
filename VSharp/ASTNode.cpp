#include "ASTNode.h"
#include "ParserContext.h"
#include "OutputContext.h"

void ASTNode::DumpNodeImpl()
{
    printf("%s node %p\n", GetDebugName(), this);    
}

void ASTNode::DumpNode(DebugContext* pContext)
{
    pContext->PrintIndent();
    DumpNodeImpl();
    pContext->_indent++;
    
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->DumpNode(pContext);
        }
    }

    pContext->_indent--;
}

void ASTNode::VerifyNode(DebugContext* pContext)
{
    if (_fVerified)
    {
        // Double verify could go badly
        return;
    }

    //_pContext->PrintIndent();
    //printf("Begin verifying %s node %p\n", GetDebugName(), this);
    if (pContext != nullptr)
    {
        pContext->_indent++;        
    }

    if (PreVerifyNodeImpl())
    {
        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i] != nullptr)
            {
                _children[i]->VerifyNode(pContext);
            }
        }
    
        VerifyNodeImpl();
    }

    if (pContext != nullptr)
    {
        pContext->_indent--;        
    }
    //_pContext->PrintIndent();
    //printf("End verifying %s node %p\n", GetDebugName(), this);

    _fVerified = true;
}

void ASTNode::AddNode(ASTNode *pNode)
{
    _children.push_back(std::unique_ptr<ASTNode>(pNode));

    if (pNode != nullptr)
    {
        pNode->_pParent = this;
    }
}

void ASTNode::ProcessNodeImpl(OutputContext* pOutputContext)
{
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->ProcessNode(pOutputContext);
        }
    }
}

void ASTNode::ProcessNode(OutputContext* pOutputContext)
{
    //_pContext->PrintIndent();
    //printf("Begin processing %s node %p\n", GetDebugName(), this);
    pOutputContext->GetDebugContext()->_indent++;

    // Processing before children are done - return true to continue
    if (PreProcessNodeImpl(pOutputContext))
    {
        // Actual processing
        ProcessNodeImpl(pOutputContext);
    
        // Processing after children are done
        PostProcessNodeImpl(pOutputContext);
    }

    pOutputContext->GetDebugContext()->_indent--;
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

ASTNode* ASTNode::DuplicateNode(FunctionExpandType type)
{
    //printf("Duplicating node %s %p\n", GetDebugName(), this);

    ASTNode* pCopy = DuplicateNodeImpl(type);
    for (size_t i = 0; i < GetChildCount(); i++)
    {
        if (GetChild(i) != nullptr)
        {
            pCopy->AddNode(GetChild(i)->DuplicateNode(type));            
        }
        else
        {
            pCopy->AddNode(nullptr);
        }
    }

    return pCopy;
}

ASTNode* ASTNode::DuplicateNodeImpl(FunctionExpandType type)
{
    throw "Internal compiler error - unimplemented node duplicator";
}