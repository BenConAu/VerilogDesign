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

class Argument
{
public:
	static Argument Construct(ArgumentBase t, int v)
	{
		Argument a;

		a._argType = t;
		a._value = v;
		a._symType = SymbolType::None;
		a._offset = -1;

		return a;
	}

	static Argument Construct(ArgumentBase t, int v, int offset)
	{
		Argument a;

		a._argType = t;
		a._value = v;
		a._symType = SymbolType::None;
		a._offset = offset;

		return a;
	}

	static Argument Construct(ArgumentBase t, int symbol, SymbolType::Enum symType)
	{
		Argument a;

		a._argType = t;
		a._value = symbol;
		a._symType = symType;
		a._offset = -1;

		return a;
	}

	static Argument ConstructNone()
	{
		return Construct(ArgumentBase::None(), 0);
	}

	void Deref()
	{
		if (_argType._modifier != OperandModifier::None)
		{
			printf("You already had a modifer\n");
		}

		_argType._modifier = OperandModifier::Deref;
	}

	void AddressOf()
	{
		if (_argType._type == OperandType::Constant && _symType == SymbolType::None)
		{
			printf("Wat - address of non symbol constant makes no sense\n");
		}

		if (_argType._type == OperandType::Register)
		{
			printf("Wat - address of register makes no sense\n");
		}

		if (_argType._type == OperandType::Constant &&
			_argType._modifier == OperandModifier::Deref &&
			_symType == SymbolType::VarAddress)
		{
			// Somebody wants to store the address of a variable, so
			// changing the modifer will give us the right thing after
			// the symbol has been looked up
			_argType._modifier = OperandModifier::None;
		}
	}

	void ResolveSymbol();

public:
	ArgumentBase _argType;
	unsigned int _value;
	unsigned int _offset;
	SymbolType::Enum _symType;
};
