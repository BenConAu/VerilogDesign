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

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2)
{
	switch(instr)
	{
		case Instructions::Mov:
			unsigned char opCode;
			if (a1._type == Argument::Register && a2._type == Argument::Constant)
			{
				opCode = 1;
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Address)
			{
				opCode = 2;
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Register)
			{
				opCode = 3;
			}
			else if (a1._type == Argument::Address && a2._type == Argument::Register)
			{
				opCode = 4;
				Argument t = a1;
				a1 = a2;
				a2 = t;
			}

			OutputBytes(opCode, a1._value, a2._value, 0);				
			break;

		case Instructions::Cmp:
        	if (a1._type != Argument::Register || a2._type != Argument::Register)
        	{
        		std::cout << "Invalid argument for fconv" << std::endl;
        	}
        	OutputBytes(5, a1._value, a2._value, 0);

		case Instructions::Fadd:
        	if (a1._type != Argument::Register || a2._type != Argument::Register)
        	{
        		std::cout << "Invalid argument for fadd" << std::endl;
        	}

        	OutputBytes(20, a1._value, a2._value, 0);
        	break;

		default:
			std::cout << "Unknown instruction" << instr << std::endl;
	}
}

void OutputInstruction(Instructions::Enum instr, Argument a1)
{
	switch(instr)
	{
        case Instructions::Fconv:
        	if (a1._type != Argument::Register)
        	{
        		std::cout << "Invalid argument for fconv" << std::endl;
        	}

        	OutputBytes(22, a1._value, 0, 0);
        	break;

        case Instructions::Jmp:
        	if (a1._type != Argument::Address)
        	{
        		std::cout << "Invalid argument for jmp" << std::endl;
        	}
        	OutputBytes(6, a1._value, 0, 0);
        	break;

		default:
			std::cout << "Unknown instruction" << std::endl;
	}
}
