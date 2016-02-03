#pragma once

#include <string>

namespace OperandType
{
	enum Enum
	{
		None = 0,
		Constant = 1,
		Register = 2,
	};
}

namespace OperandModifier
{
	enum Enum
	{
		None,
		Deref,
		AddressOf
	};
}

class ArgumentBase
{
public:
	static ArgumentBase Construct(OperandType::Enum t, OperandModifier::Enum m, bool o)
	{
		ArgumentBase base;

		base._type = t;
		base._modifier = m;
		base._fOffset = o;

		return base;
	}

	static ArgumentBase Register()
	{
		ArgumentBase base;

		base._type = OperandType::Register;
		base._modifier = OperandModifier::None;
		base._fOffset = false;

		return base;
	}

	static ArgumentBase DerefRegister()
	{
		ArgumentBase base;

		base._type = OperandType::Register;
		base._modifier = OperandModifier::Deref;
		base._fOffset = false;

		return base;
	}

	static ArgumentBase RegisterOffset()
	{
		ArgumentBase base;

		base._type = OperandType::Register;
		base._modifier = OperandModifier::None;
		base._fOffset = true;

		return base;
	}

	static ArgumentBase DerefRegisterOffset()
	{
		ArgumentBase base;

		base._type = OperandType::Register;
		base._modifier = OperandModifier::Deref;
		base._fOffset = true;

		return base;
	}

	static ArgumentBase Constant()
	{
		ArgumentBase base;

		base._type = OperandType::Constant;
		base._modifier = OperandModifier::None;
		base._fOffset = false;

		return base;
	}

	static ArgumentBase DerefConstant()
	{
		ArgumentBase base;

		base._type = OperandType::Constant;
		base._modifier = OperandModifier::Deref;
		base._fOffset = false;

		return base;
	}

	static ArgumentBase AddressOfConstant()
	{
		ArgumentBase base;

		base._type = OperandType::Constant;
		base._modifier = OperandModifier::AddressOf;
		base._fOffset = false;

		return base;
	}

	static ArgumentBase None()
	{
		ArgumentBase base;

		base._type = OperandType::None;
		base._modifier = OperandModifier::None;
		base._fOffset = false;

		return base;
	}

	std::string GetShortTypeText()
	{
		std::string shortTypeText;
		if (_modifier == OperandModifier::Deref)
		{
			shortTypeText.append("d");
		}
		else if (_modifier == OperandModifier::AddressOf)
		{
			shortTypeText.append("a");
		}
		shortTypeText.append(ppszShortTypeText[_type]);
		if (_fOffset)
		{
			shortTypeText.append("o");
		}

		return shortTypeText;
	}

	std::string GetTypeText()
	{
		std::string typeText;
		if (_modifier == OperandModifier::Deref)
		{
			typeText.append("Deref");
		}
		else if (_modifier == OperandModifier::AddressOf)
		{
			typeText.append("AddressOf");
		}
		typeText.append(ppszTypeText[_type]);
		if (_fOffset)
		{
			typeText.append("Offset");
		}
		typeText.append("()");

		return typeText;
	}

	bool operator==(const ArgumentBase other)
	{
		return (_type == other._type && _modifier == other._modifier && _fOffset == other._fOffset);
	}

	OperandType::Enum _type;
	OperandModifier::Enum _modifier;
	bool _fOffset;

private:
    static const char* ppszTypeText[];
    static const char* ppszShortTypeText[];
};
