#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "Argument.h"

void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
int AddSymbol(const char* pszSymbol);
int GetLabelAddress(int symIndex);
void AddLabel(int symIndex);
void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
void OutputWord(unsigned int w);
void OutputCode();
