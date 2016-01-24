#include "PACodeGenLib.h"
#include "PACodeGen.tab.h"
#include "../Argument.h"
#include <string>
#include <vector>
#include <map>

static std::vector<std::string> g_symbols;

struct InstructionData
{
    InstructionData(int si, int a1, int a2, int a3)
    {
        symIndex = si;

        args[0] = a1;
        args[1] = a2;
        args[2] = a3;

        constIndex = -1;
        opCode = g_symbols[symIndex];

        for (int i = 0; i < 3; i++)
        {
            if (args[i] == Argument::Constant || args[i] == Argument::ConstAddress)
            {
                if (constIndex == -1)
                {
                    constIndex = i;
                }
                else
                {
                    throw("Too many words stored in instruction");
                }
            }

            opCode.append(Argument::ppszShortTypeText[args[i]]);
        }
    }

    int symIndex;
    int args[3];
    int constIndex;
    std::string opCode;
};

static std::vector<InstructionData> g_instructionData;

void StoreInstruction(int symIndex, int arg1, int arg2, int arg3)
{
    InstructionData data(symIndex, arg1, arg2, arg3);
    g_instructionData.push_back(data);
}

int AddSymbol(const char* pszSymbol)
{
    for (size_t i = 0; i < g_symbols.size(); i++)
    {
        if (g_symbols[i].compare(pszSymbol) == 0)
        {
            return i;
        }
    }

    g_symbols.push_back(pszSymbol);
    return g_symbols.size() - 1;
}

std::string Pad(std::string s, int len)
{
    std::string padded = s;

    if (s.length() < len)
    {
        padded.append(len - s.length(), ' ');
    }

    return padded;
}

void OutputInstructions()
{
    FILE* fhfile = ::fopen("PhaethonOpCode.h", "w");

    // First the enum of Instructions
    ::fprintf(fhfile, "namespace Instructions\n{\n    enum Enum\n    {\n        Unknown,\n");
    for (size_t i = 0; i < g_symbols.size(); i++)
    {
        ::fprintf(fhfile, "        %s,\n", g_symbols[i].c_str());
    }
    ::fprintf(fhfile, "    };\n}\n");

    // The opCode enum
    ::fprintf(fhfile, "namespace OpCodes\n{\n    enum Enum\n    {\n        Unknown = 0,\n");
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        ::fprintf(fhfile, "        %s = %d,\n", data.opCode.c_str(), (int)i + 1);
    }
    ::fprintf(fhfile, "    };\n}\n");

    ::fclose(fhfile);

    FILE* fcppfile = ::fopen("PhaethonOpCode.cpp", "w");

    // Now the collection of instruction data
    ::fprintf(fcppfile, "InstructionData g_data[] = {\n");
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];
        ::fprintf(fcppfile, "    { Instructions::%s, { Argument::%s, Argument::%s, Argument::%s }, %d },\n",
            Pad(g_symbols[data.symIndex], 10).c_str(),
            Pad(Argument::ppszTypeText[data.args[0]], 15).c_str(),
            Pad(Argument::ppszTypeText[data.args[1]], 15).c_str(),
            Pad(Argument::ppszTypeText[data.args[2]], 15).c_str(),
            data.constIndex
        );
    }
    ::fprintf(fcppfile, "};\n");

    ::fclose(fcppfile);

    // Now the Verilog
    FILE* fvfile = ::fopen("PhaethonOpCode.v", "w");

    // The opCode enum does as defines in verilog
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        ::fprintf(fvfile, "`define %s %d\n", data.opCode.c_str(), (int)i + 1);
    }
    ::fprintf(fvfile, "\n");

    // Verilog function to tell opCodes that have constant data
    ::fprintf(fvfile, "function [0:0] Is8ByteOpcode;\n  input [7:0] opCodeParam;\n  if (");
    bool fFirst = true;
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        if (data.constIndex != -1)
        {
            if (!fFirst)
            {
                fprintf(fvfile, ",\n      ");
            }

            ::fprintf(fvfile, "opCodeParam == %s", data.opCode.c_str());

            fFirst = false;
        }
    }
    ::fprintf(fvfile, ")\n    Is8ByteOpcode = 1;\n  else\n    Is8ByteOpcode = 0;\nendfunction\n");

    ::fclose(fvfile);
}
