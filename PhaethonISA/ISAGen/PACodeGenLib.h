#pragma once

#include "ISAOperand.h"

void StoreInstruction(int symIndex, ISAOperand arg1, ISAOperand arg2, ISAOperand arg3, int flag);
int AddSymbol(const char* pszSymbol);
void OutputInstructions();
