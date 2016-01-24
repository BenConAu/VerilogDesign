#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "DataSegmentDef.h"
#include "PhaethonAsm.tab.h"
#include "PhaethonAsmTypes.h"
#include <iostream>
#include <vector>

std::vector<std::unique_ptr<StructDef> > StructDef::s_defs;
std::vector<std::unique_ptr<StructMember> > StructMember::s_defs;
std::vector<std::unique_ptr<DataSegmentDef> > DataSegmentDef::s_defs;
std::vector<std::unique_ptr<DataSegmentItemDef> > DataSegmentItemDef::s_defs;
std::vector<std::unique_ptr<DataSegmentItemEntry> > DataSegmentItemEntry::s_defs;

StructDef::StructDefInfo StructDef::s_defInfo;

struct LabelData
{
	int symIndex;
	int address;
};

int g_byteCount = 0;
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
	OpCodes::Enum opCode;
	Argument::Type args[3];
	int wordArg;
};

InstructionData g_data[] = {
    { Instructions::Mov       , OpCodes::MovRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Mov       , OpCodes::MovRcA         , { Argument::Register       , Argument::ConstAddress   , Argument::None            }, 1 },
    { Instructions::Mov       , OpCodes::MovRR          , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Mov       , OpCodes::MovcAR         , { Argument::ConstAddress   , Argument::Register       , Argument::None            }, 0 },
    { Instructions::Mov       , OpCodes::MovRrAC        , { Argument::Register       , Argument::RegAddress     , Argument::Constant        }, 2 },
    { Instructions::Mov       , OpCodes::MovrACR        , { Argument::RegAddress     , Argument::Constant       , Argument::Register        }, 1 },
    { Instructions::Mov       , OpCodes::MovRrA         , { Argument::Register       , Argument::RegAddress     , Argument::None            }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRR          , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Cmp       , OpCodes::CmpRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Jmp       , OpCodes::JmpC           , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Jne       , OpCodes::JneC           , { Argument::Constant       , Argument::None           , Argument::None            }, 0 },
    { Instructions::Add       , OpCodes::AddRC          , { Argument::Register       , Argument::Constant       , Argument::None            }, 1 },
    { Instructions::Inc       , OpCodes::IncR           , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Dec       , OpCodes::DecR           , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fadd      , OpCodes::FaddRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fsub      , OpCodes::FsubRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fconv     , OpCodes::FconvR         , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
    { Instructions::Fmul      , OpCodes::FmulRR         , { Argument::Register       , Argument::Register       , Argument::None            }, -1 },
    { Instructions::Fmuladd   , OpCodes::FmuladdRRR     , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Fmin      , OpCodes::FminRRR        , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Fmax      , OpCodes::FmaxRRR        , { Argument::Register       , Argument::Register       , Argument::Register        }, -1 },
    { Instructions::Dout      , OpCodes::DoutR          , { Argument::Register       , Argument::None           , Argument::None            }, -1 },
};

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);

	g_byteCount += 4;
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

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3)
{
	//printf("Processing instruction\n");

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

				OutputWord(opDataWord);
			}

			return;
		}
	}

	std::cout << "Unknown instruction instr = " << instr << ", " << a1._type << ", " << a2._type << ", " << a3._type << std::endl;
}

void OutputDataSegment()
{
	if (DataSegmentDef::s_defs.size() != 0)
	{
		int startByte = DataSegmentDef::s_defs[0]->GetIntProperty("address");

		for (int i = g_byteCount; i < startByte; i += 4)
		{
			OutputBytes(0x1a, 0x2b, 0x3c, 0x4d);
		}

		for (int i = 0; i < DataSegmentDef::s_defs[0]->GetItemCount(); i++)
		{
			//		printf("Doing item %d in Data segment\n", i);

			DataSegmentItemDef* itemDef = DataSegmentDef::s_defs[0]->GetItem(i);
			//		printf("Item %d has count %d\n", i, itemDef->GetItemCount());

			for (int j = 0; j < itemDef->GetItemCount(); j++)
			{
				DataSegmentItemEntry* entry = itemDef->GetItem(j);

				OutputWord(entry->GetIntProperty("value"));
			}
		}
	}
}
