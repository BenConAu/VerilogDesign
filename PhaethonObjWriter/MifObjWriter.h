#pragma once

#include "BinaryWriterBase.h"

class MifObjWriter : public BinaryWriterBase
{
public:
  MifObjWriter(const char *pszFilename);
  ~MifObjWriter();

  void WriteHeader(unsigned int numWords) override;
  void WriteFooter() override;
  void WriteWordToFile(unsigned int w) override;

private:
  FILE *_pOutFile;
  unsigned int _pos;
};
