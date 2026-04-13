#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<vector<bool>> visited(n, vector<bool>(n, true));
	priority_queue<int, vector<int>, greater<int>> result;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < n; j++)
		{
			if (temp[j] == '1')
				visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
				continue;

			queue<pair<int, int>> q;
			q.push({ j, i });
			visited[i][j] = true;

			int cnt = 0;

			while (!q.empty())
			{
				auto node = q.front();
				q.pop();

				cnt++;

				int x = node.first;
				int y = node.second;

				if (x + 1 < n && !visited[y][x + 1])
				{
					q.push({ x + 1, y });
					visited[y][x + 1] = true;
				}

				if (x - 1 >= 0 && !visited[y][x - 1])
				{
					q.push({ x - 1, y });
					visited[y][x - 1] = true;
				}

				if (y + 1 < n && !visited[y + 1][x])
				{
					q.push({ x, y + 1 });
					visited[y + 1][x] = true;
				}

				if (y - 1 >= 0 && !visited[y - 1][x])
				{
					q.push({ x, y - 1 });
					visited[y - 1][x] = true;
				}
			}

			result.push(cnt);
		}
	}

	cout << result.size() << "\n";

	while (!result.empty())
	{
		cout << result.top() << "\n";
		result.pop();
	}

	return 0;
}