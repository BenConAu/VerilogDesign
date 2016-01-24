#pragma once

#include "CodeGen/PhaethonOpCode.h"
#include "Argument.h"

struct InstructionData
{
	Instructions::Enum instr;
	OpCodes::Enum opCode;
	Argument::Type args[3];
	int wordArg;

    static InstructionData s_data[];
    static int s_dataCount;
};
