#pragma once

#include "AssemblerNode.h"
#include "InstructionData.h"
#include "PhaethonAsmLib.h"
#include <iostream>
#include <vector>

class InstructionNode : public AssemblerNode<InstructionNode>
{
public:
    static int GetCodeSize() { return s_codeSize; }

    void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3)
    {
        _args[0] = a1;
        _args[1] = a2;
        _args[2] = a3;

    	for (int i = 0; i < InstructionData::s_dataCount; i++)
    	{
    		if (InstructionData::s_data[i].instr == instr &&
    			InstructionData::s_data[i].args[0] == a1._type &&
    			InstructionData::s_data[i].args[1] == a2._type &&
    			InstructionData::s_data[i].args[2] == a3._type)
    		{
                _opCode = InstructionData::s_data[i].opCode;
                _wordArg = InstructionData::s_data[i].wordArg;
                s_codeSize += (_wordArg == -1) ? 4 : 8;

    			return;
    		}
    	}

    	std::cout << "Unknown instruction instr = " << instr << ", " << a1._type << ", " << a2._type << ", " << a3._type << std::endl;
    }

    void ResolveSymbols()
    {
        for (int i = 0; i < 3; i++)
        {
            _args[i].ResolveSymbol();
        }
    }

    void OutputInstruction()
    {
    	OutputBytes(_opCode, _args[0]._value, _args[1]._value, _args[2]._value);

    	if (_wordArg != -1)
    	{
    		OutputWord(_args[_wordArg]._value);
    	}
    }


public:
    static std::vector<std::unique_ptr<InstructionNode> > s_defs;
    static std::vector<std::unique_ptr<InstructionNode> >& GlobalList() { return s_defs; }
    static int s_codeSize;

private:
    Instructions::Enum _instr;
    OpCodes::Enum _opCode;
    Argument _args[3];
    int _wordArg;
};
