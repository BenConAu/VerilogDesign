#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>

#include "RegisterCollection.h"

class PSLCompilerContext;

class ASTNode
{
public:
    ASTNode(PSLCompilerContext* pContext)
    {
        _pContext = pContext;
    }

    void AddNode(ASTNode* pNode)
    {
        _children.push_back(std::unique_ptr<ASTNode>(pNode));
    }

    void ProcessNode()
    {
        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i] != nullptr)
            {
                _children[i]->ProcessNode();
            }
        }

        ProcessNodeImpl();
    }

    void VerifyNode()
    {
        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i] != nullptr)
            {
                _children[i]->VerifyNode();
            }
        }

        VerifyNodeImpl();
    }

    virtual bool IsConstant() const { return false; }
    virtual void VerifyNodeImpl() = 0;
    virtual void ProcessNodeImpl() {}

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }

    PSLCompilerContext* GetContext() { return _pContext; }

private:
    PSLCompilerContext* _pContext;
    std::unique_ptr<ASTNode> _parent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
