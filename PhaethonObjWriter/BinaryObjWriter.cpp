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
