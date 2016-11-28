#include "BinaryObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"

BinaryObjWriter::BinaryObjWriter(const char *pszFilename)
{
    _pOutFile = ::fopen(pszFilename, "w");
}

BinaryObjWriter::~BinaryObjWriter()
{
    for (size_t i = 0; i < _wordCache.size(); i++)
    {
        WriteWordToFile(_wordCache[i]);
    }

    ::fprintf(_pOutFile, "@7ff\n");
    ::fclose(_pOutFile);
}

void BinaryObjWriter::WriteWordToFile(unsigned int w)
{
    fprintf(
        _pOutFile,
        "%02x %02x %02x %02x\n",
        static_cast<unsigned char>(w & 0xFF),
        static_cast<unsigned char>(w >> 8 & 0xFF),
        static_cast<unsigned char>(w >> 16 & 0xFF),
        static_cast<unsigned char>(w >> 24 & 0xFF));
}

void BinaryObjWriter::OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
    OutputWord(
        ((unsigned int)b1) |
        ((unsigned int)b2 << 8) |
        ((unsigned int)b3 << 16) |
        ((unsigned int)b4 << 24));
}

void BinaryObjWriter::OutputWord(unsigned int w)
{
    _wordCache.push_back(w);
}

void BinaryObjWriter::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args)
{
    OutputBytes(opCode, args[0]._value, args[1]._value, args[2]._value);

    int wordArg = OpCodeData::s_data[opCode - 1].wordArg;
    if (wordArg != -1)
    {
        if (args[wordArg]._offset == -1)
        {
            //printf("Output word %d\n", _args[_wordArg]._value);
            OutputWord(args[wordArg]._value);

            if (args[wordArg]._fMemoryLocation)
            {
                // The index of the last word is a memory location
                _memLocations.push_back(_wordCache.size() - 1);
            }
        }
        else
        {
            //printf("Output word %d\n", _args[_wordArg]._offset);
            OutputWord(args[wordArg]._offset);
        }
    }
}

void BinaryObjWriter::OutputLabel(const char *pszLabel)
{
}

void BinaryObjWriter::FinishCode()
{
    // All of the following words are going to be memory so we know
    // where memory starts now.
    unsigned int memStart = _wordCache.size() * 4;

    // All of the memory locations can be updated now
    for (size_t i = 0; i < _memLocations.size(); i++)
    {
        _wordCache[_memLocations[i]] += memStart;
    }
}