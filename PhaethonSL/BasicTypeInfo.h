#pragma once

#include "TypeInfo.h"
#include <string>

class BasicTypeInfo : public TypeInfo
{
  public:
    BasicTypeInfo(int typeToken);
    unsigned int GetSize() override;
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    int GetTypeToken() const;
    bool EqualType(TypeInfo *pOther) override;
    TypeInfo *MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection) override;

  private:
    int _typeToken;
};
