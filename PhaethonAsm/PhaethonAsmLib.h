#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "Argument.h"
#include <vector>

extern BinaryObjWriter s_writer;

void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
int AddSymbol(const char* pszSymbol);
int GetLabelAddress(int symIndex);
void AddLabel(int symIndex);
void OutputCode();
