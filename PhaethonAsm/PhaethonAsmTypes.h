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
        Inc = 11,
        Add = 12,
        Dec = 13,
        Fmax = 14,
        Jne = 15,
    };
}

class Argument
{
public:
	enum Type
	{
		None = 0,
		Constant = 1,
        Register = 2,
        ConstAddress = 3,
        RegAddress = 4,
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
