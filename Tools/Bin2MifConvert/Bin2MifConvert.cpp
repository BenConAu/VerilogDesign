#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	FILE* pInFile = ::fopen(argv[1], "rb");    
	FILE* pOutFile = ::fopen(argv[2], "w");
	unsigned int pos = 0;

	size_t start = ftell(pInFile);
    fseek(pInFile, 0L, SEEK_END);

    size_t fileLength = ftell(pInFile);
    fseek(pInFile, start, SEEK_SET);

	fileLength -= start;
	fileLength /= 4;

	fprintf(pOutFile, "DEPTH = %d;\n", (int)fileLength);
	fprintf(pOutFile, "WIDTH = 32;\n");
	fprintf(pOutFile, "ADDRESS_RADIX = HEX;\n");
	fprintf(pOutFile, "DATA_RADIX = HEX;\n");
	fprintf(pOutFile, "CONTENT\n");
	fprintf(pOutFile, "BEGIN\n");

	for (;;)
	{
		unsigned int dword;
		size_t read = ::fread(&dword, 4, 1, pInFile);

		if (read != 1)
		{
			printf("End of file reached because %d elements read\n", (int)read);
			break;
		}

		// Swap from big to little endian
		unsigned int reordered = 0;
		reordered |= ((dword >> 24) & 0xFF);
		reordered |= (((dword >> 16) & 0xFF) << 8);
		reordered |= (((dword >> 8) & 0xFF) << 16);
		reordered |= ((dword & 0xFF) << 24);

		::fprintf(pOutFile, "%.8x : %.8x;\n", pos, reordered);

		pos++;
	}

	fprintf(pOutFile, "END;\n");

	::fclose(pInFile);
	::fclose(pOutFile);

	return 0;
}