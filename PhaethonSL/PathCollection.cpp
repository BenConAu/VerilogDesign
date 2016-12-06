#include "PathCollection.h"
#include "VariableInfo.h"

VariablePath *PathCollection::EnsurePath(VariableInfo *pInfo)
{
    for (size_t i = 0; i < _paths.size(); i++)
    {
        if (_paths[i]->GetVariableInfo() == pInfo && _paths[i]->GetPathLength() == 0)
        {
            return _paths[i].get();
        }
    }

    _paths.emplace_back(std::unique_ptr<VariablePath>(new VariablePath(pInfo)));
    return _paths[_paths.size() - 1].get();
}

VariablePath *PathCollection::EnsurePath(VariablePath *pPath, StructMember *pAddMember)
{
    VariablePath* pNewPath = new VariablePath(*pPath, pAddMember);

    for (size_t i = 0; i < _paths.size(); i++)
    {
        if (_paths[i]->GetVariableInfo() == pNewPath->GetVariableInfo() && _paths[i]->GetPathLength() == pNewPath->GetPathLength())
        {
            bool FoundPath = true;

            for (size_t j = 0; j < _paths[i]->GetPathLength(); j++)
            {
                if (_paths[i]->GetMember(j) != pNewPath->GetMember(j))
                {
                    FoundPath = false;
                    break;
                }
            }

            if (FoundPath)
            {
                return _paths[i].get();
            }
        }
    }

    // Not found, add to the end
    _paths.emplace_back(std::unique_ptr<VariablePath>(pNewPath));
    return _paths[_paths.size() - 1].get();
}
