#pragma once

#include "BinaryWriterBase.h"

class BinaryObjWriter : public BinaryWriterBase
{
public:
  BinaryObjWriter(const char *pszFilename);
  ~BinaryObjWriter();

  void WriteWordToFile(unsigned int w) override;

private:
  FILE *_pOutFile;
};
