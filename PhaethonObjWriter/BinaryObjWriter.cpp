#include "BinaryObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"

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

    int wordArg = OpCodeData::s_data[opCode - 1].wordArg;
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

void BinaryObjWriter::OutputLabel(const char* pszLabel)
{
}