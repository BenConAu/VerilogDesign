#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>

#include "../PhaethonISA/Generated/PhaethonOpCode.h"

class PSLCompilerContext;

class ASTNode
{
public:
    ASTNode(PSLCompilerContext* pContext)
    {
        _pContext = pContext;
        _pParent = nullptr;
    }

    void AddNode(ASTNode* pNode);
    virtual void ProcessNode();

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

    template<typename T>
    T* GetTypedChild()
    {
        for (size_t i = 0; i < GetChildCount(); i++)
        {
            T* pTypedChild = dynamic_cast<T*>(GetChild(i));
            if (pTypedChild != nullptr)
            {
                return pTypedChild;
            }
        }

        return nullptr;
    }

    virtual bool IsConstant() const { return false; }
    virtual const char* GetDebugName() { return "NoDebugName"; }
    virtual void PreVerifyNodeImpl() {}
    virtual void VerifyNodeImpl() {}
    virtual void PreProcessNodeImpl() {}
    virtual void PostProcessNodeImpl() {}

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }
    ASTNode* GetParent() { return _pParent; }
    void MoveChild(size_t from, size_t to);
    
    int GetChildIndex(ASTNode* pNode);

    PSLCompilerContext* GetContext() { return _pContext; }

private:
    PSLCompilerContext* _pContext;
    ASTNode* _pParent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
