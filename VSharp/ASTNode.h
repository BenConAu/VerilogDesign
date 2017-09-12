#pragma once

#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include "VSharp.tab.h"

class ParserContext;
class VSharpCompiler;
class DebugContext;
class OutputContext;

class ASTNode
{
public:
    ASTNode(ParserContext* pContext, const YYLTYPE &location)
    {
        _pContext = pContext;
        _location = location;
        _pParent = nullptr;
    }

    virtual ~ASTNode()
    {
    }

    void AddNode(ASTNode* pNode);
    void ProcessNode(OutputContext* pOutputContext);

    void VerifyNode(DebugContext* pContext);

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
    virtual bool PreProcessNodeImpl(OutputContext* pContext) { return true; }
    virtual void ProcessNodeImpl(OutputContext* pOutputContext);
    virtual void PostProcessNodeImpl(OutputContext* pContext) {}
    virtual ASTNode* DuplicateNode();
    virtual ASTNode* DuplicateNodeImpl();

    size_t GetChildCount() const { return _children.size(); }
    ASTNode* GetChild(size_t i) { return _children[i].get(); }
    ASTNode* GetParent() { return _pParent; }
    void MoveChild(size_t from, size_t to);
    ASTNode* ExtractChild(size_t index);
    void InsertChild(size_t index, ASTNode* pChild);
    
    int GetChildIndex(ASTNode* pNode);

    ParserContext* GetContext() { return _pContext; }
    void DumpNode(DebugContext* pContext);    
    virtual void DumpNodeImpl();

protected:
    const YYLTYPE& GetLocation() { return _location; }    
    
private:
    ParserContext* _pContext;
    YYLTYPE _location;    
    ASTNode* _pParent;
    std::vector<std::unique_ptr<ASTNode> > _children;
};
