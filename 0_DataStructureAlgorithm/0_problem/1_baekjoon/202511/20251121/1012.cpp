#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
};

int main(void)
{
	int t, m, n, k, result;
	cin >> t;

	for (int repeat = 0; repeat < t; repeat++)
	{
		cin >> m >> n >> k;

		vector<vector<int>> field(n, vector<int>(m, 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		result = 0;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			field[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && field[i][j] == 1)
				{
					queue<Node> q;
					q.push({ j, i });
					visited[i][j] = true;
					result++;

					while (!q.empty())
					{
						auto data = q.front();
						q.pop();

						int x = data.x - 1;
						int y = data.y;
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							if (!visited[y][x] && field[y][x] == 1)
							{
								q.push({ x, y });
								visited[y][x] = true;
							}
						}

						x = data.x + 1;
						y = data.y;
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							if (!visited[y][x] && field[y][x] == 1)
							{
								q.push({ x, y });
								visited[y][x] = true;
							}
						}

						x = data.x;
						y = data.y - 1;
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							if (!visited[y][x] && field[y][x] == 1)
							{
								q.push({ x, y });
								visited[y][x] = true;
							}
						}

						x = data.x;
						y = data.y + 1;
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							if (!visited[y][x] && field[y][x] == 1)
							{
								q.push({ x, y });
								visited[y][x] = true;
							}
						}
					}
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}