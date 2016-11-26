#include "ObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"
#include <stdio.h>
#include <sstream>

void BinaryObjWriter::OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
    printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void BinaryObjWriter::OutputWord(unsigned int w)
{
    OutputBytes(
        static_cast<unsigned char>(w & 0xFF),
        static_cast<unsigned char>(w >> 8 & 0xFF),
        static_cast<unsigned char>(w >> 16 & 0xFF),
        static_cast<unsigned char>(w >> 24 & 0xFF));
}

void BinaryObjWriter::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args
    )
{
    OutputBytes(opCode, args[0]._value, args[1]._value, args[2]._value);

    int wordArg = InstructionData::s_data[opCode - 1].wordArg;
    if (wordArg != -1)
    {
        if (args[wordArg]._offset == -1)
        {
            //printf("Output word %d\n", _args[_wordArg]._value);
            OutputWord(args[wordArg]._value);
        }
        else
        {
            //printf("Output word %d\n", _args[_wordArg]._offset);
            OutputWord(args[wordArg]._offset);
        }
    }
}

std::string AsmObjWriter::GetOpString(const ObjArgument &objArg) const
{
    std::stringstream result;

    switch (objArg._argType)
    {
    case OperandType::Constant:
        // PASM just uses the constant simply
        result << objArg._value;
        break;

    case OperandType::Register:
        // Return the register syntax
        result << "r" << objArg._value;
        break;

    case OperandType::DerefConstant:
        // The assembler uses C-like syntax for getting addresses of things
        result << "&" << objArg._memberName;
        break;

    case OperandType::DerefRegisterOffset:
        // C++ syntax for members of things
        result << "r" << objArg._value << "->" << objArg._typeName << "::" << objArg._memberName;
        break;

    default:
        throw "Unknown result type";
    }

    return result.str();
}

void AsmObjWriter::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args
    )
{
    for (int i = 0; i < InstructionData::s_dataCount; i++)
    {
        if (InstructionData::s_data[i].opCode == opCode)
        {
            // Subtract 1 to account for Unknown
            int index = InstructionData::s_data[i].instr - 1;

            printf(
                "%s %s, %s\n",
                InstructionDataReal::s_data[index].pszName,
                GetOpString(args[0]).c_str(),
                GetOpString(args[1]).c_str()
                );
            
            return;
        }
    }

    throw "Unknown instruction";
}
