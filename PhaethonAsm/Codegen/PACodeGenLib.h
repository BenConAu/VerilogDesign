#pragma once

#include "../ArgumentBase.h"

void StoreInstruction(int symIndex, ArgumentBase arg1, ArgumentBase arg2, ArgumentBase arg3, int flag);
int AddSymbol(const char* pszSymbol);
void OutputInstructions();
