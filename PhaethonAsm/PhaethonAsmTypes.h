#pragma once

#include <vector>

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
    };
}

struct StructMember
{
    int nameSym;
};

class StructDef
{
public:
    static int Construct(int firstSym)
    {
        StructDef newDef;
        StructMember firstMember;
        firstMember.nameSym = firstSym;
        newDef.members.push_back(firstMember);
        s_defs.push_back(newDef);

        return s_defs.size() - 1;
    }

    static void SetStructName(int structIndex, int nameIndex)
    {
    	s_defs[structIndex].nameSym = nameIndex;
    }

    static int AddMember(int structIndex, int nameIndex)
    {
        StructMember nextMember;
        nextMember.nameSym = nameIndex;

        //printf("Adding to %d\n", structIndex);

        s_defs[structIndex].members.insert(s_defs[structIndex].members.begin(), nextMember);

        return structIndex;
    }

    static int CalcOffset(int structIndex, int memberSymIndex)
    {
//        printf("Searching for %d\n", memberSymIndex);

        for (size_t j = 0; j < s_defs[structIndex].members.size(); j++)
        {
//            printf("Def %d is %d\n", j, s_defs[structIndex].members[j].nameSym);

            if (s_defs[structIndex].members[j].nameSym == memberSymIndex)
            {
                return j * 4;
            }
        }

        return -1;
    }

private:
	int nameSym;
    std::vector<StructMember> members;

    static std::vector<StructDef> s_defs;
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
