#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define WORK_MAX		10000
#define THREAD_MAX		50

typedef void (*WORK) (void);

typedef struct __WorkerThread
{
	HANDLE hThread;
	DWORD idThread;
}WorkerThread;

DWORD AddWorkToPool(WORK work);				// ���ο� Work�� ����� �� ȣ���ϴ� �Լ�
WORK GetWorkFromPool(void);					// ������ Ǯ���� Work�� ������ �� ȣ���ϴ� �Լ�
DWORD MakeThreadToPool(DWORD numOfThread);	// ������ Ǯ�� ������ ���Ŀ� Ǯ�� ������ �����ϴ� �Լ� 
											// ���ڷ� ���޵Ǵ� ����ŭ �����尡 ����
void WorkerThreadFunction(LPVOID pParam);	// �����尡 �������ڸ��� ȣ��Ǵ� �������� main �Լ�

// Work�� Thread ������ ���� ����ü
struct __ThreadPool
{
	// Work�� ����ϱ� ���� �迭
	WORK workList[WORK_MAX];

	// Thread ������ �� Thread�� Event ������Ʈ
	WorkerThread workerThreadList[THREAD_MAX];
	HANDLE workerEventList[THREAD_MAX];

	// Work�� ���� ����
	DWORD idxOfCurrentWork;		// ��� 1����	Work Index
	DWORD idxOfLastAddedWork;	// ������ �߰�	Work Index + 1

	// Number of Thread
	DWORD threadIdx;			// Pool�� �����ϴ� Thread�� ����
}gThreadPool;

#pragma region Mutex ���� �Լ���
/*
* Mutex ���� �Լ���
* gThreadPool�� ���� ������ ��ȣ�ϱ� ���� ����
* ���ؽ� ��� ����ȭ �Լ����� ����(Rapping) �� ��
*/
static HANDLE mutex = NULL;

void InitMutex(void)
{
	mutex = CreateMutex(NULL, FALSE, NULL);
}

void DeInitMutex(void)
{
	BOOL ret = CloseHandle(mutex);
}

void AcquireMutex(void)
{
	DWORD ret = WaitForSingleObject(mutex, INFINITE);

	if (ret == WAIT_FAILED)
		_tprintf(_T("Error Occur!\n"));
}

void ReleaseMutex(void)
{
	BOOL ret = ReleaseMutex(mutex);

	if (ret == 0)
		_tprintf(_T("Error Occur!\n"));
}
#pragma endregion

#pragma region Thread Pool�� Work�� ��Ͻ�Ű�� ���� �Լ�
/*
* Thread Pool�� Work�� ��Ͻ�Ű�� ���� �Լ�
*/
DWORD AddWorkToPool(WORK work)
{
	AcquireMutex();
	if (gThreadPool.idxOfLastAddedWork >= WORK_MAX)
	{
		_tprintf(_T("AddWorkToPool fail!\n"));
		return NULL;
	}

	// Work ���
	gThreadPool.workList[gThreadPool.idxOfLastAddedWork++] = work;

	// Work ��� ��, ������� ��������� ��� ���� ���� �����ϵ��� ��
	// ��� ���� �ʿ䰡 �����Ƿ� �������� �������� �κ���
	for (DWORD i = 0; i < gThreadPool.threadIdx; i++)
	{
		SetEvent(gThreadPool.workerEventList[i]);
	}

	ReleaseMutex();
	return 1;
}
#pragma endregion

#pragma region Thread���� Work�� ������ �� ȣ��Ǵ� �Լ�
/*
* Thread���� Work�� ������ �� ȣ��Ǵ� �Լ�
* gThreadPool�� ���� ������ ��ȣ�ϱ� ���� ����
*/
WORK GetWorkFromPool(void)
{
	WORK work = NULL;

	AcquireMutex();

	// ���� ó���ؾ� �� Work�� �������� �ʴ´ٸ�
	if (!(gThreadPool.idxOfCurrentWork < gThreadPool.idxOfLastAddedWork))
	{
		ReleaseMutex();
		return NULL;
	}

	work = gThreadPool.workList[gThreadPool.idxOfCurrentWork++];
	ReleaseMutex();

	return work;
}
#pragma endregion

#pragma region Thread Pool ����
/*
* Thread Pool ����
* ���޵Ǵ� ���ڰ��� ���� Thread ����
*/
DWORD MakeThreadToPool(DWORD numOfThread)
{
	InitMutex();
	DWORD capacity = WORK_MAX - (gThreadPool.threadIdx);

	if (capacity < numOfThread)
		numOfThread = capacity;

	for (DWORD i = 0; i < numOfThread; i++)
	{
		DWORD idThread;
		HANDLE hThread;

		gThreadPool.workerEventList[gThreadPool.threadIdx] = CreateEvent(
			NULL, 
			FALSE,
			FALSE,
			NULL);

		hThread = CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)WorkerThreadFunction, 
			(LPVOID)gThreadPool.threadIdx,
			0,
			&idThread);

		gThreadPool.workerThreadList[gThreadPool.threadIdx].hThread = hThread;
		gThreadPool.workerThreadList[gThreadPool.threadIdx].idThread = idThread;
	}

	return numOfThread;		// ������ �������� ���� ��ȯ�Ѵ�
}
#pragma endregion

void WorkerThreadFunction(LPVOID pParam)
{
	WORK workFunction;
	HANDLE event = gThreadPool.workerEventList[(DWORD)pParam];

	while (1)
	{
		workFunction = GetWorkFromPool();
		if (workFunction == NULL)
		{
			// Work�� �Ҵ�� ������ Blocked ���¿� �ְ� �ȴ�
			WaitForSingleObject(event, INFINITE);
			continue;
		}
		workFunction();
	}
}

void TestFunction()
{
	static int i = 0;
	i++; 

	_tprintf(
		_T("Good Test --%d : Processing thread : %d--\n\n"), 
		i, 
		GetCurrentThreadId());
}

int _tmain(int argc, TCHAR* argv[])
{
	MakeThreadToPool(3);

	// �ټ��� work ���
	for (int i = 0; i < 100; i++)
	{
		AddWorkToPool(TestFunction);
	}

	Sleep(50000);
	return 0;
}