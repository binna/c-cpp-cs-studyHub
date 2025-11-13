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

	for (int i = 0; i < n; i++)
	{
		string text;
		cin >> text;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = text[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0]++;

	while (!q.empty())
	{
		auto info = q.front();
		q.pop();

		int x = info.second;
		int y = info.first;

		if (y + 1 < n 
			&& board[y + 1][x] == 1 && visited[y + 1][x] == 0)
		{
			q.push(make_pair(y + 1, x));
			visited[y + 1][x] = visited[y][x] + 1;
		}

		if (y - 1 >= 0 
			&& board[y - 1][x] == 1 && visited[y - 1][x] == 0)
		{
			q.push(make_pair(y - 1, x));
			visited[y - 1][x] = visited[y][x] + 1;
		}

		if (x + 1 < m 
			&& board[y][x + 1] == 1 && visited[y][x + 1] == 0)
		{
			q.push(make_pair(y, x + 1));
			visited[y][x + 1] = visited[y][x] + 1;
		}

		if (x - 1 >= 0
			&& board[y][x - 1] == 1 && visited[y][x - 1] == 0)
		{
			q.push(make_pair(y, x - 1));
			visited[y][x - 1] = visited[y][x] + 1;
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}