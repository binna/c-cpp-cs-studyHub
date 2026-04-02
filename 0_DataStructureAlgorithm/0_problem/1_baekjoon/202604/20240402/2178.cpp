#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int x;
	int y;
	int move;
};

int main(void)
{
	int n, m;
	string temp;

	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = temp[j] - '0';
		}
	}

	queue<Edge> q;

	q.push({ 0, 0, 1 });
	board[0][0] = 0;

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;

		cout << x << "," << y << endl;

		if (x == m - 1 && y == n - 1)
		{
			cout << node.move << endl;
			return 0;
		}

		if (x + 1 < m && board[y][x + 1] == 1)
		{
			q.push({ x + 1, y, node.move + 1 });
			board[y][x + 1] = 0;
		}
			
		if (x - 1 >= 0 && board[y][x - 1] == 1)
		{
			q.push({ x - 1, y, node.move + 1 });
			board[y][x - 1] = 0;
		}

		if (y + 1 < n && board[y + 1][x] == 1)
		{
			q.push({ x, y + 1, node.move + 1 });
			board[y + 1][x] = 0;
		}

		if (y - 1 >= 0 && board[y - 1][x] == 1)
		{
			q.push({ x, y - 1, node.move + 1 });
			board[y - 1][x] = 0;
		}
	}

	return 0;
}