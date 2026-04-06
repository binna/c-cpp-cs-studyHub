#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = temp[j] - '0';
		}
	}

	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int x = node.first;
		int y = node.second;

		if (x == m - 1 && y == n - 1)
		{
			cout << visited[y][x];
			break;
		}

		if (x + 1 < m && visited[y][x + 1] == 0 && board[y][x + 1] == 1)
		{
			q.push({ x + 1, y });
			visited[y][x + 1] = visited[y][x] + 1;
		}

		if (x - 1 >= 0 && visited[y][x - 1] == 0 && board[y][x - 1] == 1)
		{
			q.push({ x - 1, y });
			visited[y][x - 1] = visited[y][x] + 1;
		}

		if (y + 1 < n && visited[y + 1][x] == 0 && board[y + 1][x] == 1)
		{ 
			q.push({ x, y + 1 });
			visited[y + 1][x] = visited[y][x] + 1;
		}
		
		if (y - 1 >= 0 && visited[y - 1][x] == 0 && board[y - 1][x] == 1)
		{
			q.push({ x, y - 1 });
			visited[y - 1][x] = visited[y][x] + 1;
		}
	}

	return 0;
}