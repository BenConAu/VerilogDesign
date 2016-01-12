#pragma once

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
        Fmuladd = 7
    };
}

class Argument
{
public:
	enum Type
	{
		None,
		Constant,
        Register,
        Address
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