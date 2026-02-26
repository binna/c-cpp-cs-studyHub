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

	vector<vector<int>> edgeList(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		edgeList[s].push_back(e);
		edgeList[e].push_back(s);
	}

	queue<int> q;
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		
		q.push(i);
		visited[i] = true;
		cnt++;

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			for (auto cur : edgeList[node])
			{
				if (visited[cur])
					continue;

				q.push(cur);
				visited[cur] = true;
			}
		}
	}

	cout << cnt;

	return 0;
}