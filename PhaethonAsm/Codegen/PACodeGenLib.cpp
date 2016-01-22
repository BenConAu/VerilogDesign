#include "PACodeGenLib.h"
#include <string>
#include <vector>

struct InstructionData
{
    int symIndex;
    int arg1;
    int arg2;
    int arg3;
};

static std::vector<std::string> g_symbols;
static std::vector<InstructionData> g_instructionData;

void StoreInstruction(int symIndex, int arg1, int arg2, int arg3)
{
    InstructionData data;
    data.symIndex = symIndex;
    data.arg1 = arg1;
    data.arg2 = arg2;
    data.arg3 = arg3;
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

void OutputInstructions()
{
    // First the enum of Instructions
    printf("namespace Instructions\n{\n    enum Enum\n    {\n");
    for (size_t i = 0; i < g_symbols.size(); i++)
    {
        printf("        %s,\n", g_symbols[i].c_str());
    }
    printf("    };\n}\n");

    // Now the collection of instruction data
    for (size_t i = 0; i < g_instructionData.size(); i++)
    {
        printf("    %s, { %d, %d, %d }, %d\n", g_symbols[g_instructionData[i].symIndex].c_str(), 1, 2, 3, 4);
    }
}
