#include "PACodeGenLib.h"
#include "PACodeGen.tab.h"
#include <string>
#include <vector>
#include <map>

static std::vector<std::string> g_symbols;

struct InstructionData
{
    InstructionData(int si, ISAOperand a1, ISAOperand a2, ISAOperand a3, int flag)
    {
        symIndex = si;

        args[0] = a1;
        args[1] = a2;
        args[2] = a3;

        constIndex = -1;
        fRAM = false;
        opCode = g_symbols[symIndex];

        for (int i = 0; i < 3; i++)
        {
            if (args[i].Is8ByteOpcode())
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

            if (args[i].IsRAMOpcode() || flag == 1)
            {
                fRAM = true;
            }

            opCode.append(ISAOperand::GetShortTypeText(args[i]._type));
        }
    }

    int symIndex;
    ISAOperand args[3];
    int constIndex;
    bool fRAM;
    std::string opCode;
};

static std::vector<InstructionData> g_instructionData;

void StoreInstruction(int symIndex, ISAOperand arg1, ISAOperand arg2, ISAOperand arg3, int flag)
{
    InstructionData data(symIndex, arg1, arg2, arg3, flag);
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
    FILE* fhfile = ::fopen("Generated/PhaethonOpCode.h", "w");

    ::fprintf(fhfile, "#pragma once\n\n");

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

    ::fprintf(fhfile, "bool Is8ByteOpcode(OpCodes::Enum opCodeParam);\n");
    ::fprintf(fhfile, "bool IsRAMOpcode(OpCodes::Enum opCodeParam);\n");

    ::fclose(fhfile);

    FILE* fcppfile = ::fopen("Generated/PhaethonOpCode.cpp", "w");

    ::fprintf(fcppfile, "#include \"../InstructionData.h\"\n\n");

    // Now the collection of instruction data
    ::fprintf(fcppfile, "InstructionData InstructionData::s_data[] = {\n");
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];
        ::fprintf(fcppfile, "    { Instructions::%s, OpCodes::%s, { ISAOperand::%s, ISAOperand::%s, ISAOperand::%s }, %d, \"%s\" },\n",
            Pad(g_symbols[data.symIndex], 10).c_str(),
            Pad(data.opCode, 15).c_str(),
            Pad(ISAOperand::GetTypeText(data.args[0]._type), 22).c_str(),
            Pad(ISAOperand::GetTypeText(data.args[1]._type), 22).c_str(),
            Pad(ISAOperand::GetTypeText(data.args[2]._type), 12).c_str(),
            data.constIndex,
            data.opCode.c_str()
        );
    }
    ::fprintf(fcppfile, "};\n\n");

    ::fprintf(fcppfile, "int InstructionData::s_dataCount = sizeof(InstructionData::s_data) / sizeof(InstructionData::s_data[0]);\n\n");

    // Cpp function to tell opCodes that have constant data
    ::fprintf(fcppfile, "bool Is8ByteOpcode(OpCodes::Enum opCodeParam)\n{\n    if (");
    bool fFirst = true;
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        if (data.constIndex != -1)
        {
            if (!fFirst)
            {
                fprintf(fcppfile, " ||\n        ");
            }

            ::fprintf(fcppfile, "opCodeParam == OpCodes::%s", data.opCode.c_str());

            fFirst = false;
        }
    }
    ::fprintf(fcppfile, ")\n        return true;\n    else\n        return false;\n}\n\n");

    // Cpp function to tell opCodes that read or write RAM
    ::fprintf(fcppfile, "bool IsRAMOpcode(OpCodes::Enum opCodeParam)\n{\n    if (");
    fFirst = true;
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        if (data.fRAM)
        {
            if (!fFirst)
            {
                fprintf(fcppfile, " ||\n        ");
            }

            ::fprintf(fcppfile, "opCodeParam == OpCodes::%s", data.opCode.c_str());

            fFirst = false;
        }
    }
    ::fprintf(fcppfile, ")\n        return true;\n    else\n        return false;\n}\n\n");

    ::fclose(fcppfile);

    // Now the Verilog
    FILE* fvfile = ::fopen("Generated/PhaethonOpCode.v", "w");

    // The opCode enum does as defines in verilog
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        ::fprintf(fvfile, "`define %s %d\n", data.opCode.c_str(), (int)i + 1);
    }
    ::fprintf(fvfile, "\n");

    // Verilog function to tell opCodes that have constant data
    ::fprintf(fvfile, "function [0:0] Is8ByteOpcode;\n  input [7:0] opCodeParam;\n  if (");
    fFirst = true;
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        if (data.constIndex != -1)
        {
            if (!fFirst)
            {
                fprintf(fvfile, " ||\n      ");
            }

            ::fprintf(fvfile, "opCodeParam == `%s", data.opCode.c_str());

            fFirst = false;
        }
    }
    ::fprintf(fvfile, ")\n    Is8ByteOpcode = 1;\n  else\n    Is8ByteOpcode = 0;\nendfunction\n\n");

    // Verilog function to tell opCodes that read or write RAM
    ::fprintf(fvfile, "function [0:0] IsRAMOpcode;\n  input [7:0] opCodeParam;\n  if (");
    fFirst = true;
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        InstructionData& data = g_instructionData[i];

        if (data.fRAM)
        {
            if (!fFirst)
            {
                fprintf(fvfile, " ||\n      ");
            }

            ::fprintf(fvfile, "opCodeParam == `%s", data.opCode.c_str());

            fFirst = false;
        }
    }
    ::fprintf(fvfile, ")\n    IsRAMOpcode = 1;\n  else\n    IsRAMOpcode = 0;\nendfunction\n\n");

    ::fclose(fvfile);
}
