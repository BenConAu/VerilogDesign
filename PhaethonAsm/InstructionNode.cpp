#include "InstructionNode.h"

int InstructionNode::s_codeSize = 0;

void InstructionNode::StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3)
{
    _args[0] = a1;
    _args[1] = a2;
    _args[2] = a3;

    //std::cout << "Lookup instr = " << instr << ", " << a1._argType.GetShortTypeText() << ", " << a2._argType.GetShortTypeText() << ", " << a3._argType.GetShortTypeText() << std::endl;
    //std::cout << "       value = " << instr << ", " << a1._value << ", " << a2._value << ", " << a3._value << std::endl;

    // Search for the opcode that has the arguments with the given instruction
    for (int i = 0; i < OpCodeData::s_dataCount; i++)
    {
        if (OpCodeData::s_data[i].instr == instr &&
            OpCodeData::s_data[i].argTypes[0] == a1._objArg._argType &&
            OpCodeData::s_data[i].argTypes[1] == a2._objArg._argType &&
            OpCodeData::s_data[i].argTypes[2] == a3._objArg._argType)
        {
            _opCode = OpCodeData::s_data[i].opCode;

            s_codeSize += (OpCodeData::s_data[i].wordArg == -1) ? 4 : 8;

            return;
        }
    }

    std::cout
        << "Unknown instruction instr = "
        << instr << ", "
        << OperandTypeHelper::GetShortTypeText(a1._objArg._argType) << ", "
        << OperandTypeHelper::GetShortTypeText(a2._objArg._argType) << ", "
        << OperandTypeHelper::GetShortTypeText(a3._objArg._argType) << std::endl;
}

void InstructionNode::ResolveSymbols()
{
    for (int i = 0; i < 3; i++)
    {
        _args[i].ResolveSymbol();
    }
}

void InstructionNode::OutputInstruction()
{
    ObjArgument objArgs[3];
    for (int i = 0; i < 3; i++)
    {
        objArgs[i] = _args[i]._objArg;
    }

    s_pWriter->OutputInstruction(
        _opCode,
        objArgs
        );
}
