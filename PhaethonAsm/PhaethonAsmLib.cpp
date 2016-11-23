#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "DataSegmentDef.h"
#include "InstructionNode.h"
#include "PhaethonAsm.tab.h"
#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include "../PhaethonISA/InstructionData.h"
#include <iostream>
#include <vector>

StructDef::StructDefInfo StructDef::s_defInfo;

std::vector<std::unique_ptr<AssemblerNode> > s_nodeDefs;

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

void OutputCode()
{
	// Make sure that the symbols are resolved
	DataSegmentDef::ResolveSymbols();

	// Now output all of the instructions
	for (size_t i = 0; i < s_nodeDefs.size(); i++)
	{
		InstructionNode* pInstr = dynamic_cast<InstructionNode*>(s_nodeDefs[i].get());
		if (pInstr != nullptr)
		{
			pInstr->OutputInstruction();
		}
	}

	// Now the data segments can be printed
	for (size_t i = 0; i < s_nodeDefs.size(); i++)
	{
		DataSegmentDef* pDS = dynamic_cast<DataSegmentDef*>(s_nodeDefs[i].get());
		if (pDS != nullptr)
		{
			pDS->OutputDataSegment();
		}
	}
}
