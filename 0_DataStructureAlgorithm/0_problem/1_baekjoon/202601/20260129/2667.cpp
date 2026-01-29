#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> board;
static vector<int> result;

static int n;
static int houseNum;

void DFS(int x, int y, int houseNum)
{
	if (board[y][x] != -1)
		return;

	board[y][x] = houseNum;
	result[houseNum]++;
	
	if (x + 1 < n)
		DFS(x + 1, y, houseNum);

	if (x - 1 >= 0)
		DFS(x - 1, y, houseNum);

	if (y + 1 < n)
		DFS(x, y + 1, houseNum);

	if (y - 1 >= 0)
		DFS(x, y - 1, houseNum);
}

int main(void)
{
	
	cin >> n;

	board.assign(n, vector<int>(n));

	houseNum = 0;
	result.push_back(0);

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < n; j++) 
		{
			if (temp[j] == '1')
			{
				board[i][j] = -1;
				continue;
			}

			board[i][j] = 0;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			DFS(x, y, houseNum);

			if (result[houseNum] > 0)
			{
				houseNum++;
				result.push_back(0);
			}
		}
	}

	cout << houseNum << "\n";

	sort(result.begin(), result.end());

	for (int i = 1; i < houseNum + 1; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}