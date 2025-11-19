#include <iostream>

using namespace std;

static int board[5][5];
static int row[5] = { 0, };
static int col[5] = { 0, };
static int diagonal[2] = { 0, };

int main(void)
{
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int n = 0; n < 25; n++)
	{
		bool isRun = true;
		int temp;
		cin >> temp;

		for (int i = 0; i < 5 && isRun; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] == temp)
				{
					row[i]++;
					col[j]++;

					if (i == j)
					{
						diagonal[0]++;

						if (diagonal[0] == 5)
							result++;
					}

					if (i + j == 4)
					{
						diagonal[1]++;

						if (diagonal[1] == 5)
							result++;
					}

					if (row[i] == 5)
						result++;

					if (col[j] == 5)
						result++;

					if (result >= 3)
					{
						cout << n + 1 << endl;
						return 0;
					}

					isRun = false;
					break;
				}
			}
		}
	}

	return 0;
}