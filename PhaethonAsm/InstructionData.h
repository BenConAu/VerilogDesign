#pragma once

#include "../PhaethonISA/PhaethonOpCode.h"
#include "Operand.h"

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
