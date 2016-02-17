#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "RegisterCollection.h"

extern RegisterCollection _regCollection;

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
            _children[i]->ProcessNode();
        }

        ProcessNodeImpl();
    }

    virtual bool IsConstant() const { return false; }
    virtual void ProcessNodeImpl() {}
    virtual RegIndex GetResultRegister() { throw "Not implemented"; }

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }

private:
    std::unique_ptr<ASTNode> _parent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
