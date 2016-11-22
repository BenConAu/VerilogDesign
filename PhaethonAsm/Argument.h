#pragma once

#include "../PhaethonISA/ISAOperand.h"
#include "../PhaethonObjWriter/ObjArgument.h"

namespace SymbolType
{
	enum Enum
	{
		None,
		VarAddress,    // Address of a variable in a data segment
		LabelAddress,  // Address of a label in a code segment
	};
}

class Argument
{
public:
	static Argument Construct(Operand t, int v)
	{
		Argument a;

		a._argType = t;
		a._symType = SymbolType::None;
		a._objArg._value = v;
		a._objArg._offset = -1;

		return a;
	}

	static Argument Construct(Operand t, int v, int offset)
	{
		Argument a;

		a._argType = t;
		a._symType = SymbolType::None;
		a._objArg._value = v;
		a._objArg._offset = offset;

		return a;
	}

	static Argument Construct(Operand t, int symbol, SymbolType::Enum symType)
	{
		Argument a;

		a._argType = t;
		a._symType = symType;

		// We store the symbol index here, but we replace it later in ResolveSymbol
		a._objArg._value = symbol;
		a._objArg._offset = -1;

		return a;
	}

	static Argument ConstructNone()
	{
		return Construct(Operand::None(), 0);
	}

	void Deref();
	void AddressOf();
	void ResolveSymbol();

public:
	Operand _argType;
	ObjArgument _objArg;
	SymbolType::Enum _symType;
};
