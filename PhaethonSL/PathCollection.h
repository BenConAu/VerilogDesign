#pragma once

#include "VariablePath.h"
#include <vector>

class VariablePath;
class StructMember;

class PathCollection
{
  public:
    VariablePath *EnsurePath(VariableInfo *pInfo);
    VariablePath *EnsurePath(VariablePath *pPath, StructMember *pMember);

  private:
    std::vector<std::unique_ptr<VariablePath>> _paths;
};