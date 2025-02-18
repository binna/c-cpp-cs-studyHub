#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>

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