#pragma once

#include <string>

// This enumeration represents the different types of operand arguments that
// the assembly can represent. In practice most of them will need to be
// converted to a register.
enum class OperandType : int
{
    None = 0,       // Used for error conditions and the such
    Constant,       // The result is a constant
    Register,       // The result is stored in a register
    ConstantMemory, // The result is a memory location (also a constant, technically)
	RegisterMemory, // The result is a memory location (stored in a register) - not used by SL yet
    MemoryOffset,   // The result is a memory location plus an offset
};

class ISAOperand
{
public:
	static ISAOperand Construct(OperandType t, bool deref)
	{
		ISAOperand base;

		if (t == OperandType::Register)
		{
			if (deref)
			{
				t = OperandType::RegisterMemory;
			}
		}

		if (t == OperandType::Constant)
		{
			if (deref)
			{
				t = OperandType::ConstantMemory;
			}
		}

		base._type = t;

		return base;
	}

	static ISAOperand Register()
	{
		ISAOperand base;

		base._type = OperandType::Register;

		return base;
	}

	static ISAOperand DerefRegister()
	{
		ISAOperand base;

		base._type = OperandType::RegisterMemory;

		return base;
	}

	static ISAOperand DerefRegisterOffset()
	{
		ISAOperand base;

		base._type = OperandType::MemoryOffset;

		return base;
	}

	static ISAOperand Constant()
	{
		ISAOperand base;

		base._type = OperandType::Constant;

		return base;
	}

	static ISAOperand DerefConstant()
	{
		ISAOperand base;

		base._type = OperandType::ConstantMemory;

		return base;
	}

	static ISAOperand None()
	{
		ISAOperand base;

		base._type = OperandType::None;

		return base;
	}

	std::string GetShortTypeText()
	{
		std::string shortTypeText;
		shortTypeText.append(ppszShortTypeText[static_cast<int>(_type)]);

		return shortTypeText;
	}

	std::string GetTypeText()
	{
		std::string typeText;
		typeText.append(ppszTypeText[static_cast<int>(_type)]);
		typeText.append("()");

		return typeText;
	}

	bool operator==(const ISAOperand other)
	{
		return (_type == other._type);
	}

	bool IsRAMOpcode() const
	{
		if (_type == OperandType::ConstantMemory ||
			_type == OperandType::RegisterMemory ||
			_type == OperandType::MemoryOffset
			)
		{
			return true;
		}

		return false;
	}

	bool Is8ByteOpcode() const
	{
		if (_type == OperandType::Constant ||
			_type == OperandType::ConstantMemory ||
			_type == OperandType::MemoryOffset
			)
		{
			return true;
		}

		return false;
	}

	OperandType _type;

private:
    static const char* ppszTypeText[];
    static const char* ppszShortTypeText[];
};
