#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>

#define STR_LEN			256
#define CMD_TOKEN_NUM	10

TCHAR ERROR_CMD[] = _T("'%s'������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

int CmdPocessing(void);
TCHAR* StrLower(TCHAR*);

int _tmain(int argc, TCHAR* argv[])
{
	// �ѱ� �Է��� �����ϰ� �ϱ� ����
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdPocessing();
		if (isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�."), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
PTCHAR contex = NULL;
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/*
* ��ɾ �Է� �޾Ƽ� �ش� ��ɾ �����Ǿ� �ִ� ����� �����Ѵ�
* exit�� �ԷµǸ� TRUE�� ��ȯ�ϰ� �̴� ���α׷� ����� �̾�����
*/
int CmdPocessing(void)
{
	_fputts(_T("Shine Command prompt>> "), stdout);
	_getts_s(cmdString, STR_LEN);

	TCHAR* token = _tcstok_s(cmdString, seps, &contex);
	int tokenNum = 0;

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[tokenNum++], STR_LEN, StrLower(token));

		// _tcstok_s �Լ����� ù ��° �Ű������� NULL�� �����ϸ�,
		// ������ ó���ߴ� ���ڿ��� ���� ��ū�� �����Ѵ�
		token = _tcstok_s(NULL, seps, &contex);
	}

	// _tcscmp(string1, string2)
	// < 0(����)	string1�� string2����	���� ���
	// 0		string1�� string2��		���� ���
	// > 0(���)	string1�� string2����	ū ���
	if (!_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 1")))
	{
	}
	else if (!_tcscmp(cmdTokenList[0], _T("�߰� �Ǵ� ��ɾ� 2")))
	{
	}
	else
	{
		STARTUPINFO si = { 0, };
		PROCESS_INFORMATION pi;

		BOOL isRun = CreateProcess(
			NULL, cmdTokenList[0], NULL, NULL,
			TRUE, 0, NULL, NULL, &si, &pi);

		if (isRun == FALSE)
			_tprintf(ERROR_CMD, cmdTokenList[0]);

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