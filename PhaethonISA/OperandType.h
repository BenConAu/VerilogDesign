#pragma once

#include <string>

// This enumeration represents the different types of operand arguments that
// the hardware can represent. Registers and constants are by far the most
// common operand arguments.
enum class OperandType : int
{
    None = 0,       		// Used for error conditions and the such or unintialized types
	ByteConstant,           // The operand is a byte constant
    Constant,       		// The operand is a word wonstant
    Register,       		// The operand is a register
    DerefConstant,  		// The operand is a memory location at the given constant location
	DerefRegister,  		// The operand is a memory location at the given register location
    DerefRegisterOffset,	// Just like above, but with a constant offset
};

class OperandTypeHelper
{
public:
	static std::string GetShortTypeText(OperandType type)
	{
		std::string shortTypeText;
		shortTypeText.append(ppszShortTypeText[static_cast<int>(type)]);

		return shortTypeText;
	}

	static std::string GetTypeText(OperandType type)
	{
		std::string typeText;
		typeText.append(ppszTypeText[static_cast<int>(type)]);

		return typeText;
	}

private:
    static const char* ppszTypeText[];
    static const char* ppszShortTypeText[];
};