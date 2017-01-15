#pragma once

#include "BinaryWriterBase.h"

class BinObjWriter : public BinaryWriterBase
{
public:
  BinObjWriter(const char *pszFilename);
  ~BinObjWriter();

  void WriteWordToFile(unsigned int w) override;

private:
  FILE *_pOutFile;
};
