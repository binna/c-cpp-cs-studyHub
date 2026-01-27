#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<int>> visited(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = temp[j];
		}
	}

	queue<pair<int, int>> q;

	vector<pair<int, int>> directions
		= { make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) };

	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int x = cur.second;
		int y = cur.first;

		if (y == n - 1 && x == m - 1)
		{
			cout << visited[y][x] << endl;
			break;
		}

		for (auto move : directions)
		{
			if (y + move.first >= 0 && y + move.first < n
				&& x + move.second >= 0 && x + move.second < m
				&& board[y + move.first][x + move.second] == '1' 
				&& visited[y + move.first][x + move.second] == 0)
			{
				visited[y + move.first][x + move.second] = visited[y][x] + 1;
				q.push(make_pair(y + move.first, x + move.second));
			}
		}
	}

	return 0;
}