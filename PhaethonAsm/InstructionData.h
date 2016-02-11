#pragma once

#include "CodeGen/PhaethonOpCode.h"
#include "ArgumentBase.h"

struct InstructionData
{
	Instructions::Enum instr;
	OpCodes::Enum opCode;
	ArgumentBase args[3];
	int wordArg;
	const char* pszName;

    static InstructionData s_data[];
    static int s_dataCount;
};
