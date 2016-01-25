#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "DataSegmentDef.h"
#include "InstructionNode.h"
#include "PhaethonAsm.tab.h"
#include "CodeGen/PhaethonOpCode.h"
#include "InstructionData.h"
#include <iostream>
#include <vector>

std::vector<std::unique_ptr<StructDef> > StructDef::s_defs;
std::vector<std::unique_ptr<StructMember> > StructMember::s_defs;
std::vector<std::unique_ptr<DataSegmentDef> > DataSegmentDef::s_defs;
std::vector<std::unique_ptr<DataSegmentItemDef> > DataSegmentItemDef::s_defs;
std::vector<std::unique_ptr<DataSegmentItemEntry> > DataSegmentItemEntry::s_defs;
std::vector<std::unique_ptr<InstructionNode> > InstructionNode::s_defs;

StructDef::StructDefInfo StructDef::s_defInfo;

struct LabelData
{
	int symIndex;
	int address;
};

std::vector<LabelData> g_labels;

int AddSymbol(const char* pszSymbol)
{
	static std::vector<std::string> g_symbols;

	//printf("AddSymbol size is now %d\n", (int)g_symbols.size());

	for (size_t i = 0; i < g_symbols.size(); i++)
	{
		//printf("  Comparing %d:%s to %s\n", (int)i, g_symbols[i].c_str(), pszSymbol);

		if (g_symbols[i].compare(pszSymbol) == 0)
		{
			//printf("Already there\n");
			return i;
		}
	}

	//printf("Adding symbol %s at %d\n", pszSymbol, (int)g_symbols.size());
	g_symbols.push_back(pszSymbol);
	return (g_symbols.size() - 1);
}

void AddLabel(int symIndex)
{
	//printf("Adding label %d with value %x\n", symIndex, g_byteCount);
	LabelData d = { symIndex, InstructionNode::GetCodeSize() };
	g_labels.push_back(d);
}

int GetLabelAddress(int symIndex)
{
	for (size_t i = 0; i < g_labels.size(); i++)
	{
		if (g_labels[i].symIndex == symIndex)
		{
			return g_labels[i].address;
		}
	}

    printf("%d labels in table\n", (int)g_labels.size());
    printf("Symbol %d not found\n", symIndex);
	return -1;
}

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputWord(unsigned int w)
{
	OutputBytes(
		static_cast<unsigned char>(w & 0xFF),
		static_cast<unsigned char>(w >> 8 & 0xFF),
		static_cast<unsigned char>(w >> 16 & 0xFF),
		static_cast<unsigned char>(w >> 24 & 0xFF)
		);
}

void OutputCode()
{
	// Make sure that the symbols are resolved
	DataSegmentDef::ResolveSymbols();

	// Now output all of the instructions
	for (size_t i = 0; i < InstructionNode::GlobalList().size(); i++)
	{
		InstructionNode::GlobalList()[i]->OutputInstruction();
	}

	// Now the data segments can be printed
	for (size_t ds = 0; ds < DataSegmentDef::GlobalList().size(); ds++)
	{
		DataSegmentDef::GlobalList()[ds]->OutputDataSegment();
	}
}
