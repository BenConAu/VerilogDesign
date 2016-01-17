#pragma once

#include "PhaethonAsmTypes.h"

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
int AddSymbol(const char* pszSymbol);
int GetSymbolAddress(int symIndex);
void AddLabel(int symIndex);