#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"

struct ObjArgument;

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
void OutputWord(unsigned int w);
void OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument* args,
    int wordArg
    );
