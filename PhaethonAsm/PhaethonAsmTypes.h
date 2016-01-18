#pragma once

#include <vector>
#include <memory>

namespace Instructions
{
    enum Enum
    {
        Unknown = 0,
        Mov = 1,
        Fconv = 2,
        Fadd = 3,
        Cmp = 4,
        Jmp = 5,
        Fmul = 6,
        Fmuladd = 7,
        Fmin = 8,
        Fsub = 9,
        Dout = 10,
    };
}

template<typename DefType, typename ChildDefType>
class ListDef
{
public:
    static DefType* Construct(ChildDefType* pFirstItem)
    {
        DefType* pNewList = new DefType;
        std::unique_ptr<DefType> newList(pNewList);
        newList->AddMember(pFirstItem);
        DefType::GlobalList().push_back(std::move(newList));
        return pNewList;
    }

    void SetName(int nameIndex)
    {
    	nameSym = nameIndex;
    }

    void AddMember(ChildDefType* newMember)
    {
        members.insert(members.begin(), newMember);
    }

    int Find(int memberSymIndex)
    {
        for (size_t j = 0; j < members.size(); j++)
        {
            if (DefType::Match(members[j], memberSymIndex))
            {
                return j;
            }
        }

        return -1;
    }

    ChildDefType* GetItem(int item) { return members[item]; }
    int GetItemCount() const { return members.size(); }

protected:
	int nameSym;
    std::vector<ChildDefType*> members;
};

struct StructMember
{
    static StructMember* Construct(int value)
    {
        StructMember* pNewEntry = new StructMember;
        pNewEntry->nameSym = value;
        std::unique_ptr<StructMember> newEntry(pNewEntry);
        s_defs.push_back(std::move(newEntry));
        return pNewEntry;
    }

    int nameSym;

    static std::vector<std::unique_ptr<StructMember> > s_defs;
};

class StructDef : public ListDef<StructDef, StructMember>
{
public:
    static bool Match(StructMember* member, int name)
    {
        return (member->nameSym == name);
    }

    static int CalcOffset(int structIndex, int memberSymIndex)
    {
        return s_defs[structIndex]->Find(memberSymIndex) * 4;
    }

    static std::vector<std::unique_ptr<StructDef> > s_defs;
    static std::vector<std::unique_ptr<StructDef> >& GlobalList() { return s_defs; }
};

struct DataSegmentItemEntry
{
    static DataSegmentItemEntry* Construct(int value)
    {
        DataSegmentItemEntry* pNewEntry = new DataSegmentItemEntry;
        pNewEntry->_value = value;
        std::unique_ptr<DataSegmentItemEntry> newEntry(pNewEntry);
        s_defs.push_back(std::move(newEntry));
        return pNewEntry;
    }

    static std::vector<std::unique_ptr<DataSegmentItemEntry> > s_defs;
    int _value;
};

class DataSegmentItemDef : public ListDef<DataSegmentItemDef,DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemDef> >& GlobalList() { return s_defs; }
};

class DataSegmentDef : public ListDef<DataSegmentDef, DataSegmentItemDef>
{
public:
    void SetAddress(int address)
    {
        _address = address;
    }

    int GetAddress() { return _address; }

    static std::vector<std::unique_ptr<DataSegmentDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentDef> >& GlobalList() { return s_defs; }

private:
    int _address;
};

class Argument
{
public:
	enum Type
	{
		None,
		Constant,
        Register,
        ConstAddress,
        RegAddress,
	};

public:
	static Argument Construct(Type t, int v)
	{
		Argument a;

		a._type = t;
		a._value = v;

		return a;
	}

	static Argument ConstructNone()
	{
		Argument a = { Argument::None, 0 };

		return a;
	}

public:
	int _type;
	unsigned int _value;
};
