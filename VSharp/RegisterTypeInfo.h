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
    int GetBitLength() const override { return _bitLength; }
    TypeInfo *MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection) override;
    bool IsVerilogRegister() const override { return true; }
    
  private:
    int _bitLength;
};
