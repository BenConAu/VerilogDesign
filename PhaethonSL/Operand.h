#pragma once

#include "../PhaethonObjWriter/ObjArgument.h"
#include "VariableLocation.h"
#include <string>

class PSLCompilerContext;
class VariableInfo;
class StructMember;
class StructTypeInfo;
class PointerTypeInfo;

enum class KnownConstants
{
    Unknown,
    DataSegmentEnd,
};

// An Operand is a representation of an operand in PASM. This is part of what an
// expression will output. Many leaf nodes of expression trees are very simple (such
// as a constant).
class Operand
{
  public:
    explicit Operand();
    explicit Operand(RegIndex index);
    explicit Operand(int constant);

    explicit Operand(
        VariableInfo *pVarInfo,
        PSLCompilerContext *pContext);

    explicit Operand(
        KnownConstants constant);

    explicit Operand(
        RegIndex regIndex,
        StructTypeInfo *pTypeInfo,
        StructMember *pTypeMember,
        PSLCompilerContext *pContext);

    explicit Operand(
        RegIndex regIndex,
        PointerTypeInfo *pTypeInfo,
        PSLCompilerContext *pContext);

    explicit Operand(
        const std::string &label);

    bool IsNone() const;
    std::string GetOpString() const;
    OperandType GetType() const { return _objArg._argType; }
    RegIndex GetRegIndex() const;
    const ObjArgument &GetObjArgument() const;
    const char *DebugPrint();

  private:
    // The information about the argument
    ObjArgument _objArg;
};
