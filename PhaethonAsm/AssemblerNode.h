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
        return T::GlobalList()[T::GlobalList().size() - 1].get();
    }

    void SetIntProperty(const char* pszPropName, int nameIndex)
    {
        //printf("Setting %s to %d\n", pszPropName, nameIndex);

        props[pszPropName] = nameIndex;
    }

    int GetIntProperty(const char* pszPropName)
    {
        return props[pszPropName];
    }

private:
    std::map<std::string, int> props;
};
