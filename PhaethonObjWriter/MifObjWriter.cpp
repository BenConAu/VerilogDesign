#include "MifObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"

MifObjWriter::MifObjWriter(const char *pszFilename)
{
    _pOutFile = ::fopen(pszFilename, "w");    
}

MifObjWriter::~MifObjWriter()
{
    ::fclose(_pOutFile);
}

void MifObjWriter::WriteWordToFile(unsigned int w)
{
    ::fprintf(_pOutFile, "%.8x : %.8x;\n", _pos, w);
	_pos++;
}

void MifObjWriter::WriteHeader(unsigned int fileLength)
{
	fprintf(_pOutFile, "DEPTH = %d;\n", (int)fileLength);
	fprintf(_pOutFile, "WIDTH = 32;\n");
	fprintf(_pOutFile, "ADDRESS_RADIX = HEX;\n");
	fprintf(_pOutFile, "DATA_RADIX = HEX;\n");
	fprintf(_pOutFile, "CONTENT\n");
	fprintf(_pOutFile, "BEGIN\n");

	_pos = 0;
}

void MifObjWriter::WriteFooter()
{
	fprintf(_pOutFile, "END;\n");	
}