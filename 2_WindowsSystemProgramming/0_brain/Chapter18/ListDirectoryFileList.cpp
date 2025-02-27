#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR DirSpec[MAX_PATH];

	_tprintf(_T("Insert target directory: "));
	_tscanf_s(_T("%s"), DirSpec, MAX_PATH);
	_tcsncat_s(DirSpec, _T("\\*"), 3);

	hFind = FindFirstFile(DirSpec, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("Invalid file handle\n"));
		return -1;
	}
	else
	{
		_tprintf(_T("First file name is %s\n"), FindFileData.cFileName);
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			_tprintf(_T("Next file name is %s\n"), FindFileData.cFileName);
		}
		FindClose(hFind);
	}
	return 0;
}