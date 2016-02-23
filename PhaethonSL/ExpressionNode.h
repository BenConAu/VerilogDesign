#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext) : ASTNode(pContext)
    {
        _pType = nullptr;
    }

    RegIndex GetResultRegister()
    {
        return _result;
    }

    TypeInfo* GetType()
    {
        if (_pType == nullptr)
        {
            throw "Unset type";
        }
        
        return _pType;
    }

protected:
    void SetResultRegister(RegIndex result)
    {
        _result = result;
    }

    void SetType(TypeInfo* pInfo)
    {
        if (pInfo == nullptr)
        {
            throw "Should not set type to null";
        }

        _pType = pInfo;
    }

private:
    RegIndex _result;
    TypeInfo* _pType;
};
