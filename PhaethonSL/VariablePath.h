#pragma once

#include "VariableLocation.h"
#include <vector>
#include <map>

class VariableInfo;
class StructMember;
class FunctionDeclaratorNode;

class VariablePath
{
  public:
    VariablePath(VariableInfo *pVarInfo)
    {
        _pVarInfo = pVarInfo;
    }

    VariablePath(VariablePath &basePath, StructMember *pMember)
    {
        _pVarInfo = basePath._pVarInfo;
        _memberPath.insert(
            _memberPath.end(),
            basePath._memberPath.begin(),
            basePath._memberPath.end());
    }

    void ReserveRegister(FunctionDeclaratorNode* pScope, RegIndex index);
    RegIndex EnsurePathRegister(FunctionDeclaratorNode* pScope);
    bool HasRegister(FunctionDeclaratorNode* pScope);

    VariableInfo* GetVariableInfo() { return _pVarInfo; }
    size_t GetPathLength() { return _memberPath.size(); }
    StructMember* GetMember(size_t index) { return _memberPath[index]; }

  private:
    // The variable that starts all of this
    VariableInfo *_pVarInfo;

    // The path of members from the struct
    std::vector<StructMember *> _memberPath;

    // Register allocated by scope (globals have multiple register locations mapped)
    std::map<FunctionDeclaratorNode*, RegIndex> _regIndexMap;
};