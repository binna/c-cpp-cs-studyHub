#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int day;
};

int main(void)
{
	int n, m, totalCnt = 0, day = 0, cnt = 0;
	cin >> n >> m;

	vector<vector<bool>> visited(m, vector<bool>(n, true));
	queue<Node> q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			if (num == 0)
			{
				totalCnt++;
				visited[i][j] = false;
				continue;
			}

			if (num == 1)
			{
				q.push({ j, i, day });
				continue;
			}
		}
	}

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int x = node.x;
		int y = node.y;
		day = node.day;

		if (x + 1 < n && !visited[y][x + 1])
		{
			q.push({ x + 1, y, day + 1 });
			visited[y][x + 1] = true;
			cnt++;
		}

		if (x - 1 >= 0 && !visited[y][x - 1])
		{
			q.push({ x - 1, y, day + 1 });
			visited[y][x - 1] = true;
			cnt++;
		}

		if (y + 1 < m && !visited[y + 1][x])
		{
			q.push({ x, y + 1, day + 1 });
			visited[y + 1][x] = true;
			cnt++;
		}

		if (y - 1 >= 0 && !visited[y - 1][x])
		{
			q.push({ x, y - 1, day + 1 });
			visited[y - 1][x] = true;
			cnt++;
		}
	}


	if (cnt < totalCnt)
		cout << "-1";
	else
		cout << day;

	return 0;
}