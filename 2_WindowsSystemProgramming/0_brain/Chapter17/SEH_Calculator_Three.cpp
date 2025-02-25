#include <stdio.h>
#include <tchar.h>
#include <windows.h>

enum { DIV = 1, MUL, ADD, MIN, ELSE, EXIT };

DWORD ShowMenu(void);
BOOL Calculator(void);

void Divide(int, int);
void Multiple(int, int);
void Add(int, int);
void Min(int, int);

int _tmain(int argc, TCHAR* argv[])
{
	BOOL state;

	do
	{
		state = Calculator();
	} while (state == TRUE);

	return 0;
}

DWORD ShowMenu()
{
	DWORD sel;

	_fputts(_T("-----Menu-----\n"), stdout);
	_fputts(_T("num1 : Divide\n"), stdout);
	_fputts(_T("num2 : Multiple\n"), stdout);
	_fputts(_T("num3 : Add\n"), stdout);
	_fputts(_T("num4 : Minus\n"), stdout);
	_fputts(_T("num5 : Any other operations.\n"), stdout);
	_fputts(_T("num6 : exit\n"), stdout);
	_fputts(_T("SELECTION >>"), stdout);
	_tscanf_s(_T("%d"), &sel);

	return sel;
}

BOOL Calculator(void)
{
	DWORD sel;
	int num1, num2, result;

	sel = ShowMenu();
	if (sel == EXIT)
		return FALSE;

	_fputts(_T("Input Num1 Num2:"), stdout);
	_tscanf_s(_T("%d %d"), &num1, &num2);

	__try
	{
		__try
		{
			switch (sel)
			{
			case DIV:
				Divide(num1, num2);
				break;
			case MUL:
				Multiple(num1, num2);
				break;
			case ADD:
				Add(num1, num2);
				break;
			case MIN:
				Min(num1, num2);
				break;
			}
		}
		__finally
		{
			_tprintf(_T("End operation\n\n"));
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		_tprintf(_T("Wrong number inserted. Try again!\n\n"));
	}

	return TRUE;
}

void Divide(int a, int b)
{
	_tprintf(_T("%d/%d=%d\n\n"), a, b, a / b);
}

void Multiple(int a, int b)
{
	_tprintf(_T("%d*%d=%d\n\n"), a, b, a * b);
}

void Add(int a, int b)
{
	_tprintf(_T("%d+%d=%d\n\n"), a, b, a + b);
}

void Min(int a, int b)
{
	_tprintf(_T("%d-%d=%d\n\n"), a, b, a - b);
}