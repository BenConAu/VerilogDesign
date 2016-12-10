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
        _pParent = nullptr;
    }

    void AddNode(ASTNode* pNode)
    {
        _children.push_back(std::unique_ptr<ASTNode>(pNode));

        if (pNode != nullptr)
        {
            pNode->_pParent = this;
        }
    }

    virtual void ProcessNode()
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

    void VerifyNode();

    template<typename T>
    T* GetTypedParent()
    {
        ASTNode* pNode = this;

        for (;;)
        {
            ASTNode* pParent = pNode->_pParent;
            if (pParent == nullptr)
            {
                return nullptr;
            }

            T* pTypedParent = dynamic_cast<T*>(pParent);
            if (pTypedParent != nullptr)
            {
                return pTypedParent;
            }

            pNode = pParent;
        }

        return nullptr;
    }

    virtual bool IsConstant() const { return false; }
    virtual const char* GetDebugName() { return "NoDebugName"; }
    virtual void VerifyNodeImpl() = 0;
    virtual void PreProcessNodeImpl() {}
    virtual void PostProcessNodeImpl() {}

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }
    ASTNode* GetParent() { return _pParent; }
    
    int GetChildIndex(ASTNode* pNode)
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

    PSLCompilerContext* GetContext() { return _pContext; }

private:
    PSLCompilerContext* _pContext;
    ASTNode* _pParent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
