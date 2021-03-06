#pragma once

#include <map>
#include <string>
#include "VariableLocationType.h"
#include "TypeModifier.h"
#include "SymbolInfo.h"
#include "UIntConstant.h"

class ASTNode;
class TypeInfo;
class ExpressionResult;
enum class VariableLocationType;

class VariableInfo : public SymbolInfo
{
  public:
    VariableInfo(
        VSharpCompiler *pCompiler,      // The context that this variable lives in
        ASTNode *pScope,                // The scope that the variable is declared in
        int symIndex,                   // The symbol index for the identifier for the variable
        VariableLocationType location,  // The location of the variable
        TypeModifier modifier,          // The type modifier
        TypeInfo *pInfo                 // The type of the variable
        );

    VariableLocationType GetLocationType() const { return _locationType; }
    TypeModifier GetModifier() const { return _modifier; }
    ExpressionResult *CalculateResult();

    TypeInfo *GetTypeInfo() { return _pType; }
    void SetNameOverride(const char* pszName) { _nameOverride = pszName; }
    const std::string GetNameOverride() { return _nameOverride; }
    void SetInitialValue(const UIntConstant& val) { _InitValue.reset(new UIntConstant(val)); }
    UIntConstant GetInitialValue() { return *(_InitValue.get()); }

  private:
    // Type of location (globals are stored in data segment, local backed by register)
    VariableLocationType _locationType;
    TypeModifier _modifier;
    std::string _nameOverride;
    std::unique_ptr<UIntConstant> _InitValue;
    ASTNode* _pScope;

    // C++ type of variable
    TypeInfo *_pType;
};
