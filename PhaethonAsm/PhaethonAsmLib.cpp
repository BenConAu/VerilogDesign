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
	Argument::Type args[3];
	int wordArg;
};

InstructionData g_data[] = {
	{ Instructions::Mov,      1, { Argument::Register, Argument::Constant, Argument::None     },     1  },
	{ Instructions::Mov,      2, { Argument::Register, Argument::Address,  Argument::None     },     1  },
	{ Instructions::Mov,      3, { Argument::Register, Argument::Register, Argument::None     },     -1 },
	{ Instructions::Mov,      4, { Argument::Address,  Argument::Register, Argument::None     },     0  },

	{ Instructions::Cmp,      5, { Argument::Register, Argument::Register, Argument::None     },     -1 },
	{ Instructions::Jmp,      6, { Argument::Address,  Argument::None,     Argument::None     },     0 },
 
	{ Instructions::Fadd,    20, { Argument::Register, Argument::Register, Argument::None     },     -1 },
	{ Instructions::Fconv,   22, { Argument::Register, Argument::None,     Argument::None     },     -1 },
	{ Instructions::Fmul,    23, { Argument::Register, Argument::Register, Argument::None     },     -1 },
	{ Instructions::Fmuladd, 24, { Argument::Register, Argument::Register, Argument::Register },     -1 },
	{ Instructions::Fmin,    25, { Argument::Register, Argument::Register, Argument::Register },     -1 },
};

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3)
{
	for (int i = 0; i < sizeof(g_data) / sizeof(g_data[0]); i++)
	{
		if (g_data[i].instr == instr && 
			g_data[i].args[0] == a1._type && 
			g_data[i].args[1] == a2._type &&
			g_data[i].args[2] == a3._type)
		{
			OutputBytes(g_data[i].opCode, a1._value, a2._value, a3._value);

			if (g_data[i].wordArg != -1)
			{
                Argument args[3] = { a1, a2, a3 };

				unsigned int opDataWord = args[g_data[i].wordArg]._value;

				OutputBytes(
					static_cast<unsigned char>(opDataWord & 0xFF),
					static_cast<unsigned char>(opDataWord >> 8 & 0xFF),
					static_cast<unsigned char>(opDataWord >> 16 & 0xFF),
					static_cast<unsigned char>(opDataWord >> 24 & 0xFF)
					);
			}

			return;
		}
	}

	std::cout << "Unknown instruction" << instr << std::endl;
}
