#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "OperandType.h"

struct OpCodeData
{
	// The enum of the corresponding instruction
	Instructions::Enum instr;

	// The enum of the opcode
	OpCodes::Enum opCode;

	// The types of the operands that the opcode takes
	OperandType argTypes[3];

	// Which of the operands supplies the word (if any)
	int wordArg;

	// The name of the opcode (used to generate code)
	const char* pszName;

	int OperandCount()
	{
		if (argTypes[0] == OperandType::None)
		{
			return 0;
		}

		if (argTypes[1] == OperandType::None)
		{
			return 1;
		}

		if (argTypes[2] == OperandType::None)
		{
			return 2;
		}

		return 3;
	}

	// Table of data about opcodes
    static OpCodeData s_data[];
    static int s_dataCount;
};

struct InstructionData
{
	// The enum of the instruction
	Instructions::Enum instr;

	// The name of the instruction
	const char* pszName;

	static InstructionData s_data[];
	static int s_dataCount;
};