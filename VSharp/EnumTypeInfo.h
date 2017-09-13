#pragma once

#include "RegisterTypeInfo.h"
#include <map>

class ParserContext;

class EnumTypeInfo : public RegisterTypeInfo
{
public:
    EnumTypeInfo(int symIndex, ParserContext* pContext);
    void AddMember(int symIndex);
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    int GetSymbolIndex();
    bool EqualType(TypeInfo* pOther) override;
    int GetBitLength() const override;
    
    bool IsMember(int symIndex);
    int GetValue(int symIndex);

private:
    int _symIndex;
    ParserContext* _pContext;
    std::map<int, int> _values;
};
