#include "stdafx.h"
#include "File.h"

void ExecuteTest(
	wchar_t* pBinFile,
	const CFile& comPort
	)
{
	// Open the file we want to send
	CFile progBin(pBinFile, OpenMode::OpenExisting);

	// Copy the filename
	wchar_t pszResult[MAX_PATH];
	::StringCchCopy(pszResult, sizeof(pszResult), pBinFile);
	::PathCchRemoveExtension(pszResult, sizeof(pszResult));
	::PathCchAddExtension(pszResult, sizeof(pszResult), L"result");

	// Open result file
	CFile resultFile(pszResult, OpenMode::CreateAlways);

	// Send dat program, start with our fancy header
	comPort.WriteDword(0x1337beef);

	// Write out the size of the program in words
	DWORD progSize = progBin.GetSize() / 4;
	comPort.WriteDword(progSize);

	// Write all of the words - program will start running once
	// all of the words are sent down.
	for (DWORD i = 0; i < progSize; i++)
	{
		comPort.WriteDword(progBin.ReadDword());
	}

	// Receive dem results
	DWORD debugCount = comPort.ReadDword();
	for (DWORD i = 0; i < debugCount; i++)
	{
		DWORD dbgWord = comPort.ReadDword();
		resultFile.WriteFormat("DebugOut %.8x\n", dbgWord);
	}
}

int wmain(int argc, wchar_t** argv)
{
	// Open the COM port to send it on
	CFile comPort(L"COM3", OpenMode::OpenExisting);
	comPort.SetDCB();

	ExecuteTest(argv[1], comPort);

    return 0;
}

