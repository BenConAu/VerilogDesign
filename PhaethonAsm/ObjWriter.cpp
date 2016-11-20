#include "ObjWriter.h"

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputWord(unsigned int w)
{
	OutputBytes(
		static_cast<unsigned char>(w & 0xFF),
		static_cast<unsigned char>(w >> 8 & 0xFF),
		static_cast<unsigned char>(w >> 16 & 0xFF),
		static_cast<unsigned char>(w >> 24 & 0xFF)
		);
}
