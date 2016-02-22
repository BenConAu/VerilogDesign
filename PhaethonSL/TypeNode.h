#pragma once

#include "ASTNode.h"

class TypeInfo;

class TypeNode : public ASTNode
{
public:
    enum TypeType
    {
        BasicType,
        StructType
    };

public:
    TypeNode(PSLCompilerContext* pContext, TypeType t, int type);
    TypeInfo* GetTypeInfo();
    void VerifyNodeImpl() override;

private:
    int _type;
    TypeType _typeType;
};
