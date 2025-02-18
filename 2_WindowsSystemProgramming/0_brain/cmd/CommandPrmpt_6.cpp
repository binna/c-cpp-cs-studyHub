#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>
#include <tlHelp32.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

TCHAR cmdString[STR_LEN];
PTCHAR contex = NULL;
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

int cmdReadTokenize(void);
int CmdProcessing(int);
TCHAR* StrLower(TCHAR*);
void ListProcessInfo(void);
void KillProcess(void);
void TypeTextFile(void);

int _tmain(int argc, TCHAR* argv[])
{
	// �ѱ� �Է��� �����ϰ� �ϱ� ����
	_tsetlocale(LC_ALL, _T("Korean"));

	// �Ű����� �������ڰ� �ִ� ��� ó���� ���� ���̴�
	// Start ��ɾ ���� ó��
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
			_tcscpy_s(cmdTokenList[i - 1], STR_LEN, argv[i]);
		CmdProcessing(argc - 1);
	}

	DWORD isExit = NULL;
	while (1)
	{
		int tokenNum = cmdReadTokenize();

		if (tokenNum == 0)		// Enter �Է� ó���� ���� �κ�
			continue;

		isExit = CmdProcessing(tokenNum);
		if (isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�."), stdout);
			break;
		}
	}
	return 0;
}

int cmdReadTokenize(void)
{
	TCHAR* token;

	_fputts(_T("Shine Command prompt>> "), stdout);
	_getts_s(cmdString);

	token = _tcstok_s(cmdString, seps, &contex);

	int tokenNum = 0;

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[tokenNum++], STR_LEN, StrLower(token));

		// _tcstok_s �Լ����� ù ��° �Ű������� NULL�� �����ϸ�,
		// ������ ó���ߴ� ���ڿ��� ���� ��ū�� �����Ѵ�
		token = _tcstok_s(NULL, seps, &contex);
	}

	return tokenNum;
}

int CmdProcessing(int tokenNum)
{
	BOOL isRun;
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	TCHAR cmdStringWithOptions[STR_LEN] = { 0, };
	TCHAR optString[STR_LEN] = { 0, };

	si.cb = sizeof(si);

	// _tcscmp(string1, string2)
	// < 0(����)	string1�� string2����	���� ���
	// 0		string1�� string2��		���� ���
	// > 0(���)	string1�� string2����	ū ���
	if (!_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("start")))
	{
		if (tokenNum > 1)
		{
			for (int i = 1; i < tokenNum; i++)
			{
				_stprintf_s(optString, _T("%s %s"), optString, cmdTokenList[i]);
			}
			_stprintf_s(cmdStringWithOptions, _T("%s %s"), _T("cmd.exe"), optString);
		}
		else
		{
			_stprintf_s(optString, _T("%s"), _T("cmd.exe"));
		}

		isRun = CreateProcess(
			NULL, cmdStringWithOptions, NULL, NULL,
			TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("echo")))
	{
		// �Էµ� ���ڿ��� �״�� ����ϴ� echo ��ɾ�
		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf_s(optString, _T("%s %s"), optString, cmdTokenList[i]);
		}
		_tprintf(_T("echo message: %s\n"), optString);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("lp")))
	{
		ListProcessInfo();
	}
	else if (!_tcscmp(cmdTokenList[0], _T("kp")))
	{
		if (tokenNum < 2)
		{
			_tprintf(_T("usage: Kp <Process Name>\n"));
			return 0;
		}
		KillProcess();
	}
	else if (!_tcscmp(cmdTokenList[0], _T("sort")))
	{
		if (!_tcscmp(cmdTokenList[1], _T(">")))
		{
			// ��� �����ؾ� ���� ����!

			SECURITY_ATTRIBUTES fileSec = { 0, };
			fileSec.nLength = sizeof(fileSec);
			fileSec.lpSecurityDescriptor = NULL;
			fileSec.bInheritHandle = TRUE;

			HANDLE hFile = CreateFile(
				cmdTokenList[2],
				GENERIC_WRITE,
				FILE_SHARE_READ,
				&fileSec,
				CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL);

			si.hStdOutput = hFile;
			si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
			si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
			si.dwFlags |= STARTF_USESTDHANDLES;

			isRun = CreateProcess(
				NULL,
				cmdTokenList[0],
				NULL,
				NULL,
				TRUE,
				0,
				NULL,
				NULL,
				&si,
				&pi);

			WaitForSingleObject(pi.hProcess, INFINITE);

			CloseHandle(hFile);
		}
		else
		{
			isRun = CreateProcess(
				NULL,
				cmdTokenList[0],
				NULL,
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&si,
				&pi);

			WaitForSingleObject(pi.hProcess, INFINITE);
		}

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("type")))
	{
		TypeTextFile();
	}
	else
	{
		_tcscpy_s(cmdStringWithOptions, STR_LEN, cmdTokenList[0]);

		for (int i = 1; i < tokenNum; i++)
		{
			_stprintf_s(cmdStringWithOptions, _T("%s %s"), cmdStringWithOptions, cmdTokenList[i]);
		}

		isRun = CreateProcess(
			NULL, cmdStringWithOptions, NULL, NULL,
			TRUE, 0, NULL, NULL, &si, &pi);


		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	return 0;
}

