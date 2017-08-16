#pragma once

#include "TypeInfo.h"
#include <string>

class RegisterTypeInfo : public TypeInfo
{
  public:
    RegisterTypeInfo(int bitLength);
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    bool EqualType(TypeInfo *pOther) override;
    int GetBitLength() const { return _bitLength; }
    TypeInfo *MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection) override;

  private:
    int _bitLength;
};
