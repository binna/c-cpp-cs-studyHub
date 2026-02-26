#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<bool>> visited;
static queue<pair<int, int>> q;
static int m;
static int n;
static int myTotal = 0;

int RipenToday(int nowCnt)
{
	int size = 0;

	while (!q.empty() && nowCnt > 0)
	{
		auto location = q.front();
		q.pop();
		nowCnt--;

		int x = location.first;
		int y = location.second;

		if (x + 1 < m && !visited[y][x + 1])
		{
			q.push({ x + 1, y });
			visited[y][x + 1] = true;
			myTotal++;
			size++;
		}

		if (x - 1 >= 0 && !visited[y][x - 1])
		{
			q.push({ x - 1, y });
			visited[y][x - 1] = true;
			myTotal++;
			size++;
		}

		if (y + 1 < n && !visited[y + 1][x])
		{
			q.push({ x, y + 1 });
			visited[y + 1][x] = true;
			myTotal++;
			size++;
		}

		if (y - 1 >= 0 && !visited[y - 1][x])
		{
			q.push({ x, y - 1 });
			visited[y - 1][x] = true;
			myTotal++;
			size++;
		}
	}
	return size;
}

int main(void)
{
	int result, qSize, total;
	cin >> m >> n;

	total = n * m;
	result = 0;

	visited.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			if (temp == 1)
			{
				visited[i][j] = true;
				myTotal++;
				q.push({ j, i });
				continue;
			}

			if (temp == -1)
			{
				visited[i][j] = true;
				myTotal++;
			}
		}
	}

	qSize = q.size();

	while (!q.empty())
	{
		result++;
		qSize = RipenToday(qSize);
	}

	cout << (myTotal == total ? result - 1 : -1);

	return 0;
}