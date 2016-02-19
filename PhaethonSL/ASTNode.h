#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "RegisterCollection.h"
#include "VariableCollection.h"

extern RegisterCollection _regCollection;
extern VariableCollection _varCollection;

class ASTNode
{
public:
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

private:
    std::unique_ptr<ASTNode> _parent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
