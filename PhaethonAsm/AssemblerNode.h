#pragma once

#include <map>
#include <string>
#include <memory>
#include <vector>

class AssemblerNode
{
public:
    virtual ~AssemblerNode()
    {
    }

    template <typename T>
    static T *Construct();

    void SetIntProperty(const char *pszPropName, int nameIndex)
    {
        //printf("Setting %s to %d\n", pszPropName, nameIndex);

        props[pszPropName] = nameIndex;
    }

    int GetIntProperty(const char *pszPropName)
    {
        return props[pszPropName];
    }

private:
    std::map<std::string, int> props;
};

extern std::vector<std::unique_ptr<AssemblerNode>> s_nodeDefs;

template <typename T>
T *AssemblerNode::Construct()
{
    std::unique_ptr<T> newNode(new T);
    s_nodeDefs.push_back(std::move(newNode));
    return dynamic_cast<T*>(s_nodeDefs[s_nodeDefs.size() - 1].get());
}
