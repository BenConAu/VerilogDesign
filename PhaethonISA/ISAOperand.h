#pragma once

#include "OperandType.h"

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
};
