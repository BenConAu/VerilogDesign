#pragma once

#include "ObjWriter.h"
#include <vector>

struct LabelInfo
{
  LabelInfo(const std::string &name)
  {
    _name = name;
    _location = 0;
  }

  std::string _name; // The label name
  size_t _location;  // The location for that label in the stream
};

class BinaryObjWriter : public ObjWriter
{
public:
  BinaryObjWriter(const char *pszFilename);
  ~BinaryObjWriter();

  void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
  void OutputWord(unsigned int w);

  void OutputInstruction(
      OpCodes::Enum opCode,
      ObjArgument *args) override;

  void OutputLabel(
      const char *pszLabel) override;

  void FinishCode() override;

private:
  void WriteWordToFile(unsigned int w);
  size_t EnsureLabelInfo(const std::string &label);

private:
  std::vector<unsigned int> _wordCache; // Cache of words to be output to object file
  std::vector<size_t> _memLocations;    // Index of which words have memory locations that need offsetting
  std::vector<size_t> _labelLocations;
  std::vector<LabelInfo> _labels;
  FILE *_pOutFile;
};
