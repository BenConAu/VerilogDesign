#include "BinaryObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"

BinaryObjWriter::BinaryObjWriter(const char *pszFilename)
{
    _pOutFile = ::fopen(pszFilename, "w");    
}

BinaryObjWriter::~BinaryObjWriter()
{
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

BinObjWriter::BinObjWriter(const char *pszFilename)
{
    _pOutFile = ::fopen(pszFilename, "wb");    
}

BinObjWriter::~BinObjWriter()
{
    ::fclose(_pOutFile);
}

void BinObjWriter::WriteWordToFile(unsigned int w)
{
    ::fwrite(&w, 1, sizeof(w), _pOutFile);
}

void BinaryWriterBase::OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
    OutputWord(
        ((unsigned int)b1) |
        ((unsigned int)b2 << 8) |
        ((unsigned int)b3 << 16) |
        ((unsigned int)b4 << 24));
}

void BinaryWriterBase::OutputWord(unsigned int w)
{
    _wordCache.push_back(w);
}

void BinaryWriterBase::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args)
{
    OutputBytes(opCode, args[0]._value, args[1]._value, args[2]._value);

    int wordArg = OpCodeData::s_data[opCode - 1].wordArg;
    if (wordArg != -1)
    {
        // See if we have a label, because if so, we need to store the index
        // to the label info so we can replace it later.
        if (OpCodeData::s_data[opCode - 1].argTypes[wordArg] == OperandType::Constant && args[wordArg]._label.length() != 0)
        {
            args[wordArg]._value = EnsureLabelInfo(args[wordArg]._label);

            //printf("Ensuring label info to store index %d and location %d\n", (int)args[wordArg]._value, (int)_wordCache.size());

            // The index of the word we will write needs updating later
            _labelLocations.push_back(_wordCache.size());
        }

        if (args[wordArg]._offset == -1)
        {
            //printf("Output word %d\n", _args[_wordArg]._value);
            OutputWord(args[wordArg]._value);

            if (args[wordArg]._fMemoryLocation)
            {
                //printf("Adding a memory location\n");

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

size_t BinaryWriterBase::EnsureLabelInfo(const std::string &label)
{
    for (size_t i = 0; i < _labels.size(); i++)
    {
        if (_labels[i]._name == label)
        {
            return i;
        }
    }

    _labels.emplace_back(label);
    return (_labels.size() - 1);
}

void BinaryWriterBase::OutputLabel(const char *pszLabel)
{
    size_t index = EnsureLabelInfo(pszLabel);

    //printf("Outputting label with index %d and location %d\n", (int)index, (int)(_wordCache.size()*4));

    // Update label info with the address that it has
    _labels[index]._location = _wordCache.size() * 4;
}

void BinaryWriterBase::FinishCode()
{
    // All of the following words are going to be memory so we know
    // where memory starts now.
    unsigned int memStart = _wordCache.size() * 4;

    // All of the memory locations can be updated now
    for (size_t i = 0; i < _memLocations.size(); i++)
    {
        _wordCache[_memLocations[i]] += memStart;
    }

    for (size_t i = 0; i < _labelLocations.size(); i++)
    {
        // The location of the word in the cache that needs updating
        size_t labelLoc = _labelLocations[i];

        // We wrote the index of the label info into that spot
        size_t index = _wordCache[labelLoc];

        //printf("Finish stage with label, location %d, index %d, final location %d\n", (int)labelLoc, (int)index, (int)_labels[index]._location);

        // Change it to the real location
        _wordCache[labelLoc] = _labels[index]._location;
    }

    for (size_t i = 0; i < _wordCache.size(); i++)
    {
        WriteWordToFile(_wordCache[i]);
    }    
}