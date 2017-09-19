#pragma once

#include "RegisterTypeInfo.h"
#include "EnumItem.h"
#include <map>

class ParserContext;

class EnumTypeInfo : public RegisterTypeInfo
{
public:
    EnumTypeInfo(int symIndex, ParserContext* pContext);
    void AddMember(EnumItem item);
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    int GetSymbolIndex();
    bool EqualType(TypeInfo* pOther) override;
    
    bool IsMember(int symIndex);
    int GetValue(int symIndex);

private:
    int _symIndex;
    ParserContext* _pContext;
    std::map<int, int> _values;
};
