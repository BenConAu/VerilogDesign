#pragma once

#include <map>
#include <string>

template<typename T>
class AssemblerNode
{
public:
    static T* Construct()
    {
        std::unique_ptr<T> newNode(new T);
        T::GlobalList().push_back(std::move(newNode));
        return newNode.get();
    }

    void SetIntProperty(const char* pszPropName, int nameIndex)
    {
        props[pszPropName] = nameIndex;
    }

    int GetIntProperty(const char* pszPropName)
    {
        return props[pszPropName];
    }

private:
    std::map<std::string, int> props;
};
