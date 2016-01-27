#pragma once

#include "ArgumentBase.h"

namespace SymbolType
{
	enum Enum
	{
		None,
		VarAddress,    // Address of a variable in a data segment
		LabelAddress,  // Address of a label in a code segment
	};
}

class Argument : public ArgumentBase
{
public:
	static Argument Construct(Type t, int v)
	{
		Argument a;

		a._type = t;
		a._value = v;
		a._symType = SymbolType::None;

		return a;
	}

	static Argument Construct(Type t, int symbol, SymbolType::Enum symType)
	{
		Argument a;

		a._type = t;
		a._value = symbol;
		a._symType = symType;

		return a;
	}

	static Argument ConstructNone()
	{
		return Construct(Argument::None, 0);
	}

	void ResolveSymbol();

public:
	Type _type;
	unsigned int _value;
	SymbolType::Enum _symType;
};
