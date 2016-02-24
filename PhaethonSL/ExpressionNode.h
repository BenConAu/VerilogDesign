#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext) : ASTNode(pContext)
    {
        _pType = nullptr;
        _result = 0xFF;
    }

    RegIndex GetResultRegister()
    {
        if (_result == 0xFF)
        {
            _result = CalcResultRegisterImpl();
        }

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
    virtual RegIndex CalcResultRegisterImpl() = 0;

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
