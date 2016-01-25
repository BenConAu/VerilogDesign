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
		a._fDelayed = false;

		return a;
	}

	static Argument ConstructDelayed(Type t, int symbol)
	{
		Argument a;

		a._type = t;
		a._value = symbol;
		a._fDelayed = true;

		return a;
	}

	static Argument ConstructNone()
	{
		Argument a = { Argument::None, 0 };

		return a;
	}

	void ResolveSymbol();

public:
	int _type;
	unsigned int _value;
	bool _fDelayed;
};
