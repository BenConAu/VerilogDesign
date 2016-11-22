#pragma once

#include <string>

// This enumeration represents the different types of operand arguments that
// the hardware can represent. Registers and constants are by far the most
// common operand arguments.
enum class OperandType : int
{
    None = 0,       		// Used for error conditions and the such or unintialized types
    Constant,       		// The operand is a constant
    Register,       		// The operand is a register
    DerefConstant,  		// The operand is a memory location at the given constant location
	DerefRegister,  		// The operand is a memory location at the given register location
    DerefRegisterOffset,	// Just like above, but with a constant offset
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
				t = OperandType::DerefRegister;
			}
		}

		if (t == OperandType::Constant)
		{
			if (deref)
			{
				t = OperandType::DerefConstant;
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

		base._type = OperandType::DerefRegister;

		return base;
	}

	static ISAOperand DerefRegisterOffset()
	{
		ISAOperand base;

		base._type = OperandType::DerefRegisterOffset;

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

		base._type = OperandType::DerefConstant;

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

	// Return true for opcodes that read / write RAM
	bool IsRAMOpcode() const
	{
		if (_type == OperandType::DerefConstant ||
			_type == OperandType::DerefRegister ||
			_type == OperandType::DerefRegisterOffset
			)
		{
			return true;
		}

		return false;
	}

	// Return true for opcodes that need 8 bytes to store
	bool Is8ByteOpcode() const
	{
		if (_type == OperandType::Constant ||
			_type == OperandType::DerefConstant ||
			_type == OperandType::DerefRegisterOffset
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
