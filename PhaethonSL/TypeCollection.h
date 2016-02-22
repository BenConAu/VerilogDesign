#pragma once

#include <vector>
#include <map>
#include <memory>

class TypeInfo
{
public:
    virtual int GetSize() = 0;
    virtual bool IsBasic() = 0;
};

class TypeMember
{
public:
    TypeMember(int symIndex, TypeInfo* pType)
    {
        _symIndex = symIndex;
        _pType = pType;
    }

    int GetSize()
    {
        return _pType->GetSize();
    }

    int _symIndex;
    TypeInfo* _pType;
};

class StructTypeInfo : public TypeInfo
{
public:
    StructTypeInfo(int symIndex)
    {
        _symIndex = symIndex;
    }

    void AddMember(int symIndex, TypeInfo* pType)
    {
        _members.push_back(std::unique_ptr<TypeMember>(new TypeMember(symIndex, pType)));
    }

    int GetSize() override
    {
        int totalSize = 0;

        for (size_t i = 0; i < _members.size(); i++)
        {
            totalSize += _members[i]->GetSize();
        }

        return totalSize;
    }

    bool IsBasic() override
    {
        return false;
    }

private:
    int _symIndex;
    std::vector<std::unique_ptr<TypeMember> > _members;
};

class BasicTypeInfo : public TypeInfo
{
public:
    BasicTypeInfo(int typeToken)
    {
        _typeToken = typeToken;
    }

    int GetSize() override
    {
        // All basic types are size 4
        return 4;
    }

    bool IsBasic() override
    {
        return true;
    }

private:
    int _typeToken;
};

class TypeCollection
{
public:
    TypeCollection();
    StructTypeInfo* GetStructType(int symIndex);
    BasicTypeInfo* GetBasicType(int type);

private:
    std::map<int, std::unique_ptr<StructTypeInfo> > _structTypes;
    std::map<int, std::unique_ptr<BasicTypeInfo> > _basicTypes;
};
