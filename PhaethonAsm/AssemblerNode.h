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

    static std::vector<std::unique_ptr<AssemblerNode>>& GetNodes()
    {
        static std::vector<std::unique_ptr<AssemblerNode>> s_nodeDefs;
        return s_nodeDefs;
    }

    template<typename T>
    static T* GetNode(size_t index)
    {
        return dynamic_cast<T*>(GetNodes()[index].get());
    }

  private:
    std::map<std::string, int> props;
};

template <typename T>
T *AssemblerNode::Construct()
{
    //printf("Adding node while size is %d and this is %p\n", (int)AssemblerNode::GetNodes().size(), &AssemblerNode::GetNodes());
    std::unique_ptr<T> newNode(new T);
    AssemblerNode::GetNodes().push_back(std::move(newNode));
    //printf("Added node while size is %d and this is %p\n", (int)AssemblerNode::GetNodes().size(), &AssemblerNode::GetNodes());
    return AssemblerNode::GetNode<T>(AssemblerNode::GetNodes().size() - 1);
}