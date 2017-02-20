#include "stdafx.h"

class CFile
{
public:
	CFile(const wchar_t* pszName)
	{
		_hFile = ::CreateFile(
			pszName,
			GENERIC_READ | GENERIC_WRITE,
			0,
			0,
			OPEN_EXISTING,
			0,
			nullptr);

		if (_hFile == INVALID_HANDLE_VALUE)
		{
			throw _hFile;
		}
	}

	~CFile()
	{
		::CloseHandle(_hFile);
	}

	void SetDCB()
	{
		DCB dcb;
		::ZeroMemory(&dcb, sizeof(dcb));

		if (!::GetCommState(_hFile, &dcb))
		{
			throw "GetCommState failed";
		}

		dcb.DCBlength = sizeof(dcb);
		dcb.BaudRate = CBR_115200;
		dcb.ByteSize = 8;
		dcb.fBinary = TRUE;

		if (!::SetCommState(_hFile, &dcb))
		{
			throw "SetCommState failed";
		}
	}

	void WriteDword(DWORD dwValue)
	{
		DWORD written = 0;
		::WriteFile(_hFile, &dwValue, sizeof(dwValue), &written, nullptr);
	}

	DWORD ReadDword()
	{
		DWORD dwValue;
		DWORD read = 0;
		::ReadFile(_hFile, &dwValue, sizeof(dwValue), &read, nullptr);
		return dwValue;
	}

	BYTE ReadByte()
	{
		BYTE val;
		DWORD read = 0;
		::ReadFile(_hFile, &val, sizeof(val), &read, nullptr);
		return val;
	}

	DWORD GetSize()
	{
		return ::GetFileSize(_hFile, nullptr);
	}

private:
	HANDLE _hFile;
};

int main()
{
	// Open the file we want to send
	CFile progBin(L"..\\Firmware\\TinyProgram.bin");

	// Open the COM port to send it on
	CFile comPort(L"COM3");
	comPort.SetDCB();

	// Send dat program, start with our fancy header
	comPort.WriteDword(0x1337beef);

	// Write out the size of the program in words
	DWORD progSize = progBin.GetSize() / 4;
	comPort.WriteDword(progSize);

	// Write all of the words
	for (DWORD i = 0; i < progSize; i++)
	{
		comPort.WriteDword(progBin.ReadDword());
	}

	// Receive dem results
	DWORD debugCount = comPort.ReadDword();
	for (DWORD i = 0; i < debugCount; i++)
	{
		DWORD dbgWord = comPort.ReadDword();
		printf("%x\n", dbgWord);
	}

    return 0;
}

