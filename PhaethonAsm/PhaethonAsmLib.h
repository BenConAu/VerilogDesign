#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "../PhaethonObjWriter/BinaryObjWriter.h"
#include "Argument.h"
#include <vector>

extern BinaryObjWriter s_writer;

void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
int AddSymbol(const char* pszSymbol);
int GetLabelAddress(int symIndex);
void AddLabel(int symIndex);
void OutputCode();

class StructDef;
class StructMember;
class DataSegmentDef;
class DataSegmentItemDef;
class DataSegmentItemEntry;
class InstructionNode;

struct ParseStruct 
{
	int intVal;
	float floatVal;
	Instructions::Enum instrIndex;
	int regIndex;
	int symIndex;
	Argument arg;
	StructDef* structDef;
	StructMember* structMember;
	DataSegmentDef* dataSegmentDef;
	DataSegmentItemDef* dataSegmentItemDef;
	DataSegmentItemEntry* dataSegmentItemEntry;
	InstructionNode* instructonNode;
};
