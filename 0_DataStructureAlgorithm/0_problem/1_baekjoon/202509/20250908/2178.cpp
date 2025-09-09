#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

static int dx[] = { 1, 0, -1, 0 };
static int dy[] = { 0, 1, 0, -1 };

vector<vector<int>> route;
vector<vector<bool>> visited;

int n, m;

void BFS(int i, int j);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	route.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++)
	{
		route[i].resize(m);
		visited[i].resize(m, false);
	}

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < m; j++)
		{
			route[i][j] = temp[j] - '0';
		}
	}

	BFS(0, 0);

	cout << route[n - 1][m - 1];
	return 0;
}

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		if (visited[node.first][node.second])
			continue;

		visited[node.first][node.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int x = node.first + dx[i];
			int y = node.second + dy[i];

			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;

			if (route[x][y] == 1 && !visited[x][y])
			{
				route[x][y] += route[node.first][node.second];
				q.push(pair<int, int>(x, y));
			}
		}
	}
}