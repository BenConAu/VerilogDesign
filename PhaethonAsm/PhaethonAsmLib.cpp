#include "PhaethonAsmLib.h"
#include "PhaethonAsm.tab.h"
#include <iostream>
#include <vector>

struct LabelData
{
	int symIndex;
	int address;
};

int g_byteCount = 0;
std::vector<LabelData> g_labels;
std::vector<std::string> g_symbols;

int AddSymbol(const char* pszSymbol)
{
	for (size_t i = 0; i < g_labels.size(); i++)
	{
		if (g_symbols[i] == pszSymbol)
		{
			// Already there!
			return i;
		}
	}

	//printf("Adding symbol %s\n", pszSymbol);
	g_symbols.push_back(pszSymbol);
	return (g_symbols.size() - 1);
}

void AddLabel(int symIndex)
{
	//printf("Adding label %d with value %x\n", symIndex, g_byteCount);
	LabelData d = { symIndex, g_byteCount };
	g_labels.push_back(d);
}

int GetSymbolAddress(int symIndex)
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

struct InstructionData
{
	Instructions::Enum instr;
	unsigned char opCode;
	Argument::Type arg1;
	Argument::Type arg2;
	bool swapArgs;
};

InstructionData g_data[] = {
	{ Instructions::Mov,    1, Argument::Register, Argument::Constant, false },
	{ Instructions::Mov,    2, Argument::Register, Argument::Address,  false },
	{ Instructions::Mov,    3, Argument::Register, Argument::Constant, false },
	{ Instructions::Mov,    4, Argument::Address,  Argument::Register, true  },

	{ Instructions::Cmp,    5, Argument::Register, Argument::Register, false },
	{ Instructions::Jmp,    6, Argument::Address,  Argument::None,     false },

	{ Instructions::Fadd,  20, Argument::Register, Argument::Register, false },
	{ Instructions::Fconv, 22, Argument::Register, Argument::None,     false },
	{ Instructions::Fmul,  23, Argument::Register, Argument::Register, false },
};

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2)
{
	for (int i = 0; i < sizeof(g_data) / sizeof(g_data[0]); i++)
	{
		if (g_data[i].instr == instr && 
			g_data[i].arg1 == a1._type && 
			g_data[i].arg2 == a2._type)
		{
			if (g_data[i].swapArgs)
			{
				OutputBytes(g_data[i].opCode, a2._value, a1._value, 0);
			}
			else
			{
				OutputBytes(g_data[i].opCode, a1._value, a2._value, 0);
			}

			return;
		}
	}

	std::cout << "Unknown instruction" << instr << std::endl;
}
