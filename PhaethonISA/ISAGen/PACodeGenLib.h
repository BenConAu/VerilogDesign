#pragma once

#include "../ISAOperand.h"

void StoreInstruction(int symIndex, Operand arg1, Operand arg2, Operand arg3, int flag);
int AddSymbol(const char* pszSymbol);
void OutputInstructions();
