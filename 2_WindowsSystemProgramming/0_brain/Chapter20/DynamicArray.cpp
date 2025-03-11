#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#define MAX_PAGE				10		// �Ҵ��� �ִ� ������ ����

int* nextPageAddr;
DWORD pageCnt = 0;
DWORD pageSize;

int PageFaultExceptionFilter(DWORD);

int _tmain(int argc, TCHAR* argv[])
{
	LPVOID baseAddr;
	int* lpPtr;
	SYSTEM_INFO sSysInfo;

	GetSystemInfo(&sSysInfo);
	pageSize = sSysInfo.dwPageSize;		// ������ ������ ȹ��

	// MAX_PAGE�� ������ŭ ������ RESERVE
	baseAddr = VirtualAlloc(
		NULL,							// ���� �ּ� �Ҵ�
		MAX_PAGE * pageSize,			// ���� �޸� ũ��
		MEM_RESERVE,					// reserve
		PAGE_READWRITE);					// no Access
	
	if (baseAddr == NULL)
	{
		_tprintf(_T("VirtualAlloc reserve failed"));
	}

	lpPtr = (int*)baseAddr;		// �迭�� ���� ������ ���� �ǹ� �ο�
	nextPageAddr = (int*)baseAddr;

	// page fault �߻� �� ���� �߻�
	for (DWORD i = 0; i < (MAX_PAGE * pageSize) / sizeof(DWORD); i++)
	{
		__try
		{
			lpPtr[i] = i;
		}
		__except (PageFaultExceptionFilter(GetExceptionCode()))
		{
			ExitProcess(GetLastError());		// ����ó�� ���� �߻� �� ����
		}
	}

	BOOL isSuccess = VirtualFree(baseAddr, 0, MEM_RESERVE);

	if (isSuccess)
		_tprintf(_T("Release successed!"));
	else
		_tprintf(_T("Release failed!"));
}



int PageFaultExceptionFilter(DWORD exptCode)
{
	if (exptCode != EXCEPTION_ACCESS_VIOLATION)
	{
		_tprintf(_T("Exception code = %d\n"), exptCode);
		return EXCEPTION_EXECUTE_HANDLER;
	}

	_tprintf(_T("Excption is a page fault\n"));

	if (pageCnt >= MAX_PAGE)
	{
		_tprintf(_T("Excption: out of pages\n"));
		return EXCEPTION_EXECUTE_HANDLER;
	}

	LPVOID lpvResult = VirtualAlloc(
		(LPVOID)nextPageAddr,
		pageSize,
		MEM_COMMIT,
		PAGE_READWRITE);

	if (lpvResult == NULL)
	{
		_tprintf(_T("VirtualAlloc failed\n"));
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else
	{
		_tprintf(_T("Allocating another page.\n"));
	}

	pageCnt++;
	nextPageAddr += pageSize / sizeof(int);
	return EXCEPTION_CONTINUE_EXECUTION;
}