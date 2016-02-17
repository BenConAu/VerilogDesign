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

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(int symIndex)
    {
        _symIndex = symIndex;
    }

    void ProcessNodeImpl() override
    {
        _regIndex = _regCollection.GetSymbolRegister(_symIndex);
    }

    RegIndex GetResultRegister() override
    {
        return _regIndex;
    }

private:
    int _symIndex;
    RegIndex _regIndex;
};

class ConstantNode : public ASTNode
{
public:
    enum ConstantType
    {
        Int,
        Float
    };

public:
    ConstantNode(int v)
    {
        _intValue = v;
        _type = Int;
    }

    ConstantNode(float v)
    {
        _floatValue = v;
        _type = Float;
    }

    int GetInteger()
    {
        if (_type == Int)
        {
            return _intValue;
        }
        else
        {
            throw "Not an integer";
        }
    }

    bool IsConstant() const override { return true; }

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};

class MultiplyNode : public ASTNode
{
public:
    MultiplyNode(ASTNode* pLeft, ASTNode* pRight)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void ProcessNodeImpl() override
    {
        // Get the register for the left side
        RegIndex leftIndex = GetChild(0)->GetResultRegister();

        // Right side is either a constant or another register
        RegIndex rightIndex = GetChild(1)->GetResultRegister();

        // print out our code
        printf("mul r%d, r%d\n", leftIndex, rightIndex);

        // Register for the left side has been stomped on, so dissociate from symbol
        _regCollection.ClearSymbolRegister(leftIndex);

        // Our result is the left index now
        _result = leftIndex;
    }

    RegIndex GetResultRegister() override
    {
        return _result;
    }

protected:
    RegIndex _result;
};
