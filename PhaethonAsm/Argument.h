#pragma once

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

    static const char* ppszTypeText[];
    static const char* ppszShortTypeText[];

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
