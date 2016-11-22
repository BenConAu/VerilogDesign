#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "../PhaethonISA/ISAOperand.h"

struct InstructionData
{
	Instructions::Enum instr;
	OpCodes::Enum opCode;
	Operand args[3];
	int wordArg;
	const char* pszName;

    static InstructionData s_data[];
    static int s_dataCount;
};
