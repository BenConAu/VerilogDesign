#include "BinObjectWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"

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
