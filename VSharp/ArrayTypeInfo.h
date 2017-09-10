#pragma once

#include "TypeInfo.h"
#include <string>

class ArrayTypeInfo : public TypeInfo
{
public:
    ArrayTypeInfo(TypeInfo* pBaseType, int arraySize);
    ~ArrayTypeInfo()
    {
        //printf("Destroying ArrayTypeInfo\n");
    }

    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    bool EqualType(TypeInfo* pOther) override;
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override;
    std::string GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr) override;
    
    TypeInfo* GetBaseType();

private:
    TypeInfo* _pBaseType;  // Type being pointed to
    int _arraySize;
};
