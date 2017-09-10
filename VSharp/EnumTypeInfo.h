#pragma once

#include "TypeInfo.h"
#include <map>

class PSLCompilerContext;

class EnumTypeInfo : public TypeInfo
{
public:
    EnumTypeInfo(int symIndex, PSLCompilerContext* pContext);
    void AddMember(int symIndex);
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    int GetSymbolIndex();
    bool EqualType(TypeInfo* pOther) override;
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override;
    bool IsVerilogRegister() const override { return true; }
    int GetBitLength() const override;
    std::string GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr) override;
    
    bool IsMember(int symIndex);
    int GetValue(int symIndex);

private:
    int _symIndex;
    PSLCompilerContext* _pContext;
    std::map<int, int> _values;
};
