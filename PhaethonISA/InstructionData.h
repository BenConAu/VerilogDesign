#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "OperandType.h"

struct InstructionData
{
	Instructions::Enum instr;
	OpCodes::Enum opCode;
	OperandType argTypes[3];
	int wordArg;
	const char* pszName;

    static InstructionData s_data[];
    static int s_dataCount;
};
