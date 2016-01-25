#pragma once

#include "ArgumentBase.h"

class Argument : public ArgumentBase
{
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
		return Construct(Argument::None, 0);
	}

	void ResolveSymbol();

public:
	int _type;
	unsigned int _value;
	bool _fDelayed;
};
