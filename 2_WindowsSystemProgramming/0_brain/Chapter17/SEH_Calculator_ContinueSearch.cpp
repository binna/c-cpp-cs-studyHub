#include <stdio.h>
#include <tchar.h>
#include <windows.h>

enum { DIV = 1, MUL, ADD, MIN, EXIT };

int num1, num2, result;

DWORD ShowMenu(void);
BOOL Calculator(void);
DWORD FilterFuntion(DWORD exptType);

int _tmain(int argc, TCHAR* argv[])
{
	BOOL state;

	__try
	{
		do
		{
			state = Calculator();
		} while (state == TRUE);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		_tprintf(_T("End of excution!\n"));
	}

	return 0;
}

DWORD ShowMenu(void)
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

	sel = ShowMenu();
	if (sel == EXIT)
		return FALSE;

	_fputts(_T("Input Num1 Num2:"), stdout);
	_tscanf_s(_T("%d %d"), &num1, &num2);

	__try
	{
		switch (sel)
		{
		case DIV:
			result = num1 / num2;
			_tprintf(_T("%d/%d=%d\n\n"), num1, num2, result);
			break;
		case MUL:
			result = num1 * num2;
			_tprintf(_T("%d*%d=%d\n\n"), num1, num2, result);
			break;
		case ADD:
			result = num1 + num2;
			_tprintf(_T("%d+%d=%d\n\n"), num1, num2, result);
			break;
		case MIN:
			result = num1 - num2;
			_tprintf(_T("%d-%d=%d\n\n"), num1, num2, result);
			break;
		}
	}
	__except (FilterFuntion(GetExceptionCode()))
	{
		_tprintf(_T("__except block ... \n\n"));
	}

	return TRUE;
}

DWORD FilterFuntion(DWORD exptType)
{
	switch (exptType)
	{
	case EXCEPTION_ACCESS_VIOLATION:
		_tprintf(_T("Access violation\n\n"));
		return EXCEPTION_EXECUTE_HANDLER;
	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		_tprintf(_T("Wrong number inserted.\n"));
		_tprintf(_T("Input second number again : "));
		_tscanf_s(_T("%d"), &num2);
		return EXCEPTION_CONTINUE_SEARCH;
	default:
		return EXCEPTION_EXECUTE_HANDLER;
	}
}