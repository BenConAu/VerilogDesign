#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "Argument.h"
#include <vector>

void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
int AddSymbol(const char* pszSymbol);
int GetLabelAddress(int symIndex);
void AddLabel(int symIndex);
void OutputCode();
