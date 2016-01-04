#pragma once

namespace Instructions
{
    enum Enum
    {
        Unknown = 0,
        Mov = 1,
        Fconv = 2,
        Fadd = 3    
    };
}

class Argument
{
public:
	enum Type
	{
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

public:
	int _type;
	int _value;
};