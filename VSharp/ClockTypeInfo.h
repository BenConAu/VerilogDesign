#pragma once

#include "TypeInfo.h"
#include <map>

class ParserContext;

class ClockTypeInfo : public TypeInfo
{
public:
    ClockTypeInfo();
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override { return "ClockTypeInfo"; }
    std::string GetTypeName() override { return "ClockTypeInfo"; }
    bool EqualType(TypeInfo* pOther) override;
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override { throw "Wat"; }
    std::string GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr) override;
    bool IsVerilogRegister() const override { return true; }
    virtual int GetBitLength() const override { return 1; }    
};
