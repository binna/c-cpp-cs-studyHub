#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, result = 0;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (visited[i])
			continue;
		
		result++;

		queue<int> q;
		q.push(i);
		visited[i] = true;

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			for (auto cur : adjList[node])
			{
				if (visited[cur])
					continue;

				q.push(cur);
				visited[cur] = true;
			}
		}
	}

	cout << result;

	return 0;
}