#pragma region ���ڿ� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� ����
/*
* ���ڿ� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�
* ����� ���ڿ��� �����͸� ��ȯ�Ѵ�
*/
TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr;

	while (*pStr)
	{
		if (_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}
	return ret;
}
#pragma endregion

#pragma region List Process
/*
* List Process
*/
void ListProcessInfo(void)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot error!\n"));
		return;
	}

	// ���μ��� ���� ��� ���� ����ü ����
	PROCESSENTRY32 pe32;

	// PROCESSENTRY32 ������ ����ϱ� ���� ���� �ʱ�ȭ �Ѵ�
	pe32.dwSize = sizeof(PROCESSENTRY32);

	// ù ��° ���μ��� ���� ����
	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First error!\n"));
		CloseHandle(hProcessSnap);
		return;
	}

	do
	{
		// ���μ��� �̸�, ID ���� ���
		_tprintf(_T("%25s %d\n"), pe32.szExeFile, pe32.th32ProcessID);
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
}
#pragma endregion

#pragma region Kill Process
/*
* Kill Process
*/
void KillProcess(void)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("CreateToolhelp32Snapshot(of process)"));
		return;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32))
	{
		_tprintf(_T("Process32First"));
		CloseHandle(hProcessSnap);
		return;
	}

	HANDLE hProcess;
	BOOL isKill = FALSE;
	do
	{
		// �Էµ� ���μ��� �̸��� ���Ѵ�
		// ����, ��ҹ��� ���� ���� �� �ؾ���
		// ��? ��� �빮�ڸ� �ҹ��ڷ� �ٲٱ� ����
		if (_tcsicmp(pe32.szExeFile, cmdTokenList[1]) == 0)
		{
			// ���μ��� ID�� �ڵ�� ��ȯ�ϴ� ����
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

			if (hProcess != NULL)
			{
				// ���μ����� ���� �����Ѵ�
				TerminateProcess(hProcess, -1);
				isKill = TRUE;
				CloseHandle(hProcess);
			}

			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);
	if (isKill == FALSE)
		_tprintf(_T("Kill process fail, Try again!\n"));
}
#pragma endregion

void TypeTextFile(void)
{
	TCHAR cmdStringWithOptions[STR_LEN] = { 0, };
	BOOL isRun;

	_tcscpy_s(cmdStringWithOptions, STR_LEN, cmdTokenList[0]);
	_stprintf_s(cmdStringWithOptions, STR_LEN, _T("%s %s"), cmdStringWithOptions, cmdTokenList[1]);

	if (!_tcscmp(cmdTokenList[2], _T("|")))
	{
		// Create unnamed pipe
		HANDLE hReadPipe, hWritePipe;

		SECURITY_ATTRIBUTES pipeSA = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

		CreatePipe(&hReadPipe, &hWritePipe, &pipeSA, 0);

#pragma region process type�� ���� ����
		STARTUPINFO siType = { 0, };
		PROCESS_INFORMATION piType;
		siType.cb = sizeof(siType);

		siType.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		siType.hStdError = GetStdHandle(STD_ERROR_HANDLE);
		siType.hStdOutput = hWritePipe;		// ��� �����̷���
		siType.dwFlags |= STARTF_USESTDHANDLES;

		isRun = CreateProcess(
			NULL, 
			cmdStringWithOptions,
			NULL,
			NULL,
			TRUE,
			0,
			NULL,
			NULL,
			&siType,
			&piType);

		CloseHandle(piType.hThread);
		CloseHandle(hWritePipe);
#pragma endregion

#pragma region process sort�� ���� ����(������ ���� sort ��ɾ�)
		STARTUPINFO siSort = { 0, };
		PROCESS_INFORMATION piSort;
		siSort.cb = sizeof(siSort);

		siSort.hStdInput = hReadPipe;		// �Է� �����̷���
		siSort.hStdError = GetStdHandle(STD_ERROR_HANDLE);
		siSort.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		siSort.dwFlags |= STARTF_USESTDHANDLES;
		 
		isRun = CreateProcess(
			NULL, 
			cmdTokenList[3],
			NULL,
			NULL, 
			TRUE,
			0,
			NULL,
			NULL,
			&siSort,
			&piSort);

		CloseHandle(piSort.hThread);
		CloseHandle(hReadPipe);
#pragma endregion

		WaitForSingleObject(piType.hProcess, INFINITE);
		WaitForSingleObject(piSort.hProcess, INFINITE);
		
		CloseHandle(piType.hProcess);
		CloseHandle(piSort.hProcess);
	}
	else
	{
		STARTUPINFO si = { 0, };
		PROCESS_INFORMATION pi;
		si.cb = sizeof(si);

		isRun = CreateProcess(
			NULL, 
			cmdStringWithOptions, 
			NULL, 
			NULL, 
			FALSE,
			0, 
			NULL, 
			NULL, 
			&si, 
			&pi);

		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	_tprintf(_T("\n"));
}