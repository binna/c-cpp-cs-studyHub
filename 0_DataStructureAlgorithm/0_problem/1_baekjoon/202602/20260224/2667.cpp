#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < n; j++)
		{
			if (temp[j] == '0')
				visited[i][j] = true;
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])
				continue;

			q.push({ i, j });
			visited[i][j] = true;
			int cnt = 1;

			while (!q.empty())
			{
				auto temp = q.front();
				q.pop();

				int x = temp.second;
				int y = temp.first;

				if (y + 1 < n && !visited[y + 1][x])
				{
					q.push({ y + 1, x });
					visited[y + 1][x] = true;
					cnt++;
				}

				if (y - 1 >= 0 && !visited[y - 1][x])
				{
					q.push({ y - 1, x });
					visited[y - 1][x] = true;
					cnt++;
				}

				if (x + 1 < n && !visited[y][x + 1])
				{
					q.push({ y, x + 1 });
					visited[y][x + 1] = true;
					cnt++;
				}

				if (x - 1 >= 0 && !visited[y][x - 1])
				{
					q.push({ y, x - 1 });
					visited[y][x - 1] = true;
					cnt++;
				}
			}

			result.push_back(cnt);
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";

	for (auto each : result)
	{
		cout << each << "\n";
	}

	return 0;
}