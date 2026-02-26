#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

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
			if (temp[j] == '0')
				visited[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int x = node.first;
		int y = node.second;

		if (x + 1 < m && visited[y][x + 1] == 0)
		{
			q.push({ x + 1, y });
			visited[y][x + 1] = visited[y][x] + 1;
		}

		if (x - 1 >= 0 && visited[y][x - 1] == 0)
		{
			q.push({ x - 1, y });
			visited[y][x - 1] = visited[y][x] + 1;
		}

		if (y + 1 < n && visited[y + 1][x] == 0)
		{
			q.push({ x, y + 1 });
			visited[y + 1][x] = visited[y][x] + 1;
		}

		if (y - 1 >= 0 && visited[y - 1][x] == 0)
		{
			q.push({ x, y - 1 });
			visited[y - 1][x] = visited[y][x] + 1;
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
}