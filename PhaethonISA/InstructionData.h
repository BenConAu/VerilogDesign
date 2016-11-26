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

	// Table of data about opcodes
    static OpCodeData s_data[];
    static int s_dataCount;
};

struct InstructionDataReal
{
	Instructions::Enum instr;
	const char* pszName;

	static InstructionDataReal s_data[];
	static int s_dataCount;
};