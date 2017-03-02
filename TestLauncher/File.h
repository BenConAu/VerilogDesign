#include <vector>

enum class OpenMode
{
	CreateAlways,
	OpenExisting
};

class CFile
{
public:
	CFile(const wchar_t* pszName, OpenMode mode)
	{
		_hFile = ::CreateFile(
			pszName,
			GENERIC_READ | GENERIC_WRITE,
			0,
			0,
			mode == OpenMode::OpenExisting ? OPEN_EXISTING : CREATE_ALWAYS,
			0,
			nullptr);

		if (_hFile == INVALID_HANDLE_VALUE)
		{
			throw _hFile;
		}

		_fComPort = false;
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

		_fComPort = true;
	}

	void WriteDword(DWORD dwValue) const
	{
		DWORD written = 0;
		::WriteFile(_hFile, &dwValue, sizeof(dwValue), &written, nullptr);
		if (written != sizeof(dwValue))
		{
			throw "Write error";
		}
	}

	DWORD ReadDword()
	{
		DWORD dwValue;
		DWORD read = 0;
		::ReadFile(_hFile, &dwValue, sizeof(dwValue), &read, nullptr);
		if (read != sizeof(dwValue))
		{
			throw "Read error";
		}

		if (_fComPort)
		{
			_readWords.push_back(dwValue);
		}

		return dwValue;
	}

	BYTE ReadByte() const
	{
		BYTE val;
		DWORD read = 0;
		::ReadFile(_hFile, &val, sizeof(val), &read, nullptr);
		return val;
	}

	DWORD GetSize() const
	{
		return ::GetFileSize(_hFile, nullptr);
	}

	void WriteFormat(char* pszFormat, ...)
	{
		va_list arglist;
		va_start(arglist, pszFormat);

		char formatTarget[128];
		::vsprintf_s(formatTarget, sizeof(formatTarget), pszFormat, arglist);

		va_end(arglist);

		DWORD read = 0;
		::WriteFile(_hFile, formatTarget, static_cast<DWORD>(::strlen(formatTarget)), &read, nullptr);
	}

private:
	HANDLE _hFile;
	bool _fComPort;
	std::vector<DWORD> _readWords;
};
