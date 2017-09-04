#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>

class PSLCompilerContext;

class ASTNode
{
public:
    ASTNode(PSLCompilerContext* pContext)
    {
        _pContext = pContext;
        _pParent = nullptr;
    }

    virtual ~ASTNode()
    {
    }

    void AddNode(ASTNode* pNode);
    void ProcessNode();

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
    virtual const char* GetDebugName() = 0;
    virtual void PreVerifyNodeImpl() {}
    virtual void VerifyNodeImpl() {}
    virtual bool PreProcessNodeImpl() { return true; }
    virtual void ProcessNodeImpl();
    virtual void PostProcessNodeImpl() {}
    virtual ASTNode* DuplicateNode();
    virtual ASTNode* DuplicateNodeImpl();

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }
    ASTNode* GetParent() { return _pParent; }
    void MoveChild(size_t from, size_t to);
    ASTNode* ExtractChild(size_t index);
    void InsertChild(size_t index, ASTNode* pChild);
    
    int GetChildIndex(ASTNode* pNode);

    PSLCompilerContext* GetContext() { return _pContext; }
    void DumpNode();    
    virtual void DumpNodeImpl();
    
private:
    PSLCompilerContext* _pContext;
    ASTNode* _pParent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
