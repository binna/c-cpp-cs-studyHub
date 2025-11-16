#include <iostream>
#include <vector>

using namespace std;

static int board[1001];

int main(void)
{
	int a, b, result = 0;
	cin >> a >> b;

	int num = 1, repeat = 0;

	for (int i = 1; i <= 1000; i++)
	{
		if (num == repeat)
		{
			num++;
			repeat = 0;
		}

		board[i] = num;
		repeat++;
	}


	for (int i = a; i <= b; i++)
	{
		result += board[i];
	}

	cout << result;

	return 0;
}